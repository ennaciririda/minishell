/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:50:52 by hlabouit          #+#    #+#             */
/*   Updated: 2023/08/12 00:58:33 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	retrieve_exit_status(int pid, int commands_nb)
{
	if (commands_nb == 1)
	{
		waitpid(pid, &g_gv.exit_status, 0);
		if (WIFEXITED(g_gv.exit_status))
			g_gv.exit_status = WEXITSTATUS(g_gv.exit_status);
		if (WIFSIGNALED(g_gv.exit_status))
		{
			g_gv.sig_exit_status = 128 + WTERMSIG(g_gv.exit_status);
			if (g_gv.sig_exit_status == 130)
				printf("\n");
			else if (g_gv.sig_exit_status == 131)
				printf("Quit: 3\n");
			else if (g_gv.sig_exit_status == 139)
				printf("segmentation fault\n");
		}
		return (g_gv.exit_status + g_gv.sig_exit_status);
	}
	return (-1);
}
