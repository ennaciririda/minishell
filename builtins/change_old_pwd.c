/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_old_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:28:18 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/31 17:26:27 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_old_pwd(t_env **envir, char *str)
{
	t_env	*tmp;
	tmp = *envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, "$OLDPWD"))
			tmp->value = str;
		tmp = tmp->next;
	}
}

void	change_pwd(t_env **envir, char *str)
{
	t_env	*tmp;
	puts("pwd");
	tmp = *envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, "$PWD"))
			tmp->value = str;
		tmp = tmp->next;
	}
}
