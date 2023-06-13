/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_var_dq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:45:58 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/13 16:05:26 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*return_node_with_cond(t_env *env, char *str)
{
	t_env	*tmp;
	tmp = env;
	if (!tmp || !str)
		return NULL;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, str))
			return tmp;
		tmp = tmp->next;
	}
	return (NULL);
}


t_list	*rep_var_dq(t_list *list, t_env *envir)
{
	t_list	*tmp;
	t_list	*flist;
	t_env	*node;
	char *replaced;
	int		len = 0;
	int k = 0;
	int j = 0;
	int start = 0;
	int end = 0;
	int t = 0;
	int p = 0;
	tmp = list;
	flist = NULL;
	node = NULL;
	while (tmp)
	{
		while (tmp && tmp->type != DOUBLE_QUOTE)
		{
			ft_lstadd_back(&flist, ft_lstnew_tokens(tmp->content, tmp->type));
			tmp = tmp->next;
		}
		if (tmp && tmp->type == DOUBLE_QUOTE && ft_strchr(tmp->content, '$'))
		{
			while (tmp->content[len])
			{
				end = 0;
				while (tmp->content[len] && tmp->content[len] != '$')
					len++;
				start = len; //len = 0;
				len++; // len = 1;
				if (tmp->content[len] == '$')
				{
					while (tmp->content[len] && tmp->content[len] == '$')
					{
						len++;
						end++;
					}
					if ((end + 1) % 2 == 0)
						tmp->content = replace_string(tmp->content, ft_substr(tmp->content, start, end + 1), ft_strdup(""));
					else
					{
						tmp->content = replace_string(tmp->content, ft_substr(tmp->content, start, end + 1), ft_strdup("$"));
						node = return_node_with_cond(envir, tmp->content);
					}
				}
				else if (ft_isalnum(tmp->content[len]) || tmp->content[len] == '_')
				{
					while (tmp->content[len] && (ft_isalnum(tmp->content[len]) || tmp->content[len] == '_'))
					{
						len++;
						end++;
					}
					node = return_node_with_cond(envir, ft_substr(tmp->content, start, end + 1));
					if (node)
					{
						tmp->content = replace_string(tmp->content, ft_substr(tmp->content, start, end + 1), node->value);
						len += end + 1 - ft_strlen(node->value);
					}
					else
					{
						tmp->content = replace_string(tmp->content, ft_substr(tmp->content, start, end + 1), ft_strdup(""));
						len += end + 1;
					}
				}
				while (tmp->content[len] && tmp->content[len] != '$')
					len++;
			}
			printf("len : %d\n", len);
			ft_lstadd_back(&flist, ft_lstnew_tokens(tmp->content, tmp->type));
			if (tmp)
				tmp = tmp->next;
		}
		else if (tmp && tmp->type == DOUBLE_QUOTE && !ft_strchr(tmp->content, '$'))
		{
			ft_lstadd_back(&flist, ft_lstnew_tokens(tmp->content, tmp->type));
			tmp = tmp->next;
		}
		if (tmp)
			tmp = tmp->next;
	}
	return flist;
}
