/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:39:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/21 15:26:51 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<stdarg.h>
# include<unistd.h>
# include <fcntl.h>

int		ft_printf(int fd, const char *str, ...);
void	ft_putchar(char c, int *len, int fd);
void	ft_putnbr(int nb, int *len, int fd);
void	ft_putnbru(unsigned int nb, int *len, int fd);
void	ft_exanum(unsigned int d, char c, int *len, int fd);
void	ft_exanumu(unsigned long d, int *len, int fd);
void	first_cases(const char *str, va_list args, int i, int *len, int fd);
void	second_cases(const char *str, va_list args, int i, int *len, int fd);
void	ft_putstr(char *str, int *len, int fd);

#endif