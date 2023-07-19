/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:35:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/19 15:28:12 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	search_and_destroy_var(t_env *envir, char *cmd)
{
	t_env *tmp;
	t_env *bef;
	t_env *aft;
	tmp = envir;
	while (tmp)
	{
		if (tmp->next && !ft_strcmp(cmd, tmp->next->variable + 1))
		{
			bef = tmp;
			tmp = tmp->next;
			if (tmp->next)
				aft = tmp->next;
			bef->next = aft;
			free_any_stack_env(tmp);
		}
		else if (!ft_strcmp(cmd, tmp->variable + 1))
		{
			bef = ft_lstlast_env(tmp);
			free_any_stack_env(bef);
		}
		if (tmp)
			tmp = tmp->next;
	}
}

void unset(t_env *envir, char **cmd)
{
	int i = 1;

	if (cmd[i] && !ft_strcmp(cmd[i]," "))
		i++;
	if (export_check_var(cmd[i]))
		search_and_destroy_var(envir, cmd[i]);
}