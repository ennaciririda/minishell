/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:15 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/15 17:25:26 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signals(int signal)
{
	if (signal == SIGINT)
	{
		g_gv.exit_status = 1;
		if (g_gv.which_process == 0)
			return ;
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	error_case(t_list **list, char *str)
{
	if (check_errors(*list))
	{
		free(str);
		free_any_stack(list);
		g_gv.check_close = 0;
		g_gv.exit_status = 258;
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_env	*envir;

	(void)argc;
	(void)argv;
	g_gv.env_not_exist = 0;
	envir = env_fill_struct(env);
	get_shellvl_value(envir);
	update_shelllevel_value(&envir);
	g_gv.exit_status = 0;
	rl_catch_signals = 0;
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		printf("\ncan't catch SIGQUIT\n");
	if (signal(SIGINT, &handle_signals) == SIG_ERR)
		printf("\ncan't catch SIGQUIT\n");
	infinit_loop(&envir);
	free_any_stack_env(&envir);
	return (0);
}
