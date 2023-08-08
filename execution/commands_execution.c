/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:13:06 by hlabouit          #+#    #+#             */
/*   Updated: 2023/08/02 11:48:54 by hlabouit         ###   ########.fr       */
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
	int pid2;
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
		tmp_fd = pipe_ends[1];
		pid = fork();
		if (pid < 0)
		{
			printf("the fork function has failed\n");
			return ;
		}
		if (pid == 0)
		{
			if (commands_nb == fixed_cnb)
			{
				dup2(pipe_ends[1], 1);
			}
			else if (commands_nb == 1)
			{
				dup2(tmp_fd, 0);
			}
			else
			{
				dup2(tmp_fd, 0);
				dup2(pipe_ends[1], 1);
			}
			exact_path = get_exact_path(commands_list->cmd[0], env);
			execve(exact_path, commands_list->cmd, envp);
		}
		commands_list = commands_list->next;
		commands_nb--;
	}
	//need a wait pid ?!!
	//wait(null) iside a while so that the prt_p waits for all childs to terminate
}



t_finallist	*add_node(char **cmd)
{
	t_finallist	*node;

	node = NULL;
	node = malloc(sizeof(t_finallist));
	if (node == NULL)
		return (NULL);
	node->cmd = cmd;
	node->next = NULL;
	return (node);
}
t_finallist	*last_node(t_finallist *head)
{
	while (head)
	{
		if (head->next == NULL)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	add_node_in_end(t_finallist **head, t_finallist *node)
{
	if (*head == NULL)
		*head = node;
	else
		last_node(*head)->next = node;
}

t_finallist *create_list(char **av)
{
	t_finallist **head;
	
	int i = 3;
	while (i)
	{
		add_node_in_end()
	}
}
int main(int ac, char **av, char **env)
{
	// commands_execution(2, cl, env);
	// char **gph;
	// printf("%s\n", get_exact_path("", env, gph));
	// exit(0);
	return 0;
}