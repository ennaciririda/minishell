/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:34:00 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/09 14:34:11 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int count_cmd(t_list *list)
{
	t_list *tmp;
	int count = 0;
	tmp = list;
	while (tmp && tmp->type == WHITE_SPACE)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->type == WHITE_SPACE && (!tmp->next || tmp->next->type == WHITE_SPACE))
			tmp = tmp->next;
		else
		{
			count++;
			tmp = tmp->next;
		}
	}
	return count;
}