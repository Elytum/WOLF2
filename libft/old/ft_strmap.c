/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:58:00 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/13 10:04:11 by pfournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;
	int		y;

	y = 0;
	i = ft_strlen(s);
	ret = ft_strnew(i + 1);
	while (s[y])
	{
		ret[y] = (*f)(s[y]);
		y++;
	}
	ret[y] = '\0';
	return (ret);
}
