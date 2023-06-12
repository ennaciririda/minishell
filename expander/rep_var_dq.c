/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_var_dq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:45:58 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/12 16:36:58 by rennacir         ###   ########.fr       */
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
			len = 0;
			while (tmp->content[len])
			{
				end = 0;
				while (tmp->content[len] && tmp->content[len] != '$')
					len++;
				start = len;
				len++;
				while (tmp->content[len] && (ft_isalnum(tmp->content[len]) || tmp->content[len] == '_'))
				{
					len++;
					end++;
				}
				// printf("substr :[%s]\n", ft_substr(tmp->content, start, end + 1));
				node = return_node_with_cond(envir, ft_substr(tmp->content, start, end + 1));
				if (node)
				{
					tmp->content = replace_string(tmp->content, node->variable, node->value);
				}
				while (tmp->content[len] && tmp->content[len] != '$')
					len++;
			}
			printf("tmp.content : [%s]\n",tmp->content);
			// if (!ft_isalnum(tmp->content[len + 1]) && tmp->content[len + 1] != '_' && tmp->content[len + 1] != '$')
			// {
			// 	ft_lstadd_back(&flist, ft_lstnew_tokens(tmp->content, tmp->type));
			// 	tmp = tmp->next;
			// }
			// else if (ft_isalnum(tmp->content[len + 1]) || tmp->content[len + 1] == '_')
			// {
			// 	j = 0;
			// 	k = len;
			// 	while (tmp->content[k + 1] && (ft_isalnum(tmp->content[k + 1]) || tmp->content[k + 1] == '_'))
			// 	{
			// 		j++;
			// 		k++;
			// 	}
			// 	node = return_node_with_cond(envir, ft_substr(tmp->content, len, j + 1));
			// 	printf("substr :[%s]\n", ft_substr(tmp->content, len, j + 1));
			// 	if (node)
			// 	{
			// 		replaced = replace_string(tmp->content, node->variable, node->value);
			// 		printf("replaced :[%s]\n", replaced);
			// 		ft_lstadd_back(&flist, ft_lstnew_tokens(replaced, tmp->type));
			// 		tmp = tmp->next;
			// 	}
			// 	// else
			// 	// {
			// 	// 	replaced = replace_string(tmp->content, node->variable, ft_strdup(""));
			// 	// 	printf("replaced :[%s]\n", replaced);
			// 	// 	// ft_lstadd_back(&flist, ft_lstnew_tokens(replaced, tmp->type));
			// 	// 	// ft_lstadd_back(&flist, ft_lstnew_tokens(tmp->content, tmp->type));
			// 	// 	// tmp = tmp->next;
			// 	// }
			// }
			// else if (tmp->content[len + 1] == '$')
			// {
			// 	t = len;
			// 	while (tmp->content[t + 1] && tmp->content[t + 1] == '$')
			// 	{
			// 		t++;
			// 		p++;
			// 	}
			// 	replaced = replace_string(tmp->content, ft_substr(tmp->content, len, p), ft_strdup(""));
			// 	printf("replaced :[%s]\n", replaced);
			// 	ft_lstadd_back(&flist, ft_lstnew_tokens(replaced, tmp->type));
			// 	tmp = tmp->next;
			// }
		}
		// else if (tmp && tmp->type == DOUBLE_QUOTE && !ft_strchr(tmp->content, '$'))
		// {
		// 	ft_lstadd_back(&flist, ft_lstnew_tokens(tmp->content, tmp->type));
		// 	tmp = tmp->next;
		// }
		if (tmp)
			tmp = tmp->next;
	}
	return flist;
}
