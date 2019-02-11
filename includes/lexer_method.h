/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_method.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:43:31 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 16:11:16 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_METHOD_H
# define LEXER_METHOD_H

void								clear(t_c_lexer *this);
void								get_cmd(t_c_lexer *this);
void								check_quote(t_c_lexer *this, char *ptr);
void								get_args(t_c_lexer *this);
#endif
