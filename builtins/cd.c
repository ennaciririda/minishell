/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:27:50 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/15 14:42:15 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd(t_finallist	*lastlist, t_env *envir, char **cmd)
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
			else
				write(2,"cd : HOME not set\n",18);
		}
		else if (!ft_strcmp(cmd[i], "-"))
		{
			if (check_var_if_exist(envir, "$OLDPWD") && check_var_if_exist(envir, "$PWD"))
			{
				str = cd_get_env(envir, "$OLDPWD");
				puts(str);
				change_old_pwd(envir, cd_get_env(envir, "$PWD"));
				chdir(str);
				char me[FILENAME_MAX];
				printf("%s\n", getcwd(me, 0));
				change_pwd(envir,me);
			}
			else
				write(2,"cd : OLDPWD not set\n",20);
		}
		else
		{
			str = ft_strdup(cmd[i]);
			change_old_pwd(envir, getcwd(NULL, 0));
			chdir(str);
		}
	}
}
