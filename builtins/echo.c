/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:52:29 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/14 08:27:14 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_str(char **str)
{
	int i = -1;
	while (str[++i])
		printf("[%s] ", str[i]);
}

void	echo(t_finallist	*lastlist)
{
	t_finallist *node;
	char **cmd;
	int i;
	node = ft_lstlast_resume(lastlist);
	cmd = node->cmd;
	if (cmd[0] && check_word("echo", cmd[0]))
	{
		i = 1;
		if (cmd[i] && !ft_strcmp(cmd[i], " "))
			i++;
		if (cmd[i] && check_moins_n_case(cmd[i]))
		{
			while (cmd[i] && (check_moins_n_case(cmd[i]) || !ft_strcmp(cmd[i], " ")))
				i++;
			while (cmd[i])
				printf("%s", cmd[i++]);
		}
		else
		{
			i = 1;
			if (cmd[i] && !ft_strcmp(cmd[i], " "))
				i++;
			while (cmd[i])
				printf("%s", cmd[i++]);
			printf("\n");
		}
	}
}
