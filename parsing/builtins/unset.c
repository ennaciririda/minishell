/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:35:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/16 21:03:58 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	unset_help(t_env **envir, char *cmd)
{
	t_env	*tmp;
	t_env	*bef;
	t_env	*aft;

	aft = NULL;
	bef = NULL;
	tmp = *envir;
	while (tmp)
	{
		if (tmp->next && !ft_strcmp(cmd, tmp->next->variable + 1))
		{
			bef = tmp;
			tmp = tmp->next;
			if (tmp->next)
				aft = tmp->next;
			bef->next = aft;
			free(tmp->variable);
			free(tmp->value);
			free(tmp);
			break ;
		}
		if (tmp)
			tmp = tmp->next;
	}
}

void	search_and_destroy_var(t_env **envir, char *cmd)
{
	t_env	*bef;

	bef = NULL;
	if (!ft_strcmp(cmd, (*envir)->variable + 1))
	{
		bef = *envir;
		if (*envir)
			(*envir) = (*envir)->next;
		free(bef->variable);
		free(bef->value);
		free(bef);
		bef = NULL;
	}
	else
		unset_help(envir, cmd);
}

void	empty_var()
{
	ft_printf(2, "unset : `': not a valid identifier\n");
	g_gv.exit_status = 1;
}

void	unset(t_env **envir, char **cmd)
{
	int		i;

	i = 1;
	if (*envir)
	{
		while (cmd[i])
		{
			if (!ft_strcmp(cmd[i], ""))
				empty_var();
			if (cmd[i] && export_check_var(cmd[i]))
				search_and_destroy_var(envir, cmd[i]);
			else if (!export_check_var(cmd[i]))
			{
				ft_printf(2, "unset : \'%s\' not a valid identifier\n", cmd[i]);
				g_gv.exit_status = 1;
			}
			i++;
		}
	}
}
