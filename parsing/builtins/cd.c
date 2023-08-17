/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:27:50 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/17 15:08:38 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
			g_gv.exit_status = 1;
			perror("cd");
			free(s);
			return ;
		}
		change_old_pwd(envir, s);
		change_pwd(envir, str);
		free(s);
		g_gv.exit_status = 0;
	}
	else
	{
		ft_printf(2, "cd: HOME not set\n");
		g_gv.exit_status = 1;
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
			g_gv.exit_status = 1;
			perror("cd");
			return ;
		}
		change_old_pwd(envir, cd_get_env(*envir, "$PWD"));
		s = getcwd(NULL, 0);
		change_pwd(envir, s);
		g_gv.exit_status = 0;
		ft_printf(1, "%s\n", s);
		free(s);
	}
	else
	{
		ft_printf(2, "cd : OLDPWD not set\n");
		g_gv.exit_status = 1;
	}
}

void	cd_help_2(t_env **envir, char *cmd)
{
	char	*str;
	char	*s;
	char	*s1;

	str = ft_strdup(cmd);
	s = getcwd(NULL, 0);
	if (chdir(str) == -1)
	{
		g_gv.exit_status = 1;
		perror("cd");
		free(s);
		free(str);
		return ;
	}
	change_old_pwd(envir, s);
	s1 = getcwd(NULL, 0);
	change_pwd(envir, s1);
	free(str);
	free(s);
	free(s1);
	g_gv.exit_status = 0;
}

void	cd_help_3(t_env **envir, char *cmd)
{
	char	s[1024];
	char	s1[1024];
	char	pwd[1024];

	getcwd(s, 1024);
	if (chdir(cmd) == -1 || getcwd(pwd, 1024) == NULL)
	{
		getcwd(s1, 1024);
		ft_printf(2, "cd: error retrieving current : getcwd: cannot\
access parent directories\n");
		g_gv.exit_status = 0;
		change_pwd(envir, s1);
		change_old_pwd(envir, s);
	}
	else
	{
		getcwd(s1, 1024);
		change_old_pwd(envir, s);
		change_pwd(envir, s1);
		g_gv.exit_status = 0;
	}
}

void	cd(t_env *envir, char **cmd)
{
	int	i;

	if (cmd[0] && check_word("cd", cmd[0]))
	{
		i = 1;
		if (!cmd[i] || !ft_strcmp(cmd[i], "~"))
			cd_help(&envir);
		else if (!ft_strcmp(cmd[i], "-"))
			cd_help_1(&envir);
		else if (!ft_strcmp(cmd[i], "..") || !ft_strcmp(cmd[i], "."))
			cd_help_3(&envir, cmd[i]);
		else
			cd_help_2(&envir, cmd[i]);
	}
}
