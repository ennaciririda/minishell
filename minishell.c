/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:15 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/11 15:45:38 by rennacir         ###   ########.fr       */
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

void	print_str(char **str)
{
	int i = -1;
	while (str[++i])
		printf("[%s] ", str[i]);
}

t_list *tokenizing(char *str)
{
	t_list	*list;
	list = NULL;
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
		else
			word(&list, str, &i);
	}
	return list;
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
	t_list	*tmp1;
	t_env	*envir;
	t_globallist *finalist;
	t_globallist *finaltmp;
	t_finallist	*lastlist;
	t_finallist	*tmplast;
	(void)argc;
	(void)argv;
	tmp = NULL;
	tmp1 = NULL;
	clist = NULL;
	elist = NULL;
	list = NULL;
	finalist = NULL;
	newlist = NULL;
	lastlist = NULL;
	tmplast = NULL;
	while (1)
	{
		fll = 0;
	str = readline("minishell$ ");
	if (ft_strcmp(str, ""))
	{
		list = tokenizing(str);
		if (check_errors(list))
			continue;
		envir = env_fill_struct(env);
		elist = rep_var(list, envir);
		flist = rep_var_dq(elist, envir);
		clist = concatinated_list(flist);
		newlist = replace_redir(clist, envir);
		finalist = final_list(newlist);
		lastlist = resume(finalist);
		tmplast = lastlist;
		while (tmplast)
		{
			tmp1 = tmplast->red;
			printf("resiredctions\n");
			while (tmp1)
			{
				printf("[%s] ", tmp1->content);
				tmp1 = tmp1->next;
			}
			printf("\n");
			printf("double string\n");
			print_str(tmplast->cmd);
			printf("\n-----------------------------\n");
			tmplast = tmplast->next;
		}
	}
	}
	return 0;
}
