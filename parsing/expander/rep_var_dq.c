/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_var_dq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:45:58 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/24 15:54:00 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*return_node_with_cond(t_env *env, char *str)
{
	t_env	*tmp;

	tmp = env;
	if (!tmp || !str)
		return (NULL);
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, str))
			return (tmp);
		tmp = tmp->next;
	}
	free(str);
	return (NULL);
}

void	rep_var_dq_help(t_list **flist, t_list *list, t_env *envir)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		while (tmp && tmp->type != DOUBLE_QUOTE)
		{
			add_back(flist, new_tokens(ft_strdup(tmp->content),
					tmp->type));
			tmp = tmp->next;
		}
		if (tmp && tmp->type == DOUBLE_QUOTE && ft_strchr(tmp->content, '$'))
		{
			add_back(flist, new_tokens(return_var(tmp->content,
						envir), tmp->type));
			tmp = tmp->next;
		}
		else if (tmp && tmp->type == DOUBLE_QUOTE
			&& !ft_strchr(tmp->content, '$'))
		{
			add_back(flist, new_tokens(ft_strdup(tmp->content),
					tmp->type));
			tmp = tmp->next;
		}
	}
}

t_list	*rep_var_dq(t_list *list, t_env *envir)
{
	t_list	*tmp;
	t_list	*flist;

	tmp = list;
	flist = NULL;
	rep_var_dq_help(&flist, list, envir);
	return (flist);
}