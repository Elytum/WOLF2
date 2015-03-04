/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:50:38 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 15:59:00 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s1)
{
	size_t		i;
	char		*s2;

	i = ft_strlen(s1);
	if ((s2 = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	return (ft_strcpy(s2, s1));
}
