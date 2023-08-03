/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_old_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:28:18 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/03 17:30:38 by rennacir         ###   ########.fr       */
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
			tmp->value = ft_strdup(str);
		tmp = tmp->next;
	}
}

void	change_pwd(t_env **envir, char *str)
{
	t_env	*tmp;
	tmp = *envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, "$PWD"))
		{
			tmp->value = ft_strdup(str);
			printf("a : %p\n", tmp->value);
		}

		tmp = tmp->next;
	}
}
