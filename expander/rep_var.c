/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:02:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/07 22:41:52 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_if_exist(t_list *list, t_env *env)
{
	t_list	*tmp;
	t_env	*etmp;

	// if (!list || !env)
	// 	return -41;
	tmp = list;
	etmp = env;
	while (tmp)
	{
		if (tmp->type == VARIABLE)
		{
			while (etmp)
			{
				if (etmp->variable == tmp->content + 1)
					return 1;
				etmp = etmp->next;
			}
		}
		tmp = tmp->next;
	}
	return 0;
}

// void	rep_var(t_list **list, t_env *envir)
// {
// 	t_list	*tmp;
// 	t_env	*etmp;
// 	t_list	*new_list;
// 	tmp = *list;
// 	etmp = envir;

// 	while (tmp)
// 	{
// 		while (tmp && tmp->type != VARIABLE)
// 		{
// 			ft_lstadd_back(&new_list, ft_lstnew_tokens(tmp->content, tmp->type));
// 			tmp = tmp->next;
// 		}
// 		check_if_exist(tmp, etmp);
// 		tmp = tmp->next;
// 	}
// }