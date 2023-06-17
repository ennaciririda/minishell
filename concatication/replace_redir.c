/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:38:08 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/17 22:02:33 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*replace_redir(t_list *list)
{
	t_list *tmp;
	int type;
	t_list *new_list;
	new_list = NULL;
	tmp = list;
	type = 0;
	char	*str;
	while (tmp)
	{
		if (tmp->type == ARED_OUT || tmp->type == RED_IN || tmp->type == RED_OUT)
		{
			type = tmp->type;
			tmp = tmp->next;
			if (tmp && tmp->type == WHITE_SPACE)
				tmp = tmp->next;
			ft_lstadd_back(&new_list, ft_lstnew_tokens(tmp->content, type));
			tmp = tmp->next;
		}
		else if (tmp->type == HER_DOC)
		{
			str = here_doc_case(tmp->next->content);
		}
		else
		{
			ft_lstadd_back(&new_list, ft_lstnew_tokens(tmp->content, tmp->type));
			tmp = tmp->next;
		}
	}
	return new_list;
}
