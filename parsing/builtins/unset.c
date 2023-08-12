/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:35:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/12 01:39:29 by hlabouit         ###   ########.fr       */
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

void	unset(t_env **envir, char **cmd)
{
	int		i;
	char	*s;

	i = 1;
	if (*envir)
	{
		while (cmd[i])
		{
			s = ft_strdup(cmd[i]);
			if (cmd[i] && export_check_var(s))
			{
				search_and_destroy_var(envir, cmd[i]);
				free(s);
			}
			else if (!export_check_var(s))
			{
				ft_printf(2, "unset : \'%s\' not a valid identifier\n", cmd[i]);
				free(s);
				g_gv.exit_status = 1;
			}
			i++;
		}
	}
}
