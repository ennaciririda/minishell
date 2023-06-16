/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:04:58 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/14 13:34:03 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_errors(t_list *list)
{
	t_list *tmp;

	tmp = list;
	if (tmp->next && tmp->type == WHITE_SPACE)
		tmp = tmp->next;
	if (tmp->type == PIPE)
		error("synrtax error");
}

void	redirections_errors(t_list *list)
{
	t_list *tmp;

	tmp = list;

	while (tmp)
	{
		if (tmp->type == RED_OUT || tmp->type == ARED_OUT || tmp->type == RED_IN || tmp->type == HER_DOC)
		{
			if (tmp->next)
				tmp = tmp->next;
			if (tmp->next && tmp->type == WHITE_SPACE)
				tmp = tmp->next;
			if (tmp->type != WORD && tmp->type != VARIABLE
			&& tmp->type != DOUBLE_QUOTE && tmp->type != SINGLE_QUOTE
			&& tmp->type != DOUBLE_DOLLAR && tmp->type != DOLLAR_WHY)
				error("Error : about redirections");
		}
		tmp = tmp->next;
	}
}

void	pipe_errors(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->type == PIPE && tmp->next)
		{
			if (tmp->next && tmp->next->type == WHITE_SPACE)
				tmp = tmp->next;
			if (!tmp->next || tmp->next->type == PIPE)
				error ("syntax error");
		}
		tmp = tmp->next;
	}
}

void	check_errors(t_list *list)
{
	cmd_errors(list);
	redirections_errors(list);
	pipe_errors(list);
}