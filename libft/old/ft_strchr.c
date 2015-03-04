/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:50:53 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 15:57:08 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	char		*s2;

	s2 = (char *)s;
	while (*s2)
	{
		if (*s2 == (char)c)
			return (s2);
		s2++;
	}
	if ((char)c == 0)
		return (s2);
	return (NULL);
}
