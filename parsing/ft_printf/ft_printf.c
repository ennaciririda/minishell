/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:36:23 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/26 18:53:13 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	f_cases(const char *str, va_list args, int i, int *len)
{
	while (str[i])
	{
		if (str[i] == '%')
		{
			if ((str[i + 1] == 'd' || str[i + 1] == 'i') || str[i + 1] == 'c'
				|| str[i + 1] == 's' || str[i + 1] == 'u')
			{
				first_cases(str, args, i, len);
				i++;
			}
			else if (str[i + 1] == 'x' || str[i + 1] == 'X'
				|| str[i + 1] == 'p' || str[i + 1] == '%')
			{
				second_cases(str, args, i, len);
				i++;
			}
		}
		else
			ft_putchar(str[i], len);
		i++;
	}
	return (*len);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	g_gv.print_fd = fd;
	len = 0;
	i = 0;
	va_start(args, str);
	len = f_cases(str, args, i, &len);
	va_end(args);
	return (len);
}
