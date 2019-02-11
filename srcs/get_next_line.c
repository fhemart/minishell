/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:31:44 by fhemart           #+#    #+#             */
/*   Updated: 2018/04/29 20:38:15 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static int				checkend(t_gnl *curs, char **line, char **buff)
{
	if (ft_strlen(curs->last) > 1)
	{
		*line = ft_strdup(curs->last);
		free(curs->last);
		curs->last = NULL;
		free(*buff);
		return (1);
	}
	if (!curs->last)
		free(curs->last);
	free(*buff);
	return (0);
}

static int				readthis(const int fd, char **line,
							char **buff, t_gnl *curs)
{
	int					len;
	char				*ptr;
	char				*tmp;
	char				*buff2;

	len = 0;
	while ((ptr = ft_strchr(curs->last, '\n')) == NULL)
	{
		buff2 = ft_strnew(BUFF_SIZE);
		ft_strclr(*buff);
		if ((len = read(fd, buff2, BUFF_SIZE)) == 0)
			return (checkend(curs, &(*line), &buff2));
		if (len == -1 && ft_strlen(buff2) < 1)
			return (-1);
		tmp = ft_strdup(curs->last);
		free(curs->last);
		curs->last = ft_strjoin(tmp, buff2);
		free(tmp);
		ft_strdel(&buff2);
	}
	return (2);
}

t_gnl					*creatlist(int fd)
{
	t_gnl				*new;

	if (!(new = malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->ret = 0;
	new->len = 0;
	new->last = NULL;
	new->next = NULL;
	return (new);
}

static t_gnl			*initlst(int fd, t_gnl **gnl)
{
	t_gnl				*curs;

	curs = *gnl;
	if (!*gnl)
		return (*gnl = creatlist(fd));
	while (curs->next && fd != curs->fd)
		curs = curs->next;
	if (fd != curs->fd)
	{
		curs->next = creatlist(fd);
		curs = curs->next;
	}
	return (curs);
}

int						get_next_line(const int fd, char **line)
{
	static t_gnl		*gnl;
	t_gnl				*curs;
	char				*buff;
	char				*ptr;

	if (!(curs = initlst(fd, &gnl)))
		return (-1);
	if (!line || fd < 0 || !(buff = ft_strnew(BUFF_SIZE)) ||
			(!curs->last && (curs->len = read(fd, buff, BUFF_SIZE)) == -1)
				|| (!curs->last && !(curs->last = ft_strdup(buff))))
		return (-1);
	if ((ptr = ft_strchr(curs->last, '\n')) == NULL)
	{
		if ((curs->ret = readthis(fd, &(*line), &buff, curs)) != 2)
			return (curs->ret);
		ptr = ft_strchr(curs->last, '\n');
	}
	*line = ft_strsub(curs->last, 0, ft_strlen(curs->last) - ft_strlen(ptr));
	ft_strdel(&buff);
	buff = ft_strdup(ptr + 1);
	ft_strdel(&curs->last);
	curs->last = (ptr) ? NULL : ft_strdup(buff);
	ft_strdel(&buff);
	return (1);
}
