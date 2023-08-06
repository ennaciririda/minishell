/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatinated_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:11:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/06 22:54:19 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*concatinated_list_help(t_list **tmp, int *tab)
{
	char	*join;
	char	*s;
	join = NULL;
	s = ft_strjoin(ft_strdup((*tmp)->content), ft_strdup(""));
	if ((*tmp)->type == DOUBLE_QUOTE || (*tmp)->type == SINGLE_QUOTE && g_gv.here_d)
			tab[g_gv.tab_count] = 1337;
	(*tmp) = (*tmp)->next;
	while ((*tmp) && check_type((*tmp)->type))
	{
		if ((*tmp)->type == DOUBLE_QUOTE || (*tmp)->type == SINGLE_QUOTE && g_gv.here_d)
			tab[g_gv.tab_count] = 1337;
		join = ft_strjoin(s, ft_strdup((*tmp)->content));
		s = ft_strdup(join);
		free(join);
		join = NULL;
		(*tmp) = (*tmp)->next;
	}
	if (g_gv.ppll > 0 && g_gv.tab_count < g_gv.ppll)
	{
		if (tab[g_gv.tab_count] != 1337)
			tab[g_gv.tab_count] = 0;
	}
	g_gv.tab_count++;
	return (s);
}

t_list	*concatinated_list(t_list *list, int *tab)
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
			if(tmp->type == HER_DOC)
				g_gv.here_d = 42;
			tmp = tmp->next;
		}
		else
		{
			s = concatinated_list_help(&tmp, tab);
			add_back(&clist, new_tokens(s, WORD));
			g_gv.here_d = 0;
		}
	}
	free_any_stack(&list);
	return (clist);
}
