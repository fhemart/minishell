/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_class.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:37:04 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 16:10:34 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_CLASS_H
# define LEXER_CLASS_H
# include "get_next_line.h"
# include "minishell.h"

typedef struct			s_c_lexer
{
	char				line[4096];
	char				args[4096];
	void				(*destructor)(struct s_c_lexer *this);
	void				(*check_quote)(struct s_c_lexer *this, char *ptr);
	void				(*get_args)(struct s_c_lexer *this);
	void				(*clear)(struct s_c_lexer *this);
}						t_c_lexer;
t_c_lexer				*c_lexer_constructor();
#endif
