/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:27:50 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/14 15:01:24 by rennacir         ###   ########.fr       */
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
			str = cd_get_env(envir, "$HOME");
		// else if (!ft_strcmp(cmd[i], "-"))
		// 	str = cd_get_env(envir, "$OLDPWD");
		else
			str = ft_strdup(cmd[i]);
		chdir(str);
	}

}

login to session : login : "exam"  , password : "exam"
register for exam : "examshell"
then follow the instructions.
you will get 3 directories :
	* rendu : where you gonna put your code (after finishing the code go back to rendu and (git add * , git commit -m "comment" , git push))
	* subject : for the subject of the exercices
	* traces : in case you get a failure grade, just check the traces to undestand
after pushing the code go to terminal where you typed examshell and put "grademe" and wait for the result or moulinette
its better if you leave a terminal just for "examshell" and "grademe"
