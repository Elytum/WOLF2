/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:24:39 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 15:48:34 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	t_uchar		*tmp_dst;
	t_uchar		*tmp_src;

	tmp_dst = (t_uchar*)dst;
	tmp_src = (t_uchar*)src;
	i = 0;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if (tmp_src[i] == (t_uchar)c)
			return ((void *)&tmp_dst[i + 1]);
		i++;
	}
	return (NULL);
}
