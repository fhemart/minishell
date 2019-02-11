/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_method.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:40:53 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 20:55:13 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void								clear(t_c_lexer *this)
{
	ft_strclr(this->line);
	ft_strclr(this->args);
}

void								check_quote(t_c_lexer *this, char *ptr)
{
	char							*ptrstart;
	char							*ptrend;
	char							*tmp;

	tmp = NULL;
	ptrend = NULL;
	ptrstart = ft_strchr(ptr ? ptr : this->line, '"');
	if (ptrstart && !(ptrend = ft_strchr(ptrstart + 1, '"')))
	{
		ft_putendl("Terminate quote not found");
		while (get_next_line(0, &tmp))
		{
			if (ft_strlcat(this->line, tmp, 4096) > 4096 ||
			(ptrend = ft_strchr(tmp, '"')))
				break ;
			ft_memdel((void**)&tmp);
		}
	}
	if (ptrend)
	{
		this->check_quote(this, ptrend + 1);
		if (tmp)
			ft_memdel((void**)&tmp);
	}
}

void								get_args(t_c_lexer *this)
{
	int								i;
	int								j;
	int								quote;

	i = 0;
	j = 0;
	quote = 0;
	while (this->line[i])
	{
		while (this->line[i] == ' ' || this->line[i] == '\t')
			i++;
		while (((this->line[i] != ' ' && this->line[i] != '\t')
					|| quote % 2) && this->line[i] != '\0')
		{
			if (this->line[i] == '"')
				quote++;
			else
				this->args[j++] = this->line[i];
			i++;
		}
		if (this->line[i - 1] != ' ' && this->line[i - 1] != '\t')
			this->args[j++] = 7;
	}
}
