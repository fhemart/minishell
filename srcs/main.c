/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 09:41:37 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 19:59:27 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"

void			exiterror(char *why)
{
	ft_putendl(why);
	exit(-1);
}

int				main(int argc, char **argv, char *envp[])
{
	t_c_parser *c_parser;

	(void)argc;
	(void)argv;
	if (!(c_parser = c_parser_constructor(envp)))
		return (1);
	c_parser->start(c_parser);
	c_parser->destructor(c_parser);
}
