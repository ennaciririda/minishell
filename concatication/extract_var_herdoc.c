/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_var_herdoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:09:42 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/12 21:18:53 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// nbedlou hna ou dik sa3at nemchi n3awed nbedlou f getnext line
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
				str = replace_string(str, node->variable, node->value);
			else
				str = replace_string(str, res, ft_strdup(""));
		}
		else
		{
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
				i++;
			res = ft_substr(str, start, i - start);
			node = heredoc_return_node(res, envir);
			if (node)
				str = replace_string(str, node->variable, node->value);
			else
				str = replace_string(str, res, ft_strdup(""));
		}
	}
	return str;
}
