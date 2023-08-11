/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:15 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/11 17:04:19 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signals(int signal)
{
	if (signal == SIGINT)
	{
		if(g_gv.which_process == 0)
			return;
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
		return 0;
	}
	return 1;
}



int main(int argc, char **argv, char **env)
{
	char	*str;

	int	*tab;
	int i = 0;
	t_list	*list;
	t_list	*flist;
	t_list	*clist;
	t_list	*elist;
	t_list	*newlist;
	t_env	*envir;
	t_globallist *finalist;
	t_finallist	*lastlist;
	t_finallist	*tmplast;
	(void)argc;
	(void)argv;
	clist = NULL;
	elist = NULL;
	list = NULL;
	finalist = NULL;
	newlist = NULL;
	lastlist = NULL;
	tmplast = NULL;
	envir = env_fill_struct(env);
	g_gv.exit_status = 0;
	rl_catch_signals = 0;
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		printf("\ncan't catch SIGQUIT\n");
	if (signal(SIGINT, &handle_signals) == SIG_ERR)
		printf("\ncan't catch SIGQUIT\n");
	g_gv.which_process = 1;

	int fds[2];
	fds[0] = dup(0);
	fds[1] = dup(1);
	while (1)
	{
		i = 0;
		str = readline("minishell$ ");
		g_gv.which_process = 0;
		if (!str)
			exit(g_gv.exit_status);
		if (ft_strcmp(str, ""))
			add_history(str);
		if (ft_strcmp(str, ""))
		{
			list = tokenizing(str);
			replace_ex(&list);
			if (!error_case(&list, str))
				continue;
			tab = ft_calloc(count_her(list), sizeof(int));
			if (!tab)
				return 0;
			g_gv.tab_count = 0;
			g_gv.rep_tab_c = 0;
			g_gv.check_fd = 0;
			g_gv.spl = fill_dilimiter(list, tab);
			elist = rep_var(list, envir);
			flist = rep_var_dq(elist, envir);
			clist = concatinated_list(flist);
			newlist = replace_redir(clist, envir, tab);
			if (g_gv.check_fd)
			{
				free_any_stack(&newlist);
				free(str);
				free_2d_tab(g_gv.spl);
				free(tab);
				continue;
			}
			finalist = final_list(newlist);
			lastlist = resume(finalist);
			commands_execution(lastlist, &envir);
			dup2(fds[0], 0);
			dup2(fds[1], 1);
			free_any_stack_final(&lastlist);
			free(str);
			free(tab);
			free_2d_tab(g_gv.spl);
			lastlist = NULL;
		}
		else
			free(str);
		g_gv.which_process = 1;
	}
	free_any_stack_env(envir);
	return 0;
}
