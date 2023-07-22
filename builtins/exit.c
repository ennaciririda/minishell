/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:48:23 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/22 14:11:58 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_arg_is_int(char *str)
{
	int i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return 0;
	return 1;
}

void	only_exit()
{
		ft_printf(1, "exit\n");
		gv.ex_status = 0;
		exit(0);
}

void exit_cmd(char **cmd)
{
	int i = 1;
	int j = 0;
	if (cmd[i] && !ft_strcmp(cmd[i], " "))
		i++;
	while (cmd[j])
		j++;
	if (j == 1 || j == 2)
		only_exit();
	else if (j > 3 && check_arg_is_int(cmd[i]))
	{
		ft_printf(2, "exit\nexit: too many arguments\n");
		gv.ex_status = 1;
	}
	else if (!check_arg_is_int(cmd[i]) || ft_atoi(cmd[i]) > LLONG_MAX)
	{
		ft_printf(2, "exit\nexit: %s: numeric argument required\n", cmd[i]);
		gv.ex_status = 255;
		exit(255);
	}
	else if (j == 3 && check_arg_is_int(cmd[i]))
	{
		ft_printf(1, "exit\n");
		gv.ex_status = ft_atoi(cmd[i]);
		exit(ft_atoi(cmd[i]) % 256);
	}
}
