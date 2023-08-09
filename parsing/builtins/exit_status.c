/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:15:09 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/09 17:05:11 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_status(t_finallist *lastlist)
{
	t_finallist	*tmp;
	char		**cmd;
	int			i;

	i = 0;
	tmp = lastlist;
	while (tmp)
	{
		cmd = tmp->cmd;
		i = 0;
		while (cmd[i])
		{
			if (ft_strstr(cmd[i], "$?"))
				cmd[i] = rep_str(cmd[i], ft_strdup("$?"),
						ft_itoa(g_gv.exit_status));
			i++;
		}
		tmp = tmp->next;
	}
}
