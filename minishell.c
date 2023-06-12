/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:15 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/11 00:40:12 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *tokenizing(char *str)
{
	t_list	*list;
	int i = 0;
	while(str[i])
	{
		if (str[i] == ' ')
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

int main(int argc, char **argv, char **env)
{
	char	*str;
	// int i = 0;
	t_list	*list;
	t_list	*flist;
	t_env *node;
	node = NULL;
	t_list	*tmp;
	t_env	*envir;
	t_env	*en;
	en  =NULL;
	(void)argc;
	(void)argv;
	tmp = NULL;
	str = readline("minishell$ ");
	list = tokenizing(str);
	check_errors(list);
	envir = env_fill_struct(env);
	tmp = rep_var(list, envir);
	// rep_var_dq(&tmp, envir);
	flist = rep_var_dq(tmp, envir);

	tmp = flist;
	while (tmp)
	{
		printf("[%s]\n", tmp->content);
		tmp = tmp->next;
	}
	return 0;
}
