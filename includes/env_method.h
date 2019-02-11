/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_method.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 09:17:43 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 16:09:18 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_METHOD_H
# define ENV_METHOD_H

t_elem_env		*create_elem(char *elem);
void			del_elem(t_c_env *this, char *key);
void			add_elem(t_c_env *this, char *elem);
void			mod_elem(t_elem_env *link, char *elem);
void			export(t_c_env *this, char *exec);
void			populate(t_c_env *this, char *envp[]);
void			print_env(t_c_env *this);
void			del_curenv(t_c_env *this);
void			del_curpath(t_c_env *this);

#endif
