/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exanum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:05:28 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/26 18:44:45 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exanum(unsigned int d, char c, int *len)
{
	char	*x;

	if (c == 'x')
		x = "0123456789abcdef";
	if (c == 'X')
		x = "0123456789ABCDEF";
	if (d < 16)
		ft_putchar(x[d], len);
	else
	{
		ft_exanum(d / 16, c, len);
		ft_exanum(d % 16, c, len);
	}
}

void	ft_exanumu(unsigned long d, int *len)
{
	char	*x;

	x = "0123456789abcdef";
	if (d < 16)
		ft_putchar(x[d], len);
	else
	{
		ft_exanumu(d / 16, len);
		ft_exanumu(d % 16, len);
	}
}
