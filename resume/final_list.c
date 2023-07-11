// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   final_list.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/06/20 20:17:37 by rennacir          #+#    #+#             */
// /*   Updated: 2023/06/21 13:23:15 by rennacir         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../minishell.h"

t_globallist *final_list(t_list *list)
{
	t_globallist *glist;
	t_list	*tmp;
	t_list *cmd;
	t_list *redir;
	glist = NULL;
	tmp = list;

	while(tmp)
	{
		cmd = NULL;
		redir = NULL;
		while (tmp && tmp->type != PIPE)
		{
			if (!check_redir_type(tmp->type))
				ft_lstadd_back(&cmd, ft_lstnew_tokens(tmp->content, tmp->type));
			else
				ft_lstadd_back(&redir, ft_lstnew_tokens(tmp->content, tmp->type));
			tmp = tmp->next;
		}
		ft_lstadd_back_global(&glist, ft_lstnew_global(cmd, redir));
		if (tmp)
			tmp = tmp->next;
	}
	return glist;
}