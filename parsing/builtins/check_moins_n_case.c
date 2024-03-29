/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moins_n_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:17:46 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/10 18:58:55 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_moins_n_case(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' && str[i + 1])
	{
		i++;
		while (str[i] && str[i] == 'n')
			i++;
		if (!str[i])
			return (1);
	}
	return (0);
}
