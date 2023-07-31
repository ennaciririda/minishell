/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:04:58 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/26 18:56:02 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_errors(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (tmp && tmp->type == WHITE_SPACE)
		tmp = tmp->next;
	if (tmp && tmp->type == PIPE)
	{
		ft_printf(2, "synrtax error\n");
		return (1);
	}
	return (0);
}

int	redirections_errors(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (check_redir_type(tmp->type))
		{
			tmp = tmp->next;
			if (tmp && tmp->type == WHITE_SPACE)
				tmp = tmp->next;
			if (!tmp)
			{
				ft_printf(2, "Error : about redirections\n");
				return (1);
			}
			if (check_redir_type(tmp->type) || tmp->type == PIPE)
			{
				ft_printf(2, "Error : about redirections\n");
				return (1);
			}
		}
		if (tmp)
			tmp = tmp->next;
	}
	return (0);
}

int	pipe_errors(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->type == PIPE)
		{
			tmp = tmp->next;
			if (tmp && tmp->type == WHITE_SPACE)
				tmp = tmp->next;
			if (!tmp)
			{
				ft_printf(2, "Error : syntax error\n");
				return (1);
			}
			if (tmp->type == PIPE)
			{
				ft_printf(2, "Error : syntax error\n");
				return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_errors(t_list *list)
{
	if (cmd_errors(list) || redirections_errors(list)
		|| pipe_errors(list) || g_gv.check_close)
		return (1);
	return (0);
}
