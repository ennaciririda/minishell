/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 05:06:04 by hlabouit          #+#    #+#             */
/*   Updated: 2023/07/31 15:52:40 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	number_of_nodes(t_list *head)
{
	int	n;

	n = 0;
	if (head == NULL)
		return (n);
	while (head)
	{
		head = head->next;
		n++;
	}
	return (n);
}
