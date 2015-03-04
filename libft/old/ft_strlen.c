/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:50:11 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 16:01:16 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(const char *s)
{
	int		i;
	size_t	lenght;

	lenght = 0;
	i = 0;
	while (s[i])
	{
		lenght++;
		i++;
	}
	return (lenght);
}
