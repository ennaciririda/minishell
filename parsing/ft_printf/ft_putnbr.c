/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:28:21 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/08 23:00:21 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		write(g_gv.print_fd, "-2147483648", 11);
		*len += 11;
	}
	else if (nb < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(nb *(-1), len);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	else
		ft_putchar(nb + '0', len);
}
