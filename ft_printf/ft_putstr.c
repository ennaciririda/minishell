/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:31:28 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/26 18:45:04 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_putstr(char *str, int *len)
{
	int	j;

	j = 0;
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[j])
	{
		ft_putchar(str[j], len);
		j++;
	}
}
