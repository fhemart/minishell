/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:31:49 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/12 23:25:59 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024
# include <unistd.h>
# include "libft.h"

typedef struct		s_gnl
{
	int				fd;
	char			*last;
	int				len;
	int				ret;
	struct s_gnl	*next;
}					t_gnl;
t_gnl				*creatlist(int fd);
int					get_next_line(const int fd, char **line);
#endif
