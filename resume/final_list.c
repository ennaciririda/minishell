/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:42:01 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/06 22:43:25 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_globallist	*final_list(t_list *list)
{
	t_globallist	*glist;
	t_list			*tmp;
	t_list			*cmd;
	t_list			*red;

	glist = NULL;
	tmp = list;
	while (tmp)
	{
		cmd = NULL;
		red = NULL;
		while (tmp && tmp->type != PIPE)
		{
			if (!check_redir_type(tmp->type))
				add_back(&cmd, new_tokens(ft_strdup(tmp->content), tmp->type));
			else
				add_back(&red, new_tokens(ft_strdup(tmp->content), tmp->type));
			tmp = tmp->next;
		}
		add_back_global(&glist, ft_lstnew_global(cmd, red));
		if (tmp)
			tmp = tmp->next;
	}
	free_any_stack(&newlist);
	return (glist);
}
