/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatinated_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:11:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/05 18:11:16 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*concatinated_list_help(t_list **tmp, int *tab)
{
	char	*join;
	char	*s;
	static int i;
	join = NULL;

	s = ft_strjoin(ft_strdup((*tmp)->content), ft_strdup(""));
	if ((*tmp)->type == DOUBLE_QUOTE || (*tmp)->type == SINGLE_QUOTE)
		tab[i] = 1337;
	else
		tab[i] = 0;
	(*tmp) = (*tmp)->next;
	while ((*tmp) && check_type((*tmp)->type))
	{
		if ((*tmp)->type == DOUBLE_QUOTE || (*tmp)->type == SINGLE_QUOTE)
			tab[i] = 1337;
		else
			tab[i] = 0;
		join = ft_strjoin(s, ft_strdup((*tmp)->content));
		s = ft_strdup(join);
		free(join);
		join = NULL;
		(*tmp) = (*tmp)->next;
	}
	i++;
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
			tmp = tmp->next;
		}
		else
		{
			s = concatinated_list_help(&tmp, tab);
			add_back(&clist, new_tokens(s, WORD));
		}
	}
	return (clist);
}
