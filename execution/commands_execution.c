/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:13:06 by hlabouit          #+#    #+#             */
/*   Updated: 2023/08/15 23:06:31 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execute_command(t_finallist *commands_list, t_env **environment)
{
	char	*exact_path;
	char	**envp;

	exact_path = NULL;
	envp = get_environment_variables(*environment);
	if (ft_strncmp(commands_list->cmd[0], "./", 2) == 0
		|| ft_strncmp(commands_list->cmd[0], "/", 1) == 0)
		exact_path = check_start_of_path(commands_list);
	else
		exact_path = get_exact_path(commands_list->cmd[0], envp);
	check_if_valid_path(commands_list, exact_path);
	if (execve(exact_path, commands_list->cmd, envp) == -1)
	{
		perror("minishell");
		exit(127);
	}
	return (0);
}

void	norm_struggles(t_finallist *commands_list, t_env **environment)
{
	if (input_output_redirection(commands_list) < 0)
	{
		ft_printf(2, "minishell: permission denied\n");
		exit(1);
	}
	if (check_builtins(commands_list->cmd[0]) == 0)
	{
		execute_builtin(commands_list->cmd, environment);
		exit(g_gv.exit_status);
	}
	else
	{
		change_2d_tab(&commands_list);
		execute_command(commands_list, environment);
	}
}

int	generate_child_p(t_finallist *commands_list, t_env **environment,
		int commands_nb, int *pipe_ends)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		dup2(g_gv.read_end, 0);
		if (commands_nb != 1)
			dup2(pipe_ends[1], 1);
		ft_close(pipe_ends[1]);
		ft_close(pipe_ends[0]);
		norm_struggles(commands_list, environment);
	}
	return (pid);
}

void	loop_and_execute(t_finallist *commands_list, t_env **environment,
			int commands_nb)
{
	int	pid;
	int	pipe_ends[2];

	while (commands_nb)
	{
		if (pipe(pipe_ends) < 0)
		{
			ft_printf(2, "pipe function has failed");
			exit(1);
		}
		pid = generate_child_p(commands_list, environment,
				commands_nb, pipe_ends);
		retrieve_exit_status(pid, commands_nb);
		ft_close(pipe_ends[1]);
		ft_close(g_gv.read_end);
		g_gv.read_end = pipe_ends[0];
		commands_list = commands_list->next;
		commands_nb--;
	}
}

int	commands_execution(t_finallist *commands_list, t_env **environment)
{
	int	commands_nb;

	commands_nb = number_of_nodes(commands_list);
	if (commands_nb == 1 && check_builtins(commands_list->cmd[0]) == 0)
	{
		if (input_output_redirection(commands_list) < 0)
		{
			ft_printf(2, "minishell: permission denied\n");
			g_gv.exit_status = 1;
			return (-1);
		}
		execute_builtin(commands_list->cmd, environment);
		return (0);
	}
	g_gv.read_end = 0;
	loop_and_execute(commands_list, environment, commands_nb);
	ft_close(g_gv.read_end);
	while (wait(NULL) != -1)
		;
	return (0);
}
