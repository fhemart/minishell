/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:46:28 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 17:12:03 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_method.h"

static void		c_env_destructor(t_c_env *this)
{
	t_elem_env	*tmp;

	if (!this && !this->env)
		return ;
	this->del_curenv(this);
	this->del_curpath(this);
	while (this->env)
	{
		tmp = this->env->next;
		ft_memdel((void**)&this->env->value);
		ft_memdel((void**)&this->env);
		this->env = tmp;
	}
	ft_memdel((void**)&this);
}

t_c_env			*c_env_constructor(char *envp[])
{
	t_c_env		*newclass;

	if ((newclass = malloc(sizeof(t_c_env))) == NULL)
		exiterror("Malloc error t_c_env constructor");
	ft_bzero(newclass, sizeof(t_c_env));
	newclass->add_elem = add_elem;
	newclass->create_elem = create_elem;
	newclass->mod_elem = mod_elem;
	newclass->export = export;
	newclass->populate = populate;
	newclass->print_env = print_env;
	newclass->del_elem = del_elem;
	newclass->del_curenv = del_curenv;
	newclass->del_curpath = del_curpath;
	newclass->destructor = c_env_destructor;
	newclass->populate(newclass, envp);
	newclass->export(newclass, NULL);
	return (newclass);
}
