/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:14:35 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 19:48:59 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "libft.h"
# include "env_class.h"
# include "lexer_class.h"
# include "parser_class.h"

void			exiterror(char *why);
#endif
