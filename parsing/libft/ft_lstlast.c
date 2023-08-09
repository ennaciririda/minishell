/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:19:57 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/08 23:00:49 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_env	*ft_lstlast_env(t_env *env)
{
	if (!env)
		return (NULL);
	while (env->next)
		env = env->next;
	return (env);
}

t_globallist	*ft_lstlast_global(t_globallist *glist)
{
	while (glist)
	{
		if (glist && !glist->next)
			return (glist);
		if (glist && glist->next)
			glist = glist->next;
	}
	return (glist);
}

t_finallist	*ft_lstlast_resume(t_finallist *resumelist)
{
	while (resumelist)
	{
		if (resumelist && !resumelist->next)
			return (resumelist);
		if (resumelist && resumelist->next)
			resumelist = resumelist->next;
	}
	return (resumelist);
}
