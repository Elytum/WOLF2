/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:51:07 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 16:04:01 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	char		*s2;
	char		*ret;
	int			i;

	ret = NULL;
	s2 = (char *)s;
	i = 0;
	while (s2[i])
	{
		if (s2[i] == (char)c)
			ret = &s2[i];
		i++;
	}
	if ((char)c == 0)
		return (&s2[i]);
	else if (ret == NULL)
		return (ret);
	else
		return (ret);
	return (NULL);
}
