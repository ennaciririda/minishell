/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:37:14 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/21 15:50:46 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst)
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_lstadd_back_env(t_env **env, t_env *new)
{
	t_env	*tmp;

	if (env)
	{
		if (*env)
		{
			tmp = ft_lstlast_env(*env);
			tmp->next = new;
		}
		else
			*env = new;
	}
}

// void	ft_lstadd_back_global(t_globallist **glist, t_globallist *new_glist)
// {
// 	t_globallist	*tmp;

// 	if (glist)
// 	{
// 		if (*glist)
// 		{
// 			tmp = ft_lstlast_global(*glist);
// 			tmp->next = new_glist;
// 		}
// 		else
// 			*glist = new_glist;
// 	}
// }