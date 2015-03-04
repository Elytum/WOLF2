/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cretaill <cretaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by cretaill          #+#    #+#             */
/*   Updated: 2015/01/03 01:45:39 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char			*ft_strcdup(const char *str, char c)
{
	register char	*strnew;
	register char	*ptr;

	strnew = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	ptr = strnew;
	while (*str && *str != c)
		*ptr++ = *str++;
	*ptr = '\0';
	return (strnew);
}

static int			ft_get_single_line(int fd, char **memory)
{
	register char	*tmp;
	register char	*buff;
	register int	re;

	buff = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	while (!ft_strchr(*memory, '\n'))
	{
		ft_strclr(buff);
		if ((re = read(fd, buff, BUFF_SIZE)) == -1)
			return (re);
		if (re == 0)
			return (0);
		tmp = ft_strjoin(*memory, buff);
		free(*memory);
		*memory = tmp;
	}
	free(buff);
	return (1);
}

static int			ft_init(char ***memory, int fd, char ***line)
{
	register int	value;

	if (!*line)
		return (-1);
	if (!*memory)
		*memory = (char **)malloc(sizeof(char *) * 1025);
	if ((value = ft_get_single_line(fd, &((*memory)[fd]))) == -1)
		return (-1);
	if (!(*(*memory)[fd]) && value == 0)
	{
		**line = ft_strdup("");
		return (0);
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char		**memory = NULL;
	register char	*tmp;
	register char	*ptr;
	register int	value;

	if ((value = ft_init(&memory, fd, &line)) <= 0)
		return (value);
	ptr = ft_strchr((memory[fd]), '\n');
	if (ptr + 1 == '\0')
		*ptr = '\0';
	if (!ptr || ptr + 1 == '\0')
	{
		*line = (memory[fd]);
		(memory[fd]) = NULL;
		return ((*(*line)) ? 1 : 0);
	}
	*line = ft_strcdup((memory[fd]), '\n');
	tmp = ft_strdup(ptr + 1);
	free((memory[fd]));
	(memory[fd]) = tmp;
	return (1);
}
