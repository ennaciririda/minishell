/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:32:05 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/17 17:47:09 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	only_export_case(t_env *envir)
{
	t_env *tmp;
	tmp = envir;
	while (tmp)
	{
		printf("declare -x %s=\"%s\"\n", tmp->variable + 1, tmp->value);
		tmp = tmp->next;
	}
}

void	update_var(t_env *envir, char *variable, char *value)
{
	t_env *tmp;

	tmp = envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, variable))
			tmp->value = value;
		tmp = tmp->next;
	}
}

void export(t_env *envir, char **cmd)
{
	int i = 1;
	int j = 0;
	char *sub;
	if (cmd[i] && !ft_strcmp(cmd[i]," "))
		i++;
	if (!cmd[i])
		only_export_case(envir);
	else if (ft_strchr(cmd[i], '='))
	{
		while (cmd[i][j] && cmd[i][j] != '=')
			j++;
		sub = ft_substr(cmd[i], 0, j);
		if (cmd[i][j])
			j++;
		if (check_var_if_exist(envir, sub))
			update_var(envir, sub, cmd[i] + j);
		else
		{
			 ft_lstadd_back_env(&envir, ft_lstnew_env(sub, cmd[i] + j));
		}
	}
}