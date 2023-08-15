/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:25:09 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/15 18:17:12 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	tokenizing_help(t_list **list, char *str, int *i)
{
	if (str[(*i)] == '>')
		red_out(list, i);
	else if (str[(*i)] == '<')
		red_in(list, i);
	else if (str[(*i)] == '$')
		dollar(list, str, i);
	else if (str[(*i)] == '\"')
		double_quote(list, str, i);
	else if (str[(*i)] == '\'')
		single_quote(list, str, i);
	else
		word(list, str, i);
}

t_list	*tokenizing(char *str)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = 0;
	while (str[i])
	{
		if (is_white_space(str[i]))
			space(&list, str, &i);
		else if (str[i] == '|')
			pipes(&list, &i);
		else if (str[i] == '$' && (str[i + 1] == '\"' || str[i + 1] == '\''))
			i++;
		else if (str[i] == '$' && str[i + 1] == '$')
			double_dollar(&list, &i);
		else if (str[i] == '$' && str[i + 1] == '?')
			why_dollar(&list, &i);
		else if (str[i] == '>' && str[i + 1] == '>')
			ared_out(&list, str, &i);
		else if (str[i] == '<' && str[i + 1] == '<')
			here_doc(&list, str, &i);
		else
			tokenizing_help(&list, str, &i);
	}
	return (list);
}
