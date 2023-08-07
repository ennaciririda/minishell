/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:19:55 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/07 21:47:26 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

void	commands(t_finallist *lastlist, t_env **envir)
{
	t_finallist	*tmp;
	char		**cmd;

	tmp = lastlist;
	while (tmp)
	{
		cmd = tmp->cmd;
		if (cmd [0] && check_word("echo", cmd[0]))
			echo(cmd);
		else if (cmd [0] && check_word("cd", cmd[0]))
			cd(*envir, cmd);
		else if (cmd [0] && check_word("pwd", cmd[0]))
			pwd(cmd);
		else if (cmd[0] && check_word("env", cmd[0]) && count(cmd) == 1)
			env(*envir);
		else if (cmd[0] && !ft_strcmp("export", cmd[0]))
			export(envir, cmd);
		else if (cmd[0] && !ft_strcmp("exit", cmd[0]))
			exit_cmd(cmd);
		else if (cmd[0] && !ft_strcmp("unset", cmd[0]))
			unset(envir, cmd);
		tmp = tmp->next;
	}
}
