/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:30:09 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/16 17:48:54 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*return_var_help(char *str, int *j, int start)
{
	int	end;

	end = 0;
	while (str[(*j)] && str[(*j)] == '$')
	{
		(*j)++;
		end++;
	}
	if ((end + 1) % 2 == 0)
	{
		str = rep_str(str, ft_substr(str, start, end + 1), ft_strdup(""));
		(*j) = 0;
	}
	else
	{
		str = rep_str(str, ft_substr(str, start, end + 1), ft_strdup("$"));
		(*j) = 0;
	}
	return (str);
}

char	*return_var_help1h(char *str, int st, int end, int *j)
{
	str = rep_str(str, ft_substr(str, st, end + 1), ft_strdup(""));
	(*j) = 0;
	return (str);
}

char	*return_var_help1(char *str, int *j, int st, t_env *envir)
{
	int		end;
	t_env	*node;

	node = NULL;
	end = 0;
	if (ft_isdigit(str[(*j)]))
		end = 1;
	else
	{
		while (str[(*j)] && (ft_isalnum(str[(*j)]) || str[(*j)] == '_'))
		{
			(*j)++;
			end++;
		}
	}
	node = return_node_with_cond(envir, ft_substr(str, st, end + 1));
	if (node)
	{
		str = rep_str(str, ft_substr(str, st, end + 1), ft_strdup(node->value));
		(*j) = 0;
	}
	else
		str = return_var_help1h(str, st, end, j);
	return (str);
}

char	*return_var(char *str, t_env *envir)
{
	int	start;
	int	end;
	int	j;

	start = 0;
	j = 0;
	while (str[j])
	{
		end = 0;
		while (str[j] && str[j] != '$')
			j++;
		start = j;
		if (str[j])
			j++;
		if (str[j] && str[j] == '$')
			str = return_var_help(str, &j, start);
		else if (str[j] && (ft_isalnum(str[j]) || str[j] == '_'))
			str = return_var_help1(str, &j, start, envir);
	}
	return (str);
}
