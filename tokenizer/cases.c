/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 00:10:37 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/06 01:41:20 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	space(t_list **list ,int *i)
{
	ft_lstadd_back(list, ft_lstnew(" ", WHITE_SPACE));
	(*i)++;
}
void	pipes(t_list **list ,int *i)
{
	ft_lstadd_back(list, ft_lstnew("|", PIPE));
	(*i)++;
}
void	ared_out(t_list **list, char *str, int *i)
{
	check_dir(str, '>');
	ft_lstadd_back(list, ft_lstnew(">>", ARED_OUT));
	(*i) = (*i) + 2;
}

void	here_doc(t_list **list, char *str, int *i)
{
	check_dir(str, '<');
	ft_lstadd_back(list, ft_lstnew("<<", HER_DOC));
	(*i) = (*i) + 2;
}
void	red_out(t_list **list, int *i)
{
	ft_lstadd_back(list, ft_lstnew(">", RED_OUT));
	(*i)++;
}
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
