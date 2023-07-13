/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_return_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:28:47 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/12 21:26:48 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


t_env	*heredoc_return_node(char *str, t_env *envir)
{
	t_env *tmp;

	tmp = envir;
	while (tmp)
	{
		if(!ft_strcmp(tmp->variable, str))
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}