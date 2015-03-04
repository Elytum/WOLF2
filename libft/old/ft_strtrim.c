/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:59:41 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/13 10:04:39 by pfournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_end(char const *s, size_t len)
{
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	return (len + 1);
}

static size_t		ft_begin(char const *s)
{
	size_t		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

char				*ft_strtrim(char const *s)
{
	char		*ret;
	size_t		a;
	size_t		b;
	size_t		len;

	len = ft_strlen(s);
	if (!len)
		return (ft_strnew(1));
	a = ft_end(s, len - 1);
	b = ft_begin(s);
	if (b == len)
		return (ft_strnew(1));
	len = len - ((len - a) + (len - (len - b)));
	ret = ft_strsub(s, b, len);
	return (ret);
}
