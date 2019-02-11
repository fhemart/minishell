/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:27:35 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/28 01:46:29 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser_method.h"

static void				c_parser_destructor(t_c_parser *this)
{
	int							i;

	i = 0;
	if (!this)
		return ;
	this->c_env->destructor(this->c_env);
	this->c_lexer->destructor(this->c_lexer);
	while (this->cmd && this->cmd[i])
		ft_memdel((void**)&this->cmd[i]);
	ft_memdel((void**)&this->cmd);
	if (this->entry)
		ft_memdel((void**)&this->entry);
	ft_memdel((void**)&this);
}

t_c_parser				*c_parser_constructor(char **env)
{
	t_c_parser			*newclass;

	if (!(newclass = malloc(sizeof(t_c_parser))))
		exiterror("Malloc error t_c_parser constructor");
	ft_bzero(newclass, sizeof(t_c_parser));
	newclass->run = 1;
	newclass->env = env;
	if (!(newclass->entry = ft_strnew(4096)))
		exiterror("Malloc error t_c_parser entry constructor");
	newclass->c_env = c_env_constructor(env);
	newclass->c_lexer = c_lexer_constructor();
	newclass->destructor = c_parser_destructor;
	newclass->clear = clearcmd;
	newclass->start = start;
	newclass->exec = exec;
	newclass->ifexec = ifexec;
	newclass->ifbuiltin = ifbuiltin;
	return (newclass);
}
