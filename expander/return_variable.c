/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:30:09 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/15 21:41:03 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*return_variable(char *str, t_env *envir)
{
	int	start = 0;
	t_env	*node;
	int end = 0;
	int j = 0;
	node = NULL;
	while (str[j])
	{
		end = 0;
		while (str[j] && str[j] != '$')
			j++;
		start = j;
		if (str[j])
		j++;
		if (str[j] && str[j] == '$')
		{
			while (str[j] && str[j] == '$')
			{
				j++;
				end++;
			}
			if ((end + 1) % 2 == 0)
			{
				str = replace_string(str, ft_substr(str, start, end + 1), ft_strdup(""));
				j = 0;
			}
			else
			{
				str = replace_string(str, ft_substr(str, start, end + 1), ft_strdup("$"));
				j = 0;
			}
		}
		else if (str[j] && (ft_isalnum(str[j]) || str[j] == '_'))
		{
			while (str[j] && (ft_isalnum(str[j]) || str[j] == '_'))
			{
				j++;
				end++;
			}
			node = return_node_with_cond(envir, ft_substr(str, start, end + 1));
			if (node)
			{
				str = replace_string(str, ft_substr(str, start, end + 1), node->value);
				j = 0;
			}
			else
			{
				str = replace_string(str, ft_substr(str, start, end + 1), ft_strdup(""));
				j = 0;
			}
		}
	}
	return str;
}
