/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:15 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/19 23:54:37 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	free_any_stack(t_list *list)
// {
// 	t_list	*node;

// 	while (list)
// 	{
// 		node = list->next;
// 		free(list);
// 		list = node;
// 	}
// }

t_list *tokenizing(char *str)
{
	t_list	*list;
	int i = 0;
	while(str[i])
	{
		if (is_white_space(str[i]))
			space(&list, str, &i);
		else if (str[i] == '|')
			pipes(&list, &i);
		else if (str[i] == '$' && str[i + 1] == '$')
			double_dollar(&list, &i);
		else if (str[i] == '$' && str[i + 1] == '?')
			why_dollar(&list, &i);
		else if (str[i] == '>' && str[i + 1] == '>')
			ared_out(&list, str, &i);
		else if (str[i] == '<' && str[i + 1] == '<')
			here_doc(&list, str, &i);
		else if (str[i] == '>')
			red_out(&list, &i);
		else if (str[i] == '<')
			red_in(&list, &i);
		else if (str[i] == '$')
			dollar(&list, str, &i);
		else if (str[i] == '\"')
			double_quote(&list, str, &i);
		else if (str[i] == '\'')
			single_quote(&list, str, &i);
		else if(str[i] != ' ' && str[i] != '|' && str[i] != '>'
		&& str[i] != '<' && str[i] != '\'' && str[i] != '\"' && str[i] != '$')
			word(&list, str, &i);
		else
			i++;
	}
	return list;
}
void func(void)
{
	system("leaks minishell");
}
int main(int argc, char **argv, char **env)
{
	char	*str;
	int i = 0;
	t_list	*list;
	t_list	*flist;
	t_list	*clist;
	t_list	*elist;
	t_list	*newlist;
	t_list	*tmp;
	t_env	*envir;
	(void)argc;
	(void)argv;
	tmp = NULL;
	clist = NULL;
	elist = NULL;
	newlist = NULL;
	str = readline("minishell$ ");
	if (ft_strcmp(str, ""))
	{
		list = tokenizing(str);
		check_errors(list);
		envir = env_fill_struct(env);
		elist = rep_var(list, envir);
		flist = rep_var_dq(elist, envir);
		clist = concatinated_list(flist);
		newlist = replace_redir(clist);
		tmp = newlist;
		while (tmp)
		{
			printf("[%s]\n", tmp->content);
			tmp = tmp->next;
		}
	}
	return 0;
}
