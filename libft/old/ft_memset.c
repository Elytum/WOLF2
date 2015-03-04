/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:35:40 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/13 10:03:39 by pfournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	t_uchar			*s;

	i = 0;
	s = (t_uchar *)b;
	while (len)
	{
		s[i] = (t_uchar)c;
		len--;
		i++;
	}
	return (b);
}
