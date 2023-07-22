/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:35:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/21 17:48:02 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	search_and_destroy_var(t_env *envir, char *cmd)
{
	t_env *tmp;
	t_env *bef;
	t_env *aft;
	tmp = envir;
	aft = NULL;
	bef = NULL;
	if (!ft_strcmp(cmd, envir->variable + 1))
	{
		bef = envir;
		if (envir)
			envir = envir->next;
		// free(bef);
	}
	else
	{
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
}

void unset(t_env *envir, char **cmd)
{
	int i = 1;

	if (cmd[i] && !ft_strcmp(cmd[i]," "))
		i++;
	if (export_check_var(ft_strdup(cmd[i])))
		search_and_destroy_var(envir, cmd[i]);
}