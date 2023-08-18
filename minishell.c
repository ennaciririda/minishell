/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:15 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/18 18:45:38 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signals(int signal)
{
	if (signal == SIGINT)
	{
		g_gv.exit_status = 1;
		if (g_gv.inside_heredoc == 1)
		{
			close(0);
			return ;
		}
		if (g_gv.which_process == 0)
			return ;
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	error_case(t_list **list)
{
	if (check_errors(*list))
	{
		free_any_stack(list);
		g_gv.check_close = 0;
		g_gv.exit_status = 258;
		return (0);
	}
	return (1);
}

void	update_some_var(t_env **envir)
{
	if (!check_var_if_exist(*envir, "$OLDPWD"))
		add_back_env(envir, ft_lstnew_env(ft_strdup("$OLDPWD"), NULL));
	if (!check_var_if_exist(*envir, "$SHLVL"))
		add_back_env(envir, ft_lstnew_env(ft_strdup("$SHLVL"), ft_itoa(g_gv.shelvl)));
	if (!check_var_if_exist(*envir, "$PATH"))
		add_back_env(envir, ft_lstnew_env(ft_strdup("$PATH"), ft_strdup(_PATH_STDPATH)));
}

int	main(int argc, char **argv, char **env)
{
	t_env	*envir;

	(void)argc;
	(void)argv;
	g_gv.env_not_exist = 0;
	envir = env_fill_struct(env);
	update_some_var(&envir);
	get_shellvl_value(envir);
	update_shelllevel_value(&envir);
	g_gv.exit_status = 0;
	rl_catch_signals = 0;
	g_gv.valide_stdin = 1;
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		printf("\ncan't catch SIGQUIT\n");
	if (signal(SIGINT, &handle_signals) == SIG_ERR)
		printf("\ncan't catch SIGQUIT\n");
	g_gv.spl = NULL;
	infinit_loop(&envir);
	free_any_stack_env(&envir);
	return (0);
}
