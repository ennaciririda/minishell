/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 05:06:04 by hlabouit          #+#    #+#             */
/*   Updated: 2023/08/12 00:47:15 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_close(int fd)
{
	if (fd == 0 || fd == 1)
		return ;
	close(fd);
}

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
		return (NULL);
	command = ft_strjoin_e("/", command);
	path = get_global_path(env);
	if (!path)
		return (NULL);
	while (path[i])
	{
		path[i] = ft_strjoin_e(path[i], command);
		if (access(path[i], X_OK) == 0)
			return (path[i]);
		i++;
	}
	return (NULL);
}

int	number_of_nodes(t_finallist *head)
{
	int	n;

	n = 0;
	if (head == NULL)
		return (n);
	while (head)
	{
		head = head->next;
		n++;
	}
	return (n);
}

int	number_of_nodes2(t_env *head)
{
	int	n;

	n = 0;
	if (head == NULL)
		return (n);
	while (head)
	{
		head = head->next;
		n++;
	}
	return (n);
}
