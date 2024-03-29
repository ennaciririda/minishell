/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:04:40 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/15 23:51:48 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_gv(t_list *list, int *tab)
{
	g_gv.tab_count = 0;
	g_gv.rep_tab_c = 0;
	g_gv.check_fd = 0;
	g_gv.spl = fill_dilimiter(list, tab);
}

t_list	*linked_lists(t_list *list, t_env **envir)
{
	t_list			*flist;
	t_list			*clist;
	t_list			*elist;
	t_list			*newlist;
	int				*tab;

	tab = ft_calloc(count_her(list), sizeof(int));
	if (!tab)
		return (0);
	fill_gv(list, tab);
	elist = rep_var(list, *envir);
	flist = rep_var_dq(elist, *envir);
	clist = concatinated_list(flist);
	newlist = replace_redir(clist, *envir, tab);
	if (g_gv.check_fd)
	{
		free_any_stack(&newlist);
		free(tab);
		return (NULL);
	}
	free(tab);
	return (newlist);
}

int	main_help(char *str, t_env **envir, int fds[2])
{
	t_list			*list;
	t_list			*newlist;
	t_globallist	*finalist;
	t_finallist		*lastlist;

	list = tokenizing(str);
	replace_ex(&list);
	if (!error_case(&list))
		return (0);
	newlist = linked_lists(list, envir);
	if (!newlist)
		return (0);
	finalist = final_list(newlist);
	lastlist = resume(finalist);
	if (g_gv.valide_stdin == 0)
	{
		dup2(fds[0], 0);
		g_gv.inside_heredoc = 0;
		g_gv.valide_stdin = 1;
	}
	else
		commands_execution(lastlist, envir);
	free_any_stack_final(&lastlist);
	lastlist = NULL;
	return (1);
}

void	about_str(char *str)
{
	if (!str)
		exit(g_gv.exit_status);
	if (ft_strcmp(str, ""))
		add_history(str);
}

void	infinit_loop(t_env **envir)
{
	int		fds[2];
	char	*str;

	fds[0] = dup(0);
	fds[1] = dup(1);
	str = NULL;
	g_gv.which_process = 1;
	while (1)
	{
		free_2d_tab(g_gv.spl);
		g_gv.spl = NULL;
		free(str);
		str = readline("minishell$ ");
		g_gv.which_process = 0;
		about_str(str);
		if (ft_strcmp(str, ""))
		{
			if (!main_help(str, envir, fds))
				continue ;
			dup2(fds[0], 0);
			dup2(fds[1], 1);
		}
		g_gv.which_process = 1;
	}
}
