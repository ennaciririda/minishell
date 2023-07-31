/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:14:19 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/03 16:18:39 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*ls;

	count = 0;
	ls = lst;
	while (ls != NULL)
	{
		count++;
		ls = ls->next;
	}
	return (count);
}
