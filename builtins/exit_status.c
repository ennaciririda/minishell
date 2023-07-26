/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:15:09 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/26 18:58:19 by rennacir         ###   ########.fr       */
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
						ft_itoa(g_gv.ex_status));
			i++;
		}
		tmp = tmp->next;
	}
}
