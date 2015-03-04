/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:04:44 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/12 15:46:01 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_number(char const *str, int i, int *number)
{
	int is_number;

	is_number = 1;
	while (str[i] && is_number)
	{
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			*number += str[i] - '0';
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
				*number *= 10;
		}
		else
			is_number = 0;
		i++;
	}
}

int				ft_atoi(const char *str)
{
	int		i;
	int		is_neg;
	int		number;

	is_neg = 0;
	i = 0;
	number = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
				|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
		is_neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	ft_number(str, i, &number);
	return (is_neg ? -number : number);
}
