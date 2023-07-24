/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatinated_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:11:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/24 15:54:00 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*concatinated_list_help(t_list **tmp)
{
	char	*join;
	char	*s;

	join = NULL;
	s = ft_strjoin(ft_strdup((*tmp)->content), ft_strdup(""));
	(*tmp) = (*tmp)->next;
	while ((*tmp) && check_type((*tmp)->type))
	{
		if ((*tmp)->type == DOUBLE_QUOTE || (*tmp)->type == SINGLE_QUOTE)
			gv.fll = 1337;
		join = ft_strjoin(s, ft_strdup((*tmp)->content));
		s = ft_strdup(join);
		free(join);
		join = NULL;
		(*tmp) = (*tmp)->next;
	}
	return (s);
}

t_list	*concatinated_list(t_list *list)
{
	t_list	*tmp;
	char	*s;
	t_list	*clist;

	tmp = list;
	clist = NULL;
	while (tmp)
	{
		if (!check_type(tmp->type))
		{
			add_back(&clist, new_tokens(ft_strdup(tmp->content),
					tmp->type));
			tmp = tmp->next;
		}
		else
		{
			s = concatinated_list_help(&tmp);
			add_back(&clist, new_tokens(s, WORD));
		}
	}
	return (clist);
}
