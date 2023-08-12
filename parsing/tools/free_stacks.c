/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:13:47 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/11 21:41:29 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_2d_tab(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}

void	free_any_stack(t_list **list)
{
	t_list	*node;

	while (*list)
	{
		node = (*list)->next;
		free((*list)->content);
		free(*list);
		(*list) = node;
	}
}

void	free_any_stack_global(t_globallist **list)
{
	t_globallist	*node;

	while ((*list))
	{
		node = (*list)->next;
		free_any_stack(&((*list)->cmd));
		free((*list));
		(*list) = node;
	}
}

void	free_any_stack_final(t_finallist **list)
{
	t_finallist	*node;

	while ((*list))
	{
		node = (*list)->next;
		free_any_stack(&((*list)->red));
		free_2d_tab((*list)->cmd);
		(*list)->cmd = NULL;
		free((*list));
		(*list) = node;
	}
	list = NULL;
}

void	free_any_stack_env(t_env **list)
{
	t_env	*node;

	while ((*list))
	{
		node = (*list)->next;
		if ((*list)->variable)
			free((*list)->variable);
		if ((*list)->value)
			free((*list)->value);
		free((*list));
		(*list) = node;
	}
}
