/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:46:42 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 16:07:17 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_s(char const *s, char c)
{
	int		ret;

	ret = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		ret++;
	}
	return (ret);
}

static size_t		ft_len(char const *s, unsigned int start, char stop)
{
	size_t		i;

	i = 0;
	while (s[start] != stop && s[start])
	{
		start++;
		i++;
	}
	return (i);
}

char				**ft_strsplit(char const *s, char c)
{
	char				**ret;
	unsigned int		i;
	int					y;

	i = 0;
	y = 0;
	ret = NULL;
	if ((ret = (char **)malloc(sizeof(char *) * (ft_s(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			ret[y] = ft_strsub(s, i, ft_len(s, i, c));
			y++;
			i = i + ft_len(s, i, c);
		}
	}
	ret[y] = NULL;
	return (ret);
}
