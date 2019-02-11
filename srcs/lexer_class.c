/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_class.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 01:12:46 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 16:09:58 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer_method.h"

static void				c_lexer_destructor(t_c_lexer *this)
{
	if (!this)
		return ;
	ft_memdel((void**)&this);
}

t_c_lexer				*c_lexer_constructor(void)
{
	t_c_lexer			*newclass;

	if (!(newclass = malloc(sizeof(t_c_lexer))))
		exiterror("Malloc error t_c_lexer constructor");
	ft_bzero(newclass, sizeof(t_c_lexer));
	newclass->get_args = get_args;
	newclass->check_quote = check_quote;
	newclass->clear = clear;
	newclass->destructor = c_lexer_destructor;
	return (newclass);
}
