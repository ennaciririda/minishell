/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exanum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:05:28 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/21 15:26:39 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_exanum(unsigned int d, char c, int *len, int fd)
{
	char	*x;

	if (c == 'x')
		x = "0123456789abcdef";
	if (c == 'X')
		x = "0123456789ABCDEF";
	if (d < 16)
		ft_putchar(x[d], len, fd);
	else
	{
		ft_exanum(d / 16, c, len, fd);
		ft_exanum(d % 16, c, len, fd);
	}
}

void	ft_exanumu(unsigned long d, int *len, int fd)
{
	char	*x;

	x = "0123456789abcdef";
	if (d < 16)
		ft_putchar(x[d], len, fd);
	else
	{
		ft_exanumu(d / 16, len, fd);
		ft_exanumu(d % 16, len, fd);
	}
}
