/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:00:09 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/26 18:47:39 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_putnbru(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_putnbru(nb / 10, len);
		ft_putnbru(nb % 10, len);
	}
	else
		ft_putchar(nb + '0', len);
}
