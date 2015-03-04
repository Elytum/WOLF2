/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 16:09:32 by pfournet          #+#    #+#             */
/*   Updated: 2014/12/02 12:50:23 by pfournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	size_t		i;
	char		*ret;

	i = ft_strlen(s1) + n;
	if ((ret = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strncat(ret, s2, n);
	return (ret);
}
