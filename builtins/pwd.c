/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:06:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/13 23:12:16 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd(t_finallist	*lastlist, t_env *envir)
{
	t_finallist *tmp;
	char **cmd;
	tmp = lastlist;
	while (tmp)
	{
		cmd = tmp->cmd;
		if (cmd[0] && !ft_strcmp(cmd[0], ))
		tmp = tmp->next;
	}
}