/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:27:50 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/26 18:57:24 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_help(t_env **envir)
{
	char	*str;
	char	*s;

	if (check_var_if_exist(*envir, "$HOME"))
	{
		str = cd_get_env(*envir, "$HOME");
		s = getcwd(NULL, 0);
		if (chdir(str))
		{
			g_gv.ex_status = 1;
			perror("cd");
			free(s);
			return ;
		}
		change_old_pwd(envir, s);
		change_pwd(envir, str);
		free(s);
		g_gv.ex_status = 0;
	}
}

void	cd_help_1(t_env **envir)
{
	char	*str;
	char	*s;

	if (check_var_if_exist(*envir, "$OLDPWD")
		&& check_var_if_exist(*envir, "$PWD"))
	{
		str = cd_get_env(*envir, "$OLDPWD");
		if (chdir(str))
		{
			g_gv.ex_status = 1;
			perror("cd");
			return ;
		}
		change_old_pwd(envir, cd_get_env(*envir, "$PWD"));
		s = getcwd(NULL, 0);
		change_pwd(envir, s);
		g_gv.ex_status = 0;
		ft_printf(1, "%s\n", s);
		free(s);
	}
	else
	{
		write(2, "cd : OLDPWD not set\n", 20);
		g_gv.ex_status = 1;
	}
}

void	cd_help_2(t_env **envir, char *cmd)
{
	char	*str;
	char	*s;
	char	*s1;

	str = ft_strdup(cmd);
	s = getcwd(NULL, 0);
	if (chdir(str))
	{
		g_gv.ex_status = 1;
		perror("cd");
		free(s);
		return ;
	}
	change_old_pwd(envir, s);
	s1 = getcwd(NULL, 0);
	change_pwd(envir, s1);
	free(str);
	free(s);
	free(s1);
	g_gv.ex_status = 0;
}

void	cd(t_env *envir, char **cmd)
{
	int	i;

	if (cmd[0] && check_word("cd", cmd[0]))
	{
		i = 1;
		if (cmd[i] && !ft_strcmp(cmd[i], " "))
			i++;
		if (!cmd[i] || !ft_strcmp(cmd[i], "~"))
			cd_help(&envir);
		else if (!ft_strcmp(cmd[i], "-"))
			cd_help_1(&envir);
		else
			cd_help_2(&envir, cmd[i]);
	}
}
