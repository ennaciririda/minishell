/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:17:37 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/20 21:00:01 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_globallist *final_list(t_list *list)
{
	t_globallist *glist;
	t_list	*tmp;
	glist = NULL;
	tmp = list;

	while(tmp)
	{
		while (tmp && tmp->type != PIPE)
		{
			if	(check_type(tmp->type))
			{
				ft_lstadd_back($glist->cmd, ft_lstnew_tokens(tmp->content, tmp->type));
				tmp = tmp->next;
			}
			else if (check_redir_type(tmp->type))
			{
				ft_lstadd_back($glist->red, ft_lstnew_tokens(tmp->content, tmp->type));
				tmp = tmp->next;
			}
		}
		if (tmp || tmp->type == PIPE)
			tmp = tmp->next;
	}
	return glist;
}