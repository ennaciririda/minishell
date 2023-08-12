/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:54:14 by hlabouit          #+#    #+#             */
/*   Updated: 2023/08/12 00:54:51 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_file(t_list *commands_list, int flag)
{
	int	red_fd;

	red_fd = 0;
	if (flag == 0)
		red_fd = open(commands_list->content, O_RDONLY);
	else if (flag == 5)
		red_fd = open(commands_list->content,
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (flag == 6)
		red_fd = open(commands_list->content,
				O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (red_fd < 0)
		return (-1);
	if (flag == 0)
		dup2(red_fd, 0);
	else
		dup2(red_fd, 1);
	ft_close(red_fd);
	return (0);
}

int	input_output_redirection(t_finallist *commands_list)
{
	t_list	*tmp;

	tmp = commands_list->red;
	while (tmp)
	{
		if (tmp->type == HER_DOC
			|| tmp->type == RED_IN)
		{
			if (open_file(tmp, 0) < 0)
				return (-1);
		}
		else if (tmp->type == RED_OUT)
		{
			if (open_file(tmp, 5) < 0)
				return (-1);
		}
		else if (tmp->type == ARED_OUT)
		{
			if (open_file(tmp, 6) < 0)
				return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}
