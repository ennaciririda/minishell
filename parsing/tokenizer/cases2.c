/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:02:00 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/15 22:33:23 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	red_in(t_list **list, int *i)
{
	add_back(list, new_tokens(ft_strdup("<"), RED_IN));
	(*i)++;
}

void	dollar(t_list **list, char *str, int *i)
{
	int	start;
	int	j;

	j = 0;
	start = *i;
	if (ft_isdigit(str[(*i) + 1]))
	{
		add_back(list, new_tokens(ft_substr(str, start, 2),
				VARIABLE));
		(*i) = (*i) + 2;
	}
	else
	{
		while (str[(*i) + 1] && (ft_isalnum(str[(*i) + 1])
				|| str[(*i) + 1] == '_'))
		{
			(*i)++;
			j++;
		}
		add_back(list, new_tokens(ft_substr(str, start, j + 1),
				VARIABLE));
		(*i)++;
	}
}

void	double_quote(t_list **list, char *str, int *i)
{
	int	start;
	int	j;

	(*i)++;
	j = 0;
	if (check_is_close(str + (*i), '\"'))
		g_gv.check_close = 1;
	start = (*i);
	j = 0;
	while (str[(*i)] && str[(*i)] != '\"')
	{
		(*i)++;
		j++;
	}
	add_back(list, new_tokens(ft_substr(str, start, j),
			DOUBLE_QUOTE));
	(*i)++;
}

void	single_quote(t_list **list, char *str, int *i)
{
	int	start;
	int	j;

	j = 0;
	(*i)++;
	if (check_is_close(str + (*i), '\''))
		g_gv.check_close = 1;
	start = (*i);
	j = 0;
	while (str[(*i)] && str[(*i)] != '\'')
	{
		(*i)++;
		j++;
	}
	add_back(list, new_tokens(ft_substr(str, start, j),
			SINGLE_QUOTE));
	(*i)++;
}

void	word(t_list **list, char *str, int *i)
{
	int	start;

	start = (*i);
	while (str[(*i)] && !is_white_space(str[(*i)]) && str[(*i)] != '|'
		&& str[(*i)] != '>' && str[(*i)] != '<'
		&& str[(*i)] != '\'' && str[(*i)] != '\"' && str[(*i)] != '$')
		(*i)++;
	add_back(list, new_tokens(ft_substr(str, start, (*i) - start),
			WORD));
}
