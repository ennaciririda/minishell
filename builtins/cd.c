/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:27:50 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/20 17:37:06 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd(t_env *envir, char **cmd)
{

	char *str;
	char *str1;
	char *s;
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
				s = getcwd(NULL, 0);
				change_old_pwd(envir, s);
				if (chdir(str))
				{
					perror("cd");
					free(s);
					gv.ex_status = 1;
				}
				change_pwd(envir, ft_strdup(str));
				gv.ex_status = 0;
			}
		}
		else if (!ft_strcmp(cmd[i], "-"))
		{
			if (check_var_if_exist(envir, "$OLDPWD") && check_var_if_exist(envir, "$PWD"))
			{
				str = cd_get_env(envir, "$OLDPWD");
				change_old_pwd(envir, cd_get_env(envir, "$PWD"));
				if (chdir(str))
				{
					perror("cd");
					gv.ex_status = 1;
				}
				change_pwd(envir, getcwd(NULL, 0));
				gv.ex_status = 0;
				printf("%s\n", getcwd(NULL, 0));
			}
			else
			{
				write(2,"cd : OLDPWD not set\n",20);
				gv.ex_status = 1;
			}
		}
		else
		{
			str = ft_strdup(cmd[i]);
			s = getcwd(NULL, 0);
			change_old_pwd(envir, s);
			if (chdir(str))
			{
				perror("cd");
				free(s);
				gv.ex_status = 1;
			}
			change_pwd(envir, getcwd(NULL, 0));
			gv.ex_status = 0;
		}
	}
}
