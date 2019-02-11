/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:52:42 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/30 20:32:35 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		exec_state(t_c_parser *this)
{
	struct stat			statbuf;

	if (this->cmd && this->cmd[0] && !this->ifbuiltin(this))
	{
		if (!this->ifexec(this))
		{
			if (stat(this->cmd[0], &statbuf) != 0)
			{
				ft_putstr("Command : ");
				ft_putstr(this->cmd[0]);
				ft_putendl(" : not found");
			}
			else
			{
				ft_putstr("Command : ");
				ft_putstr(this->cmd[0]);
				ft_putendl(" : is a directory.");
			}
		}
	}
}

static void		blck(t_c_parser *this, size_t nb)
{
	ft_strncpy(this->c_lexer->line, this->entry, nb - 1);
	this->c_lexer->check_quote(this->c_lexer, NULL);
	this->c_lexer->get_args(this->c_lexer);
	this->cmd = ft_strsplit(this->c_lexer->args, 7);
	this->c_lexer->clear(this->c_lexer);
}

void			start(t_c_parser *this)
{
	size_t		nb;

	while (this->run)
	{
		ft_putstr("$> ");
		nb = read(0, this->entry, 4096);
		this->entry[nb] = '\0';
		if (ft_strcmp(this->entry, "exit\n") == 0 || nb == 0)
			break ;
		if (ft_strchr(this->entry, '\n'))
			blck(this, nb);
		else
		{
			ft_putendl(nb > 4095 ? "Error arguments list to long" : "");
			continue ;
		}
		ft_strclr(this->entry);
		exec_state(this);
		this->clear(this);
	}
}
