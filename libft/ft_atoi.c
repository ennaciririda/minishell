/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:35:29 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/21 17:15:55 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static unsigned long long	count_nbr(const char *str, unsigned long long nbr)
{
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - 48);
		str++;
	}
	return (nbr);
}

unsigned long long	ft_atoi(const char *str)
{
	int	s;
	unsigned long long	nbr;

	s = 1;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			s = -1;
		}
		str++;
	}
	nbr = count_nbr(str, nbr);
	return (nbr * s);
}
