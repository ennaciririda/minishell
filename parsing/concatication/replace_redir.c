/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:38:08 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/08 15:43:56 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	replace_redir_help(t_list **tmp, t_list **new_list)
{
	int	type;

	type = (*tmp)->type;
	(*tmp) = (*tmp)->next;
	if ((*tmp) && (*tmp)->type == WHITE_SPACE)
		(*tmp) = (*tmp)->next;
	if ((*tmp))
	{
		add_back(new_list, new_tokens(ft_strdup((*tmp)->content),
				type));
		(*tmp) = (*tmp)->next;
	}
}

void	replace_redir_help_1(t_list **tmp, t_list **new_list,
		t_env *envir, int tabc)
{
	char	*str;
	int		type;

	type = (*tmp)->type;
	if ((*tmp))
		(*tmp) = (*tmp)->next;
	if ((*tmp) && (*tmp)->type == WHITE_SPACE)
		(*tmp) = (*tmp)->next;
	str = here_doc_case(g_gv.spl[g_gv.rep_tab_c], envir, tabc);
	add_back(new_list, new_tokens(str, type));
	g_gv.rep_tab_c++;
	if ((*tmp))
		(*tmp) = (*tmp)->next;
}

t_list	*replace_redir(t_list *list, t_env *envir, int *tab)
{
	t_list	*tmp;
	t_list	*new_list;

	new_list = NULL;
	tmp = list;
	g_gv.tab_count = 0;
	while (tmp)
	{
		if (tmp->type == ARED_OUT || tmp->type == RED_IN
			|| tmp->type == RED_OUT)
			replace_redir_help(&tmp, &new_list);
		else if (tmp->type == HER_DOC)
		{
			replace_redir_help_1(&tmp, &new_list, envir, tab[g_gv.tab_count]);
			g_gv.tab_count++;
		}
		else
		{
			add_back(&new_list, new_tokens(ft_strdup(tmp->content),
					tmp->type));
			tmp = tmp->next;
		}
	}
	free_any_stack(&list);
	return (new_list);
}
