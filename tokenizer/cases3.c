/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 08:59:08 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/23 08:59:37 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	double_dollar(t_list **list, int *i)
{
	ft_lstadd_back(list, ft_lstnew_tokens(ft_strdup("$$"), DOUBLE_DOLLAR));
	(*i) = (*i) + 2;
}
void	why_dollar(t_list **list, int *i)
{
	ft_lstadd_back(list, ft_lstnew_tokens(ft_strdup("$?"), DOLLAR_WHY));
	(*i) = (*i) + 2;
}
