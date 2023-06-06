/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:02:00 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/06 22:32:56 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	red_in(t_list **list, int *i)
{
	ft_lstadd_back(list, ft_lstnew("<", RED_IN));
	(*i)++;
}

void	dollar(t_list **list, char *str, int *i)
{
	int	start = 0;
	int j = 0;
	start = *i;
	while(str[(*i) + 1] && (ft_isalnum(str[(*i) + 1]) || str[(*i) + 1] == '_'))
	{
		(*i)++;
		j++;
	}
	ft_lstadd_back(list, ft_lstnew(ft_substr(str, start, j + 1), VARIABLE));
	(*i)++;
}

void	double_quote(t_list **list, char *str, int *i)
{
	int	start = 0;
	int j = 0;
	(*i)++;
	check_is_close(str + (*i), '\"');
	start = (*i);
	j = 0;
	while(str[(*i)] && str[(*i)] != '\"')
	{
		(*i)++;
		j++;
	}
	ft_lstadd_back(list, ft_lstnew(ft_substr(str, start, j), DOUBLE_QUOTE));
	(*i)++;
}

void	single_quote(t_list **list, char *str, int *i)
{
	int	start = 0;
	int j = 0;
	(*i)++;
	check_is_close(str + (*i), '\'');
	start = (*i);
	j = 0;
	while(str[(*i)] && str[(*i)] != '\'')
	{
		(*i)++;
		j++;
	}
	ft_lstadd_back(list, ft_lstnew(ft_substr(str, start, j), SINGLE_QUOTE));
	(*i)++;
}
void	word(t_list **list, char *str, int *i)
{
	int	start;
	int	j;
	start = (*i);
	j = 0;
	while(str[(*i)] && str[(*i)] != ' ' && str[(*i)] != '|' && str[(*i)] != '>' && str[(*i)] != '<' && str[(*i)] != '\'' && str[(*i)] != '\"' && str[(*i)] != '$')
	{
		(*i)++;
		j++;
	}
	ft_lstadd_back(list, ft_lstnew(ft_substr(str, start, j), WORD));
}

void	double_dollar(t_list **list, int *i)
{
	ft_lstadd_back(list, ft_lstnew("$$", DOUBLE_DOLLAR));
	(*i) = (*i) + 2;
}
void	why_dollar(t_list **list, int *i)
{
	ft_lstadd_back(list, ft_lstnew("$?", DOLLAR_WHY));
	(*i) = (*i) + 2;
}