/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:03:02 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 16:03:44 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		y;
	char		*ret;

	i = 0;
	y = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		while (s1[i] != s2[y] && s1[i])
			i++;
		ret = (char *)&s1[i];
		while (s1[i] == s2[y] && s1[i] && s2[y] && i < n)
			i++, y++;
		if (!s2[y])
			return (ret);
		else
			y = 0;
	}
	return (NULL);
}
