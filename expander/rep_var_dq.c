/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_var_dq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:45:58 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/10 14:54:25 by rennacir         ###   ########.fr       */
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
	t_list *final_list;
	t_list *tmp;
	char	*tmpstr;
	char	*replaced;
	t_env	*node;
	int		start = 0;
	int i = 0;
	int j = 0;
	int len = 0;
	tmp = list;
	final_list = NULL;
	replaced = NULL;
	while (tmp)
	{
		while (tmp && tmp->type != DOUBLE_QUOTE)
		{
			ft_lstadd_back(&final_list, ft_lstnew_tokens(tmp->content, tmp->type));
			tmp = tmp->next;
		}
		len = return_index_of_char(tmp->content, '$');
		printf("len = %d\n", len);
		if (tmp && ft_strchr(tmp->content, '$') && ft_isalnum(tmp->content[len + 1]))
		{
			i = 0;
			while (tmp->content[i])
			{
				while (tmp->content[i] && tmp->content[i] != '$')
					i++;
				start = i + 1;
				i++;
				while (tmp->content[i] && (ft_isalnum(tmp->content[i]) || tmp->content[i] == '_'))
				{
					j++;
					i++;
				}
				// printf("substr %s\n", ft_substr(tmp->content, start, j));
				node = return_node_with_cond(envir, ft_substr(tmp->content, start, j));
				if (node)
				{
					printf("substr : {%s}\n",ft_substr(tmp->content, start - 1, j + 1));
					replaced =  replace_string(tmp->content, ft_substr(tmp->content, start, j + 1), node->value);
					ft_lstadd_back(&final_list, ft_lstnew_tokens(replaced, tmp->type));
					if(tmp->next)
						tmp = tmp->next;
				}
				i++;
			}
		}
		else if (ft_strchr(tmp->content, '$') && !ft_isalnum(tmp->content[len + 1]) && tmp->content[len + 1] != '_' &&  tmp->content[len + 1] != '$')
		{
			ft_lstadd_back(&final_list, ft_lstnew_tokens(tmp->content, tmp->type));
			if(tmp->next)
				tmp = tmp->next;
		}
		if(tmp)
			tmp = tmp->next;
	}
	return final_list;
}