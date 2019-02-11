/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_class.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:50:24 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 16:08:07 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_CLASS_H
# define ENV_CLASS_H
# include "minishell.h"

typedef struct			s_elem_env
{
	char				key[256];
	char				*value;
	struct s_elem_env	*next;
}						t_elem_env;
typedef struct			s_c_env
{
	t_elem_env			*env;
	t_elem_env			*(*create_elem)(char *elem);
	int					nbelem;
	char				**curenv;
	char				**curpath;
	void				(*destructor)(struct s_c_env *this);
	void				(*add_elem)(struct s_c_env *this, char *elem);
	void				(*mod_elem)(t_elem_env *link, char *elem);
	void				(*populate)(struct s_c_env *this, char *envp[]);
	void				(*export)(struct s_c_env *this, char *exec);
	void				(*del_elem)(struct s_c_env *this, char *key);
	void				(*print_env)(struct s_c_env *this);
	void				(*del_curenv)(struct s_c_env *this);
	void				(*del_curpath)(struct s_c_env *this);
}						t_c_env;
t_c_env					*c_env_constructor(char *envp[]);
#endif
