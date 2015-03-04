/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 08:12:45 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 16:04:36 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ret;
	size_t		y;
	size_t		i;

	y = 0;
	i = ft_strlen(s);
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (!i || len > i || start > i)
		return (NULL);
	while (y < len)
	{
		ret[y] = s[start];
		y++;
		start++;
	}
	ret[y] = '\0';
	return (ret);
}
