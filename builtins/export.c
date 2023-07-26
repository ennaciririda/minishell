/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:32:05 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/26 18:58:56 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	only_export_case(t_env *envir)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!tmp->value)
			ft_printf(1, "declare -x %s\n", tmp->variable + 1);
		else
			ft_printf(1, "declare -x %s=\"%s\"\n", tmp->variable + 1, tmp->value);
		tmp = tmp->next;
	}
	g_gv.ex_status = 0;
}

void	update_var(t_env **envir, char *variable, char *value)
{
	t_env	*tmp;

	tmp = *envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, variable))
			tmp->value = value;
		tmp = tmp->next;
	}
	g_gv.ex_status = 0;
}

void	export(t_env *envir, char **cmd)
{
	int	i;

	i = 1;
	if (cmd[i] && !ft_strcmp(cmd[i], " "))
		i++;
	if (!cmd[i])
		only_export_case(envir);
	while (cmd[i])
	{
		if (cmd[i] && ft_strstr(cmd[i], "+="))
			export_append_case(envir, cmd[i]);
		else if (cmd[i] && ft_strchr(cmd[i], '='))
		{
			if (!export_help_3(&envir, cmd[i]))
				return ;
		}
		else
		{
			if (!export_help_4(&envir, cmd[i]))
				return ;
		}
		i++;
	}
}
