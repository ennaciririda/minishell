/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:13:06 by hlabouit          #+#    #+#             */
/*   Updated: 2023/08/09 18:06:47 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char **get_global_path(char **env)
{
	int i;
	int j;
	char **path;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			path = ft_split_E(env[i] + 5, ':');
			break;
		}
		i++;
	}
	return (path);
}

char *get_exact_path(char *command, char **env)
{
	int i;
	char **path;

	i = 0;
	command = ft_strjoin_E("/", command);
	path = get_global_path(env);
	while (path[i])
	{
		path[i] = ft_strjoin_E(path[i], command);
		if (access(path[i], X_OK) == 0)
			break;
		i++;
	}
	return (path[i]);
}

char **get_environment_variables(t_env *environment)
{
	int i;
	char **envp;

	i = 0;
	envp = malloc((number_of_nodes2(environment) + 1) * sizeof(char *));
	while (environment)
	{
		envp[i] = ft_strjoin_E(&environment->variable[1], "=");
		envp[i] = ft_strjoin_E(envp[i], environment->value);
		environment = environment->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

void ft_close(int fd)
{
	if (fd == 0 || fd == 1)
		return;
	close(fd);
}

void commands_execution(t_finallist *commands_list, t_env *environment)
{
	int red_fd;
	int pid;
	int pipe_ends[2];
	int commands_nb;
	int fixed_cnb;
	char *exact_path;
	char **envp;

	commands_nb = number_of_nodes(commands_list);
	fixed_cnb = commands_nb;
	int readEnd = 0;
	while (commands_nb)
	{
		if (pipe(pipe_ends) < 0)
			return;
		pid = fork();
		if (pid < 0)
		{
			printf("the fork function has failed\n");
			return;
		}
		if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			dup2(readEnd, 0);
			if (commands_nb != 1)
				dup2(pipe_ends[1], 1);
			ft_close(pipe_ends[1]);
			ft_close(pipe_ends[0]);
			while (commands_list->red)
			{
				if (commands_list->red->type == HER_DOC || commands_list->red->type == RED_IN)
				{
					red_fd = open(commands_list->red->content, O_RDONLY);
					dup2(red_fd, 0);
					close(red_fd);
				}
				else if (commands_list->red->type == RED_OUT)
				{
					red_fd = open(commands_list->red->content, O_CREAT | O_WRONLY | O_TRUNC, 0644);
					dup2(red_fd, 1);
					close(red_fd);
				}
				else if (commands_list->red->type == ARED_OUT)
				{
					red_fd = open(commands_list->red->content, O_CREAT | O_WRONLY | O_APPEND, 0644);
					dup2(red_fd, 1);
					close(red_fd);
				}
				commands_list->red = commands_list->red->next;
			}
			// if (commands_nb == 1)
			// {
				// waitpid
			// }
			envp = get_environment_variables(environment);
			exact_path = get_exact_path(commands_list->cmd[0], envp);
			if (execve(exact_path, commands_list->cmd, envp) == -1)
				perror("execve() function has failed");
		}
		ft_close(pipe_ends[1]);
		ft_close(readEnd);
		readEnd = pipe_ends[0];
		commands_list = commands_list->next;
		commands_nb--;
	}
	ft_close(readEnd);
	while (wait(NULL) != -1);
}
