/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_class.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:19:39 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 16:12:19 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_CLASS_H
# define PARSER_CLASS_H
# include "minishell.h"

typedef struct			s_c_parser
{
	int					run;
	char				*entry;
	char				**cmd;
	char				**env;
	t_c_env				*c_env;
	t_c_lexer			*c_lexer;
	void				(*destructor)(struct s_c_parser *this);
	void				(*clear)(struct s_c_parser *this);
	void				(*start)(struct s_c_parser *this);
	void				(*exec)(struct s_c_parser *this);
	int					(*ifexec)(struct s_c_parser *this);
	int					(*ifbuiltin)(struct s_c_parser *this);
}						t_c_parser;
t_c_parser				*c_parser_constructor(char **env);
#endif
