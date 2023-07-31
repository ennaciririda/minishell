/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:39:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/26 18:44:18 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_printf(int fd, const char *str, ...);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_putnbru(unsigned int nb, int *len);
void	ft_exanum(unsigned int d, char c, int *len);
void	ft_exanumu(unsigned long d, int *len);
void	first_cases(const char *str, va_list args, int i, int *len);
void	second_cases(const char *str, va_list args, int i, int *len);
void	ft_putstr(char *str, int *len);

#endif