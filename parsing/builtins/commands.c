/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:19:55 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/03 22:49:43 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		else if (cmd[0] && check_word("env", cmd[0]))
			env(*envir);
		else if (cmd[0] && !ft_strcmp("export", cmd[0]))
			export(*envir, cmd);
		else if (cmd[0] && !ft_strcmp("exit", cmd[0]))
			exit_cmd(cmd);
		else if (cmd[0] && !ft_strcmp("unset", cmd[0]))
			unset(envir, cmd);
		tmp = tmp->next;
	}
}
