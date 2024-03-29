/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:52:29 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/10 18:58:50 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("[%s]\n", str[i]);
}

void	echo_help(char **cmd)
{
	int	i;

	i = 1;
	if (cmd[i] && !ft_strcmp(cmd[i], " "))
		i++;
	while (cmd[i])
	{
		ft_printf(1, "%s", cmd[i]);
		if (cmd[i + 1])
			ft_printf(1, " ");
		i++;
	}
	ft_printf(1, "\n");
	g_gv.exit_status = 0;
}

void	echo(char **cmd)
{
	int	i;

	if (cmd[0] && check_word("echo", cmd[0]))
	{
		i = 1;
		if (cmd[i] && !ft_strcmp(cmd[i], " "))
			i++;
		if (cmd[i] && check_moins_n_case(cmd[i]))
		{
			while (cmd[i] && (check_moins_n_case(cmd[i])
					|| !ft_strcmp(cmd[i], " ")))
				i++;
			while (cmd[i])
				ft_printf(1, "%s", cmd[i++]);
			g_gv.exit_status = 0;
		}
		else
			echo_help(cmd);
	}
}
