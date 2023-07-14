/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:27:50 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/14 16:45:59 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd(t_finallist	*lastlist, t_env *envir, char **cmd)
{

	char *str;
	int i;

	if (cmd[0] && check_word("cd", cmd[0]))
	{
		i = 1;
		if (cmd[i] && !ft_strcmp(cmd[i], " "))
			i++;
		if (!cmd[i] || !ft_strcmp(cmd[i], "~"))
		{
			str = cd_get_env(envir, "$HOME");
			chdir(str);
			change_old_pwd(envir, getcwd(NULL, 0));
		}
		else if (!ft_strcmp(cmd[i], "-"))
		{
			change_old_pwd(envir, getcwd(NULL, 0));
			str = cd_get_env(envir, "$OLDPWD");
			chdir(str);
			printf("%s\n", str);
		}
		else
		{
			str = ft_strdup(cmd[i]);
			chdir(str);
			change_old_pwd(envir, getcwd(NULL, 0));
		}
	}
}
