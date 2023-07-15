/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:19:55 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/15 13:39:35 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	commands(t_finallist *lastlist, t_env *envir)
{
	t_finallist *tmp;
	char **cmd;
	tmp = lastlist;
	while (tmp)
	{
		cmd = tmp->cmd;
		if (cmd [0] && check_word("echo", cmd[0]))
			echo(lastlist, cmd);
		else if (cmd [0] && check_word("cd", cmd[0]))
			cd(lastlist, envir, cmd);
		else if (cmd [0] && check_word("pwd", cmd[0]))
			pwd(lastlist, cmd);
		else if (cmd[0] && check_word("env", cmd[0]))
			env(envir);

		tmp = tmp->next;
	}
}