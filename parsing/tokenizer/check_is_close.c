/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:12:22 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/15 22:33:32 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_is_close(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] && str[i] == c)
		return (0);
	else
	{
		ft_printf(2, "Error : quote is not close\n");
		g_gv.exit_status = 1;
		g_gv.check_close = 1;
		return (1);
	}
	return (0);
}
