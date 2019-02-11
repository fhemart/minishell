/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_method4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 17:03:05 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/30 22:30:32 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void					clearcmd(t_c_parser *this)
{
	int					i;

	i = 0;
	if (!this->cmd)
		return ;
	while (this->cmd[i])
		ft_memdel((void**)&this->cmd[i++]);
	ft_memdel((void**)&this->cmd);
}

static void				get_pathcmd(t_c_parser *this, char *tmp, int i)
{
	tmp = ft_strcpy(tmp, this->c_env->curpath[i]);
	tmp = ft_strcat(tmp, "/");
	tmp = ft_strcat(tmp, this->cmd[0]);
}

static int				is_dir(char *path)
{
	struct stat			statbuf;

	if (stat(path, &statbuf) == 0)
	{
		if (S_ISDIR(statbuf.st_mode))
			return (0);
	}
	return (1);
}

int						ifexec(t_c_parser *this)
{
	int					i;
	char				tmp[4096];

	ft_bzero(tmp, 4096);
	i = 0;
	if (access(this->cmd[0], X_OK) == 0 && is_dir(this->cmd[0]))
	{
		this->exec(this);
		return (1);
	}
	if (!this->c_env->curpath)
		return (0);
	while (this->c_env->curpath[i])
	{
		get_pathcmd(this, tmp, i);
		if (access(tmp, X_OK) == 0 && is_dir(tmp))
		{
			ft_memdel((void**)&this->cmd[0]);
			this->cmd[0] = ft_strdup(tmp);
			this->exec(this);
			return (1);
		}
		i++;
	}
	return (0);
}

void					exec(t_c_parser *this)
{
	int					ret;

	ret = fork();
	if (ret == 0)
	{
		this->c_env->export(this->c_env, this->cmd[0]);
		execve(this->cmd[0], this->cmd, this->c_env->curenv);
	}
	else if (ret > 0)
	{
		wait(NULL);
	}
	else
		exiterror("Fork error");
}
