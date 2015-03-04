/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:01:06 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 16:01:07 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		y;
	size_t		lenght;

	y = 0;
	i = 0;
	lenght = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	if (size > 0)
		while (i < size - 1 && src[y])
			dst[i++] = src[y++];
	if (y > 0)
	{
		dst[i] = 0;
		return (lenght + (i - y));
	}
	return (lenght + i);
}
