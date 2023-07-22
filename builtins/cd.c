/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:27:50 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/22 15:45:45 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd(t_env *envir, char **cmd)
{

	char *str;
	char *str1;
	char *s;
	char *s1;
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
					gv.ex_status = 1;
					perror("cd");
					free(s);
				}
				change_pwd(envir, str);
				free(s);
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
					gv.ex_status = 1;
					perror("cd");
				}
				s = getcwd(NULL, 0);
				change_pwd(envir, s);
				gv.ex_status = 0;
				ft_printf(1 ,"%s\n", s);
				free(s);
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
				gv.ex_status = 1;
				// free(s);
				// free(str);
				perror("cd");
			}
			s1 = getcwd(NULL, 0);
			change_pwd(envir, s1);
			free(str);
			free(s);
			free(s1);
			gv.ex_status = 0;
		}
	}
}
