/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by achazal           #+#    #+#             */
/*   Updated: 2015/02/20 12:52:13 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static char			*ft_strcdup(const char *str, char c)
{
	register char	*strnew;
	register char	*ptr;

	if (!(strnew = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
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

	if (!(buff = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while (!ft_strchr(*memory, '\n'))
	{
		ft_strclr(buff);
		if ((re = read(fd, buff, BUFF_SIZE)) == -1)
			return (re);
		if (re == 0)
		{
			free(buff);
			return (0);
		}
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

	if (!*line || !**line)
		return (-1);
	if (!*memory)
		if (!(*memory = (char **)ft_memalloc(sizeof(char *) * 1025)))
			return (-1);
	if ((value = ft_get_single_line(fd, &((*memory)[fd]))) == -1)
		return (-1);
	if (!(*memory)[fd] && value == 0)
	{
		if (!(**line = ft_strdup("")))
			return (-1);
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
	if (!(*line = ft_strcdup((memory[fd]), '\n')) ||
		!(tmp = ft_strdup(ptr + 1)))
		return (-1);
	free((memory[fd]));
	(memory[fd]) = tmp;
	return (1);
}
