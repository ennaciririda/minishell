/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:35:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/27 18:21:20 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		free(bef);
	}
	else
		unset_help(envir, cmd);
}

void	unset(t_env **envir, char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		if (cmd[i] && !ft_strcmp(cmd[i], " "))
			i++;
		if (cmd[i] && export_check_var(ft_strdup(cmd[i])))
			search_and_destroy_var(envir, cmd[i]);
		i++;
	}
}
