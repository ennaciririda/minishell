/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:15:09 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/17 21:15:34 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_arg_is_int(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	g_gv.for_ex_built = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
		count++;
	}
	if (count > 19)
		g_gv.for_ex_built = -1337;
	return (1);
}

void	exit_status(t_finallist **lastlist)
{
	t_finallist	*tmp;
	char		**cmd;
	int			i;

	i = 0;
	tmp = *lastlist;
	while (tmp)
	{
		cmd = tmp->cmd;
		i = 0;
		while (cmd[i])
		{
			while (ft_strstr(cmd[i], "$?"))
				cmd[i] = rep_str(cmd[i], ft_strdup("$?"),
						ft_itoa(g_gv.exit_status));
			i++;
		}
		tmp = tmp->next;
	}
}
