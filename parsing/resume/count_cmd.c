/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:34:00 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/15 22:33:11 by hlabouit         ###   ########.fr       */
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
