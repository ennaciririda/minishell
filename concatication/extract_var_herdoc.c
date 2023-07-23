/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_var_herdoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:09:42 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/23 11:30:34 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*extract_var_herdoc(char *str, t_env *envir)
{
	int i = 0;
	int start = 0;
	char *res;
	t_env *node;
	while (str[i])
	{
		while (str[i] && str[i] != '$')
			i++;
		start = i;
		if (str[i])
			i++;
		if (ft_isdigit(str[i]))
		{
			res = ft_substr(str, start, 2);
			node = heredoc_return_node(res, envir);
			if (node)
				str = rep_str(str, res, ft_strdup(node->value));
			else
				str = rep_str(str, res, ft_strdup(""));
		}
		else
		{
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
				i++;
			res = ft_substr(str, start, i - start);
			node = heredoc_return_node(res, envir);
			if (node)
				str = rep_str(str, res, ft_strdup(node->value));
			else
				str = rep_str(str, res, ft_strdup(""));
		}
	}
	return str;
}
