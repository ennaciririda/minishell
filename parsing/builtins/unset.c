/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:35:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/11 01:44:26 by hlabouit         ###   ########.fr       */
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
	}
	else
		unset_help(envir, cmd);
}

void	unset(t_env **envir, char **cmd)
{
	int		i;
	char	*s;

	i = 1;
	while (cmd[i])
	{
		if (cmd[i] && !ft_strcmp(cmd[i], " "))
			i++;
		s = ft_strdup(cmd[i]);
		if (cmd[i] && export_check_var(s))
		{
			search_and_destroy_var(envir, cmd[i]);
			free(s);
		}
		i++;
	}
}
