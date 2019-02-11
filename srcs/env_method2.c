/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_method2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:39:45 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 17:15:03 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		del_first(t_c_env *this, t_elem_env *curs)
{
	this->env = curs->next;
	ft_memdel((void**)&curs->value);
	ft_memdel((void**)&curs);
	this->nbelem--;
}

static void		del_one(t_c_env *this, t_elem_env *curs, t_elem_env *prev)
{
	prev->next = curs->next;
	ft_memdel((void**)&curs->value);
	ft_memdel((void**)&curs);
	this->nbelem--;
}

void			del_elem(t_c_env *this, char *key)
{
	t_elem_env	*curs;
	t_elem_env	*prev;

	curs = this->env;
	prev = NULL;
	if (!key)
		return ;
	if (curs && ft_strcmp(key, curs->key) == 0)
	{
		del_first(this, curs);
		return ;
	}
	while (curs)
	{
		if (ft_strcmp(key, curs->key) == 0)
		{
			del_one(this, curs, prev);
			break ;
		}
		prev = curs;
		curs = curs->next;
	}
}

void			print_env(t_c_env *this)
{
	t_elem_env	*curs;

	curs = this->env;
	while (curs != NULL)
	{
		ft_putstr(curs->key);
		ft_putchar('=');
		ft_putendl(curs->value);
		curs = curs->next;
	}
}
