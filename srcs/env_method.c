/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_method.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:43:39 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 17:13:57 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			populate(t_c_env *this, char *envp[])
{
	int			i;

	i = 0;
	while (envp[i])
	{
		this->add_elem(this, envp[i++]);
	}
}

void			del_curenv(t_c_env *this)
{
	int			i;

	i = 0;
	if (this->curenv)
	{
		while (this->curenv[i])
			ft_memdel((void**)&this->curenv[i++]);
		ft_memdel((void**)&this->curenv);
	}
}

void			del_curpath(t_c_env *this)
{
	int			i;

	i = 0;
	if (this->curpath)
	{
		while (this->curpath[i])
			ft_memdel((void**)&this->curpath[i++]);
		ft_memdel((void**)&this->curpath);
	}
}

static void		whrite_env(t_c_env *this, char *exec, t_elem_env *curs, int i)
{
	if (!(this->curenv[i] = malloc(sizeof(char) * (ft_strlen(curs->key) +
		1 + ft_strlen(curs->value) + 1))))
		exiterror("Malloc error in export");
	this->curenv[i] = ft_strcpy(this->curenv[i], curs->key);
	this->curenv[i] = ft_strcat(this->curenv[i], "=");
	if (curs->key[0] == '_' && exec)
		this->curenv[i] = ft_strcat(this->curenv[i], exec);
	else
		this->curenv[i] = ft_strcat(this->curenv[i], curs->value);
	if (ft_strcmp(curs->key, "PATH") == 0)
	{
		if (this->curpath)
			ft_memdel((void**)&this->curpath);
		this->curpath = ft_strsplit(curs->value, ':');
	}
}

void			export(t_c_env *this, char *exec)
{
	int			i;
	t_elem_env	*curs;

	curs = this->env;
	i = -1;
	this->del_curenv(this);
	this->del_curpath(this);
	if (!(this->curenv = malloc(sizeof(char *) * (this->nbelem + 1))))
		exiterror("Malloc error in export");
	while (curs && ++i > -1)
	{
		whrite_env(this, exec, curs, i);
		curs = curs->next;
	}
	this->curenv[i + 1] = NULL;
}
