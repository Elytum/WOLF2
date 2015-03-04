/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 08:12:45 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 16:01:50 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	char		*ret;
	int			y;

	y = 0;
	i = ft_strlen(s);
	ret = ft_strnew(i + 1);
	while (s[y])
	{
		ret[y] = (*f)(y, s[y]);
		y++;
	}
	ret[y] = '\0';
	return (ret);
}
