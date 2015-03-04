/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:00:32 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/07 11:47:25 by pfournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int number;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	number = n / 10;
	if (number > 0)
		ft_putnbr(number);
	number = n % 10;
	ft_putchar((number + '0'));
}
