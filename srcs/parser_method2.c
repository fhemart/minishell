/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_method2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:46:16 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 17:36:45 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser_method2.h"

static void			env_print(t_c_parser *this)
{
	this->c_env->print_env(this->c_env);
}

static void			env_add(t_c_parser *this)
{
	this->c_env->add_elem(this->c_env, this->cmd[1]);
	this->c_env->export(this->c_env, NULL);
}

static void			env_del(t_c_parser *this)
{
	this->c_env->del_elem(this->c_env, this->cmd[1]);
	this->c_env->export(this->c_env, NULL);
}

static void			echo(t_c_parser *this)
{
	int				j;

	j = 1;
	while (this->cmd[j])
	{
		ft_putstr(this->cmd[j++]);
		(this->cmd[j]) ? ft_putchar(' ') : ft_putchar('\n');
	}
}

int					ifbuiltin(t_c_parser *this)
{
	static char		*builtin[5] = {"env", "setenv", "unsetenv", "echo", "cd"};
	static void		(*fn[5])(t_c_parser *this) =
	{&env_print, &env_add, &env_del, &echo, &cd};
	int				i;

	i = 0;
	while (i < 5)
	{
		if (ft_strcmp(this->cmd[0], builtin[i]) == 0)
		{
			(*fn[i])(this);
			return (1);
		}
		i++;
	}
	return (0);
}
