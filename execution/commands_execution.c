/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:13:06 by hlabouit          #+#    #+#             */
/*   Updated: 2023/07/31 15:52:01 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char	**get_global_path(char **env)
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
			path = ft_split(env[i] + 5, ':');
			break;
		}
		i++;
	}
	return(path);
}

char	*get_exact_path(char *command, char **env)
{
	int		i;
	char	**path;

	i = 0;
	command = ft_strjoin("/", command);
	path = get_global_path(env);
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], command);
		if (access(path[i], X_OK) == 0)
			break;
		i++;
	}
	return (path[i]);
}

void	commands_execution(t_finallist *commands_list, char **env)
{
	int pid;
	int pipe_ends[2];
	int tmp_fd;
	int commands_nb;
	int fixed_cnb;
	char *exact_path;
	char *envp[] = {NULL};

	commands_nb = number_of_nodes(commands_list);
	fixed_cnb = commands_nb;
	while (commands_nb)
	{
		if (pipe(pipe_ends) < 0)
			return ;
		pid = fork();
		if (pid < 0)
		{
			printf("ERROR - 404");
			return ;
		}
		if (pid == 0)
		{
			if (commands_nb == fixed_cnb)
			{
				close(pipe_ends[0]);
				dup2(pipe_ends[1], 1);
			}
			else if (commands_nb == 1)
			{
				close(pipe_ends[1]);
				dup2(pipe_ends[0], 0);	
			}
			else
			{
				dup2(tmp_fd, 0);
				dup2(pipe_ends[1], 1);
			}
			exact_path = get_exact_path(commands_list->cmd[0], env);
			execve(exact_path, commands_list->cmd, envp);
		}
		close(pipe_ends);
		commands_list = commands_list->next;
		commands_nb--;
	}
	//need a wait pid ?!!
	//wait(null) iside a while so that the prt_p waits for all childs to terminate
}




int main(int ac, char **av, char **env)
{
	// commands_execution(2, cl, env);
	// char **gph;
	// printf("%s\n", get_exact_path("", env, gph));
	// exit(0);
	return 0;
}