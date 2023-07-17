/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:27:50 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/17 16:34:59 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd(t_env *envir, char **cmd)
{

	char *str;
	char *str1;
	int i;

	if (cmd[0] && check_word("cd", cmd[0]))
	{
		i = 1;
		if (cmd[i] && !ft_strcmp(cmd[i], " "))
			i++;
		if (!cmd[i] || !ft_strcmp(cmd[i], "~"))
		{
			if (check_var_if_exist(envir, "$HOME"))
			{
				str = cd_get_env(envir, "$HOME");
				change_old_pwd(envir, getcwd(NULL, 0));
				chdir(str);
				change_pwd(envir, str);
			}
		}
		else if (!ft_strcmp(cmd[i], "-"))
		{
			if (check_var_if_exist(envir, "$OLDPWD") && check_var_if_exist(envir, "$PWD"))
			{
				str = cd_get_env(envir, "$OLDPWD");
				change_old_pwd(envir, cd_get_env(envir, "$PWD"));
				if (chdir(str))
					perror("cd");
				change_pwd(envir, getcwd(NULL, 0));
				printf("%s\n", getcwd(NULL, 0));
			}
			else
				write(2,"cd : OLDPWD not set\n",20);
		}
		else
		{
			str = ft_strdup(cmd[i]);
			change_old_pwd(envir, getcwd(NULL, 0));
			if (chdir(str))
					perror("cd");
			change_pwd(envir, getcwd(NULL, 0));
		}
	}
}
