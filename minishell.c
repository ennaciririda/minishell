/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:15 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/06 01:15:27 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *tokenizing(char *str)
{
	t_list	*list;
	int i = 0;
	int j = 0;
	int start;
	while(str[i])
	{
		if (str[i] == ' ')
			space(list, &i);
		else if (str[i] == '|')
			pipes(list, &i);
		else if (str[i] == '>' && str[i + 1] == '>')
			ared_out(list, str, &i);
		else if (str[i] == '<' && str[i + 1] == '<')
			here_doc(list, str, &i);
		else if (str[i] == '>' && str[i + 1] != '>')
			red_out(list, &i);
		else if (str[i] == '<')
			red_in(list, &i);
		else if (str[i] == '$')
			dollar(list, str, &i);
		else if (str[i] == '\"')
			double_quote(list, str, &i);
		else if (str[i] == '\'')
			single_quote(list, str, &i);
		else if(str[i] != ' ' && str[i] != '|' && str[i] != '>' && str[i] != '<' && str[i] != '\'' && str[i] != '\"' && str[i] != '$')
		{
			start = i;
			j = 0;
			while(str[i] && str[i] != ' ' && str[i] != '|' && str[i] != '>' && str[i] != '<' && str[i] != '\'' && str[i] != '\"' && str[i] != '$')
			{
				i++;
				j++;
			}
			ft_lstadd_back(&list, ft_lstnew(ft_substr(str, start, j), WORD));
			// word(list, str, &i);
		}
		else
			i++;
	}
	return list;
}

int main()
{
	char *str;
	t_list *list;
	t_list *tmp;
	// int i = 0;
	str = readline("minishell$ ");
	list = tokenizing(str);
	tmp = list;
	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	return 0;
}