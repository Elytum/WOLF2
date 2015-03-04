/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:51:43 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 16:04:27 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		y;
	char		*ret;

	i = 0;
	y = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i])
	{
		while (s1[i] != s2[y] && s1[i])
			i++;
		ret = (char *)&s1[i];
		while (s1[i] == s2[y] && s1[i] && s2[y])
			i++, y++;
		if (!s2[y])
			return (ret);
		else
			y = 0;
	}
	return (NULL);
}
