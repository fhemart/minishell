/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_method3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 17:00:55 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/30 20:12:04 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*cd_get_value(t_c_parser *this, char *key)
{
	t_elem_env	*curs;

	curs = this->c_env->env;
	while (curs)
	{
		if (ft_strcmp(key, curs->key) == 0)
			return (curs->value);
		curs = curs->next;
	}
	return ("/");
}

static int		is_directory(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
	{
		ft_putstr(path);
		ft_putendl(" : directory not found.");
		return (0);
	}
	if (!S_ISDIR(statbuf.st_mode))
	{
		ft_putstr(path);
		ft_putendl(" : is not a directory.");
		return (0);
	}
	if (access(path, R_OK) != 0)
	{
		ft_putstr(path);
		ft_putendl(" : no right to open this directory.");
		return (0);
	}
	return (1);
}

static void		doit(t_c_parser *this, char *path, char *formatkey,
	char *formatkeyold)
{
	chdir(path);
	getcwd(formatkey + 4, 4092);
	this->c_env->add_elem(this->c_env, formatkey);
	this->c_env->add_elem(this->c_env, formatkeyold);
}

void			cd(t_c_parser *this)
{
	char		formatkey[4096];
	char		formatkeyold[4096];

	ft_bzero(formatkey, 4096);
	ft_bzero(formatkeyold, 4096);
	ft_strcpy(formatkeyold, "OLDPWD=");
	ft_strcat(formatkeyold, cd_get_value(this, "PWD"));
	ft_strcpy(formatkey, "PWD=");
	if (!this->cmd[1] && is_directory(cd_get_value(this, "HOME")))
		doit(this, cd_get_value(this, "HOME"), formatkey, formatkeyold);
	else if (ft_strcmp(this->cmd[1], "-") == 0 &&
	is_directory(cd_get_value(this, "OLDPWD")))
		doit(this, cd_get_value(this, "OLDPWD"), formatkey, formatkeyold);
	else if (is_directory(this->cmd[1]))
		doit(this, this->cmd[1], formatkey, formatkeyold);
}
