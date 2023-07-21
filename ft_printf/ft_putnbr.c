/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:28:21 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/21 15:16:04 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putnbr(int nb, int *len, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*len += 11;
	}
	else if (nb < 0)
	{
		ft_putchar('-', len, fd);
		ft_putnbr(nb *(-1), len, fd);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10, len, fd);
		ft_putnbr(nb % 10, len, fd);
	}
	else
		ft_putchar(nb + '0', len, fd);
}
