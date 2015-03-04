/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:39:47 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 15:48:32 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	t_uchar		*tmp_s;

	tmp_s = (t_uchar*)s;
	i = 0;
	while (i < n)
	{
		if ((t_uchar)c == tmp_s[i])
			return ((void *)&tmp_s[i]);
		i++;
	}
	return (NULL);
}
