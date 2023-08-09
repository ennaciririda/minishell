/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 00:10:37 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/08 23:01:38 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	space(t_list **list, char *str, int *i)
{
	while (str[(*i)] && is_white_space(str[(*i)]))
		(*i)++;
	add_back(list, new_tokens(ft_strdup(" "), WHITE_SPACE));
}

void	pipes(t_list **list, int *i)
{
	add_back(list, new_tokens(ft_strdup("|"), PIPE));
	(*i)++;
}

void	ared_out(t_list **list, char *str, int *i)
{
	check_dir(str, '>');
	add_back(list, new_tokens(ft_strdup(">>"), ARED_OUT));
	(*i) = (*i) + 2;
}

void	here_doc(t_list **list, char *str, int *i)
{
	check_dir(str, '<');
	add_back(list, new_tokens(ft_strdup("<<"), HER_DOC));
	*i += 2;
}

void	red_out(t_list **list, int *i)
{
	add_back(list, new_tokens(ft_strdup(">"), RED_OUT));
	(*i)++;
}
