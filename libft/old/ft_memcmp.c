/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:40:21 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 15:50:13 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	t_uchar		*tmp_s1;
	t_uchar		*tmp_s2;

	tmp_s1 = (t_uchar*)s1;
	tmp_s2 = (t_uchar*)s2;
	i = 0;
	while (i < n && tmp_s1[i] == tmp_s2[i])
		i++;
	if (i == n)
		return (0);
	else
		return ((int)(tmp_s1[i] - tmp_s2[i]));
	return (-1);
}
