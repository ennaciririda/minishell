/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fill_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:01:18 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/13 13:54:47 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	env_not_exist_case(t_env **envir)
{
	add_back_env(envir, ft_lstnew_env(ft_strjoin(ft_strdup("$"),
		ft_strdup("PWD")), getcwd(NULL, 0)));
	add_back_env(envir, ft_lstnew_env(ft_strjoin(ft_strdup("$"),
		ft_strdup("SHLVL")), ft_itoa(g_gv.shelvl)));
	add_back_env(envir, ft_lstnew_env(ft_strjoin(ft_strdup("$"),
		ft_strdup("_")), ft_strdup("/usr/bin/env")));
	add_back_env(envir, ft_lstnew_env(ft_strjoin(ft_strdup("$"),
		ft_strdup("PATH")), ft_strdup("/Users/rennacir/goinfre/.brew/bin:/bin:/usr/bin:/usr/ucb:/usr/local/bin")));
}

t_env	*env_fill_struct(char **env)
{
	int		i;
	int		j;
	t_env	*envir;

	envir = NULL;
	i = 0;
	j = 0;
	if (!env[0])
	{
		g_gv.env_not_exist = 42;
		env_not_exist_case(&envir);
	}
	else
	{
		while (env[i])
		{
			j = 0;
			while (env[i][j] && env[i][j] != '=')
				j++;
			add_back_env(&envir, ft_lstnew_env(ft_strjoin(ft_strdup("$"),
						ft_substr(env[i], 0, j)), ft_strdup(env[i] + j + 1)));
			i++;
		}
	}
	return (envir);
}
