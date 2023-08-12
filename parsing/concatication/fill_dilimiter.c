/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_dilimiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:45:02 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/11 16:54:24 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_her(t_list *list)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->type == HER_DOC)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

char	*fill_dilimiter_help(t_list **tmp, int *tab)
{
	char	*s;

	s = NULL;
	if ((*tmp) && (*tmp)->type == WHITE_SPACE)
		(*tmp) = (*tmp)->next;
	if ((*tmp))
	{
		if ((*tmp)->type == 3 || (*tmp)->type == 4)
			tab[g_gv.tab_count] = 1337;
		s = ft_strjoin(ft_strdup((*tmp)->content), ft_strdup(""));
		(*tmp) = (*tmp)->next;
	}
	while ((*tmp) && !check_redir_type((*tmp)->type)
		&& (*tmp)->type != WHITE_SPACE)
	{
		if ((*tmp)->type == 3 || (*tmp)->type == 4)
			tab[g_gv.tab_count] = 1337;
		s = ft_strjoin(s, ft_strdup((*tmp)->content));
		(*tmp) = (*tmp)->next;
	}
	return (s);
}

char	**fill_dilimiter(t_list *list, int *tab)
{
	int		count;
	char	**spl;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = list;
	count = count_her(list);
	spl = malloc (sizeof(char *) * (count + 1));
	if (!spl)
		return (NULL);
	while (tmp)
	{
		if (tmp->type == HER_DOC)
		{
			tmp = tmp->next;
			spl[i] = fill_dilimiter_help(&tmp, tab);
			g_gv.tab_count++;
			i++;
		}
		else
			tmp = tmp->next;
	}
	spl[i] = NULL;
	return (spl);
}
