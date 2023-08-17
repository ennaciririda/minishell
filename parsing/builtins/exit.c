/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:48:23 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/17 21:22:32 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	only_exit(void)
{
	ft_printf(1, "exit\n");
	exit(g_gv.exit_status);
}

void	normal_case(char *str)
{
	ft_printf(1, "exit\n");
	g_gv.exit_status = ft_atoi(str) % 256;
	exit(ft_atoi(str) % 256);
}

void	numeric_arg_case(char *str)
{
	ft_printf(2, "exit\nexit: %s: numeric argument required\n", str);
	g_gv.exit_status = 255;
	exit(255);
}

void	t_m_a(void)
{
	ft_printf(2, "exit\nexit: too many arguments\n");
	g_gv.exit_status = 1;
}

void	exit_cmd(char **cmd)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (cmd[j])
		j++;
	if (j == 1)
		only_exit();
	else if (j == 2 && check_arg_is_int(cmd[i]) && g_gv.for_ex_built != -1337)
	{
		if (!ft_strcmp(cmd[i], ""))
			numeric_arg_case(cmd[i]);
		else
			normal_case(cmd[i]);
	}
	else if (j >= 2)
	{
		if (j > 2 && check_arg_is_int(cmd[i]) && g_gv.for_ex_built != -1337)
			t_m_a();
		else if (!check_arg_is_int(cmd[i]) || g_gv.for_ex_built == -1337)
			numeric_arg_case(cmd[i]);
	}
}
