/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:35:29 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/18 18:35:48 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_nbr(const char *str, int nbr)
{
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - 48);
		str++;
	}
	return (nbr);
}

int	ft_atoi(const char *str)
{
	int	s;
	int	nbr;
	int	i;

	s = 1;
	i = 0;
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
