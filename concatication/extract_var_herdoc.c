/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_var_herdoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:09:42 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/05 16:04:30 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*extract_var_herdoc_help(char *str, int *i, int start, t_env *envir)
{
	char	*res;
	t_env	*node;

	if (ft_isdigit(str[(*i)]))
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
		while (str[(*i)] && (ft_isalnum(str[(*i)]) || str[(*i)] == '_'))
			(*i)++;
		res = ft_substr(str, start, (*i) - start);
		node = heredoc_return_node(res, envir);
		if (node)
			str = rep_str(str, res, ft_strdup(node->value));
		else
			str = rep_str(str, res, ft_strdup(""));
	}
	return (str);
}

char	*extract_var_herdoc(char *str, t_env *envir)
{
	int	i;
	int	start;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '$')
			i++;
		start = i;
		if (str[i])
			i++;
		str = extract_var_herdoc_help(str, &i, start, envir);
	}
	return (str);
}
