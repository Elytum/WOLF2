/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:37:02 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/07 23:08:09 by pfournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int number;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	number = n / 10;
	if (number > 0)
		ft_putnbr_fd(number, fd);
	number = n % 10;
	ft_putchar_fd((number + '0'), fd);
}
