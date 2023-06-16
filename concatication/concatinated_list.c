/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatinated_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:11:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/16 20:56:30 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*concatinated_list(t_list *list)
{
	t_list *tmp;
	tmp = list;
	char *join;
	t_list *clist;
	clist = NULL;
	while (tmp)
	{
		if (!check_type(tmp->type))
		{
			ft_lstadd_back(&clist, ft_lstnew_tokens(tmp->content, tmp->type));
			tmp = tmp->next;
		}
		else
		{
			join = ft_strjoin(tmp->content, ft_strdup(""));
			tmp = tmp->next;
			while (tmp && check_type(tmp->type))
			{
				join = ft_strjoin(join, tmp->content);
				tmp = tmp->next;
			}
			ft_lstadd_back(&clist, ft_lstnew_tokens(join, WORD));
		}
	}
	return clist;
}