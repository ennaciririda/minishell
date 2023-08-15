/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:38:08 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/15 21:59:11 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
	g_gv.inside_heredoc = 1;
	str = here_doc_case(g_gv.spl[g_gv.rep_tab_c], envir, tabc);
	g_gv.inside_heredoc = 0;
	if (isatty(0) == 0)
		g_gv.valide_stdin = 0;
	if (!str)
		g_gv.check_fd = 15;
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
	return (free_any_stack(&list), new_list);
}
