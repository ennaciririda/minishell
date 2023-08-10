/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:34:00 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/08 23:01:28 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_cmd(t_list *list)
{
	t_list	*tmp;
	int		count;

	tmp = list;
	count = 0;
	while (tmp)
	{
		if (tmp->type == WHITE_SPACE)
			tmp = tmp->next;
		else
		{
			count++;
			tmp = tmp->next;
		}
	}
	return (count);
}
