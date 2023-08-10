/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:13:06 by hlabouit          #+#    #+#             */
/*   Updated: 2023/08/10 18:03:47 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_global_path(char **env)
{
	char	**path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			path = ft_split_e(env[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (path);
}

char	*get_exact_path(char *command, char **env)
{
	char	**path;
	int		i;

	i = 0;
	if (access(command, X_OK) == 0)
		return (command);
	command = ft_strjoin_e("/", command);
	path = get_global_path(env);
	while (path[i])
	{
		path[i] = ft_strjoin_e(path[i], command);
		if (access(path[i], X_OK) == 0)
			break ;
		i++;
	}
	return (path[i]);
}

char	**get_environment_variables(t_env *environment)
{
	char	**envp;
	int		i;

	i = 0;
	envp = malloc((number_of_nodes2(environment) + 1) * sizeof(char *));
	if (!envp)
		return (NULL);
	while (environment)
	{
		envp[i] = ft_strjoin_e(&environment->variable[1], "=");
		envp[i] = ft_strjoin_e(envp[i], environment->value);
		environment = environment->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

void	ft_close(int fd)
{
	if (fd == 0 || fd == 1)
		return ;
	close(fd);
}

int	retrieve_exit_status(int pid, int commands_nb)
{
	if (commands_nb == 1)
	{
		waitpid(pid, &g_gv.exit_status, 0);
		if (WIFEXITED(g_gv.exit_status))
			g_gv.exit_status = WEXITSTATUS(g_gv.exit_status);
		if (WIFSIGNALED(g_gv.exit_status))
		{
			g_gv.sig_exit_status = 128 + WTERMSIG(g_gv.exit_status);
			if (g_gv.sig_exit_status == 130)
				printf("\n");
			else if (g_gv.sig_exit_status == 131)
				printf("Quit: 3\n");
		}
		return (g_gv.exit_status + g_gv.sig_exit_status);
	}
	return (-1);
}

int	open_file(t_finallist *commands_list, int flag)
{
	int	red_fd;

	if (flag == 0)
		red_fd = open(commands_list->red->content, O_RDONLY);
	else if (flag == 5)
		red_fd = open(commands_list->red->content,
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (flag == 6)
		red_fd = open(commands_list->red->content,
				O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (red_fd < 0)
		return (-1);
	if (flag == 0)
		dup2(red_fd, 0);
	else
		dup2(red_fd, 1);
	ft_close(red_fd);
	return (0);
}

int	input_output_redirection(t_finallist *commands_list)
{
	int	red_fd;

	while (commands_list->red)
	{
		if (commands_list->red->type == HER_DOC
			|| commands_list->red->type == RED_IN)
			open_file(commands_list, 0);
		else if (commands_list->red->type == RED_OUT)
			open_file(commands_list, 5);
		else if (commands_list->red->type == ARED_OUT)
			open_file(commands_list, 6);
		commands_list->red = commands_list->red->next;
	}
	return (0);
}

int	execute_command(t_finallist *commands_list, t_env *environment)
{
	char	*exact_path;
	char	**envp;

	envp = get_environment_variables(environment);
	exact_path = get_exact_path(commands_list->cmd[0], envp);
	if (execve(exact_path, commands_list->cmd, envp) == -1)
		ft_printf(2, "minishell: %s: command not found\n",
			commands_list->cmd[0]);
	return (0);
}

int	generate_child_p(t_finallist *commands_list, t_env *environment,
	int pid, int commands_nb)
{
	int	read_end;
	int	pipe_ends[2];

	if (pipe(pipe_ends) < 0)
		return (-1);
	read_end = 0;
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		dup2(read_end, 0);
		if (commands_nb != 1)
			dup2(pipe_ends[1], 1);
		ft_close(pipe_ends[1]);
		ft_close(pipe_ends[0]);
		input_output_redirection(commands_list);
		execute_command(commands_list, environment);
	}
	return (pid);
}

int	commands_execution(t_finallist *commands_list, t_env *environment)
{
	int	pipe_ends[2];
	int	read_end;
	int	pid;
	int	commands_nb;

	commands_nb = number_of_nodes(commands_list);
	read_end = 0;
	while (commands_nb)
	{
		pid = generate_child_p(commands_list, environment, pid, commands_nb);
		retrieve_exit_status(pid, commands_nb);
		ft_close(pipe_ends[1]);
		ft_close(read_end);
		read_end = pipe_ends[0];
		commands_list = commands_list->next;
		commands_nb--;
	}
	ft_close(read_end);
	while (wait(NULL) != -1)
		;
	return (0);
}
