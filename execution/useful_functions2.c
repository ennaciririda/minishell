/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:49:13 by hlabouit          #+#    #+#             */
/*   Updated: 2023/08/16 19:41:18 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	check_if_directory(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

char	*check_start_of_path(t_finallist *commands_list)
{
	char	*exact_path;

	if (access(commands_list->cmd[0], F_OK) == -1)
	{
		ft_printf(2, "minishell: %s: command not found\n",
			commands_list->cmd[0]);
		exit(127);
	}
	else if (access(commands_list->cmd[0], X_OK) == -1)
	{
		ft_printf(2, "minishell: %s: permission denied\n",
			commands_list->cmd[0]);
		exit(126);
	}
	exact_path = commands_list->cmd[0];
	return (exact_path);
}

void	check_if_valid_path(t_finallist *commands_list, char *exact_path)
{
	if (!exact_path)
	{
		ft_printf(2, "minishell: %s: command not found\n",
			commands_list->cmd[0]);
		exit(127);
	}
	else if (check_if_directory(exact_path))
	{
		ft_printf(2, "minishell: %s: is a directory\n",
			commands_list->cmd[0]);
		exit(127);
	}
}
