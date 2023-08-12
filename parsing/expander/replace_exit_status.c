/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_exit_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:34:41 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/11 16:36:36 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	replace_ex(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->type == DOLLAR_WHY || tmp->type == DOUBLE_QUOTE)
		{
			if (tmp->type == DOLLAR_WHY)
				tmp->content = rep_str(tmp->content, ft_strdup(tmp->content),
						ft_itoa(g_gv.exit_status));
			else if (tmp->type == DOUBLE_QUOTE)
			{
				while (ft_strstr(tmp->content, "$?"))
					tmp->content = rep_str(tmp->content, ft_strdup("$?"),
							ft_itoa(g_gv.exit_status));
			}
		}
		tmp = tmp->next;
	}
}
