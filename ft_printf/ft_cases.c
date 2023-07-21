/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:14:24 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/21 15:27:16 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	first_cases(const char *str, va_list args, int i, int *len, int fd)
{
	if (str[i + 1] == 'c')
	{
		ft_putchar(va_arg(args, int), len, fd);
		i++;
	}
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
	{
		ft_putnbr(va_arg(args, int), len, fd);
		i++;
	}
	else if (str[i + 1] == 'u')
	{
		ft_putnbru(va_arg(args, unsigned int), len, fd);
		i++;
	}
	else if (str[i + 1] == 's')
	{
		ft_putstr(va_arg(args, char *), len, fd);
		i++;
	}
}

void	second_cases(const char *str, va_list args, int i, int *len, int fd)
{
	if (str[i + 1] == 'x' || str[i + 1] == 'X')
	{
		if (str[i + 1] == 'x')
			ft_exanum(va_arg(args, unsigned int), 'x', len, fd);
		else if (str[i + 1] == 'X')
			ft_exanum(va_arg(args, unsigned int), 'X', len, fd);
		i++;
	}
	else if (str[i + 1] == 'p')
	{
		ft_putstr("0x", len, fd);
		ft_exanumu(va_arg(args, unsigned long), len, fd);
		i++;
	}
	else if (str[i + 1] == '%')
	{
		ft_putchar('%', len, fd);
		i++;
	}
}
