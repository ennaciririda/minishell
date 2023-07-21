/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:00:09 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/21 15:15:41 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putnbru(unsigned int nb, int *len, int fd)
{
	if (nb >= 10)
	{
		ft_putnbru(nb / 10, len, fd);
		ft_putnbru(nb % 10, len, fd);
	}
	else
		ft_putchar(nb + '0', len, fd);
}
