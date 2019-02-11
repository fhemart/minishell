/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_method3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:41:54 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 20:25:46 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_elem_env		*create_elem(char *elem)
{
	size_t		lenght;
	t_elem_env	*newelem;

	lenght = 0;
	if (!elem)
		exiterror("Error no env to set");
	if (!(newelem = malloc(sizeof(t_elem_env))))
		exiterror("Malloc error t_elem_env in add_elem.c");
	ft_bzero(newelem, sizeof(t_elem_env));
	while (elem[lenght] != '=' && elem[lenght])
	{
		newelem->key[lenght] = elem[lenght];
		lenght++;
	}
	if (!(newelem->value = ft_strdup(elem + ++lenght)))
		exiterror("Malloc error strdup in add_elem.c");
	return (newelem);
}

void			mod_elem(t_elem_env *link, char *elem)
{
	ft_memdel((void**)&link->value);
	while (*elem != '=' && *elem)
		elem++;
	if (!(link->value = ft_strdup(++elem)))
		exiterror("Malloc error strdup in mod_elem");
}

static int		check_elem(char *elem)
{
	if (!elem || !ft_strchr(elem, '='))
	{
		ft_putendl("No key to set");
		return (0);
	}
	return (1);
}

static void		add_one(t_elem_env *newelem, t_c_env *this, char *elem)
{
	while (newelem->next)
	{
		if (ft_strncmp(newelem->key, elem, ft_strlen(newelem->key)) == 0 &&
		elem[ft_strlen(newelem->key)] == '=')
		{
			this->mod_elem(newelem, elem);
			return ;
		}
		newelem = newelem->next;
	}
	if (ft_strncmp(newelem->key, elem, ft_strlen(newelem->key)) == 0 &&
		elem[ft_strlen(newelem->key)] == '=')
	{
		this->mod_elem(newelem, elem);
		return ;
	}
	newelem->next = this->create_elem(elem);
	this->nbelem++;
}

void			add_elem(t_c_env *this, char *elem)
{
	t_elem_env	*newelem;

	newelem = this->env;
	if (!check_elem(elem))
		return ;
	if (this->env)
	{
		add_one(newelem, this, elem);
		return ;
	}
	else
		this->env = this->create_elem(elem);
	this->nbelem++;
}
