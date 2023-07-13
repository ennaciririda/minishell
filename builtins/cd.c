/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:27:50 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/13 22:41:35 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd(t_finallist	*lastlist, t_env *envir)
{

	t_finallist *tmp;
	char *str;
	char **cmd;
	int i;
	tmp = lastlist;
	while (tmp)
	{
		cmd = tmp->cmd;
		if (cmd[0] && !ft_strcmp(cmd[0], "cd"))
		{
			i = 1;
			if (cmd[i] && !ft_strcmp(cmd[i], " "))
				i++;
			if (!cmd[i])
				str = cd_get_env(envir, "$HOME");
			else
				str = ft_strdup(cmd[i]);
			chdir(str);
		}
		tmp = tmp->next;
	}
}