/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 00:10:37 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/06 15:31:14 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	space(t_list **list, char *str,int *i)
{

	while(str[(*i)] && str[(*i)] == ' ')
		(*i)++;
	ft_lstadd_back(list, ft_lstnew(" ", WHITE_SPACE));
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

