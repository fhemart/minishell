/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_method.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:58:14 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 16:13:11 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_METHOD_H
# define PARSER_METHOD_H

void				clearcmd(t_c_parser *this);
void				start(t_c_parser *this);
void				exec(t_c_parser *this);
int					ifexec(t_c_parser *this);
int					ifbuiltin(t_c_parser *this);
#endif
