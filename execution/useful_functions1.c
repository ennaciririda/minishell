/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 05:06:04 by hlabouit          #+#    #+#             */
/*   Updated: 2023/08/08 23:13:06 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	number_of_nodes(t_finallist *head)
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
int	number_of_nodes2(t_env *head)
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