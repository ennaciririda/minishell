/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:31:28 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/21 15:15:01 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len, int fd)
{
	int	j;

	j = 0;
	if (!str)
	{
		ft_putstr("(null)", len, fd);
		return ;
	}
	while (str[j])
	{
		ft_putchar(str[j], len, fd);
		j++;
	}
}
