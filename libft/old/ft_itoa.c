/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 09:15:55 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 15:47:51 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_insert_nb(char *s, size_t id, int n)
{
	if (n >= 10 || n <= -10)
	{
		if (n > 0)
			s[id] = (n % 10) + '0';
		else
			s[id] = -(n % 10) + '0';
		ft_insert_nb(s, id - 1, n / 10);
	}
	else
	{
		if (n > 0)
			s[id] = n + '0';
		else
			s[id] = -n + '0';
	}
}

char			*ft_itoa(int n)
{
	char		*ret;
	size_t		len_nb;
	int		tmp;

	tmp = n;
	len_nb = 1;
	while (tmp /= 10)
		len_nb++;
	ret = ft_strnew(len_nb + (n < 0 ? 2 : 1));
	if (n < 0)
	{
		ret[0] = '-';
		ft_insert_nb(&ret[1], len_nb - 1, n);
	}
	else
		ft_insert_nb(ret, len_nb - 1, n);
	if (n < 0)
		ret[len_nb + 1] = '\0';
	else
		ret[len_nb] = '\0';
	return (ret);
}
