/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatinated_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:11:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/18 18:05:19 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*concatinated_list(t_list *list)
{
	t_list *tmp;
	tmp = list;
	char *join;
	char *s;
	t_list *clist;
	clist = NULL;
	join = NULL;
	while (tmp)
	{
		if (!check_type(tmp->type))
		{
			ft_lstadd_back(&clist, ft_lstnew_tokens(ft_strdup(tmp->content), tmp->type));
			tmp = tmp->next;
		}
		else
		{
			s = ft_strjoin(ft_strdup(tmp->content), ft_strdup(""));
			tmp = tmp->next;
			while (tmp && check_type(tmp->type))
			{
				if (tmp->type == DOUBLE_QUOTE || tmp->type == SINGLE_QUOTE)
					gv.fll = 1337;
				join = ft_strjoin(s, ft_strdup(tmp->content));
				s = ft_strdup(join);
				free(join);
				join = NULL;
				tmp = tmp->next;
			}
			ft_lstadd_back(&clist, ft_lstnew_tokens(s, WORD));
		}
	}
	return clist;
}
