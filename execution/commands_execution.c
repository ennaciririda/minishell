/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:13:06 by hlabouit          #+#    #+#             */
/*   Updated: 2023/08/10 22:38:24 by hlabouit         ###   ########.fr       */
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
	path = NULL;
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
	if (command[0] == '\0')
		return NULL;
	command = ft_strjoin_e("/", command);
	path = get_global_path(env);
	if (!path)
		return NULL;
	while (path[i])
	{
		path[i] = ft_strjoin_e(path[i], command);
		if (access(path[i], X_OK) == 0)
			return path[i];
		i++;
	}
	
	return NULL;
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

	red_fd = 0;
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
	t_finallist *tmp = commands_list;
	while (tmp->red)
	{
		if (tmp->red->type == HER_DOC
			|| tmp->red->type == RED_IN)
		{
			if (open_file(tmp, 0) < 0)
				return -1;
		}
	
		else if (tmp->red->type == RED_OUT)
		{
			if (open_file(tmp, 5) < 0)
				return -1;
		}
		else if (tmp->red->type == ARED_OUT)
		{
			if (open_file(tmp, 6) < 0)
				return -1;			
		}
		tmp->red = tmp->red->next;
	}
	return (0);
}
int is_directory(const char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}
int	execute_command(t_finallist *commands_list, t_env *environment)
{
	char	*exact_path;
	char	**envp;
	exact_path = NULL;
	envp = get_environment_variables(environment);

	if (ft_strncmp(commands_list->cmd[0], "./", 2) == 0 || ft_strncmp(commands_list->cmd[0], "/", 1) == 0)
	{
		if (access(commands_list->cmd[0], F_OK) == -1)
		{
			ft_printf(2, "minishell: %s: command not found\n",
			commands_list->cmd[0]);
			exit(127);
		}
		if (access(commands_list->cmd[0], X_OK) == -1)
		{
			ft_printf(2, "minishell: %s: permission denied\n",
			commands_list->cmd[0]);
			exit(126);
		}
		exact_path = commands_list->cmd[0];
	}
	else
		exact_path = get_exact_path(commands_list->cmd[0], envp);
	if (!exact_path)
	{	
		ft_printf(2, "minishell: %s: command not found\n",
			commands_list->cmd[0]);
		exit(127);
	}
	if (is_directory(exact_path))
	{
		ft_printf(2, "minishell: %s: is a directory\n",
		commands_list->cmd[0]);
		exit(127);
	}

	if (execve(exact_path, commands_list->cmd, envp) == -1)
	{
		perror("minishell");
		exit(127);
	}
	return (0);
}

int	generate_child_p(t_finallist *commands_list, t_env *environment,
	int pid, int commands_nb, int *pipe_ends, int read_end)
{
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
		if (input_output_redirection(commands_list) < 0)
		{
			ft_printf(2, "minishell: permission denied\n");
			exit(1);
		}
		if (check_builtins(commands_list->cmd[0]) == 0)
		{
			commands(commands_list->cmd, &environment);
			exit(g_gv.exit_status);
		}
		else
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
	if (commands_nb == 1 && check_builtins(commands_list->cmd[0]) == 0)
	{
		if (input_output_redirection(commands_list) < 0)
		{
			ft_printf(2, "minishell: permission denied\n");
			g_gv.exit_status = 1;
			return -1;
		}
		commands(commands_list->cmd, &environment);
		return 0;
	}
	read_end = 0;
	while (commands_nb)
	{
		pipe(pipe_ends);
		pid = generate_child_p(commands_list, environment, pid, commands_nb, pipe_ends, read_end);
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
