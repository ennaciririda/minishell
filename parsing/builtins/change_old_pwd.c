/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_old_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:28:18 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/08 22:58:50 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	change_old_pwd(t_env **envir, char *str)
{
	t_env	*tmp;
	char	*s;

	tmp = *envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, "$OLDPWD"))
		{
			s = tmp->value;
			tmp->value = ft_strdup(str);
			free(s);
			break ;
		}
		tmp = tmp->next;
	}
}

void	change_pwd(t_env **envir, char *str)
{
	t_env	*tmp;
	char	*s;

	tmp = *envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, "$PWD"))
		{
			s = tmp->value;
			tmp->value = ft_strdup(str);
			free(s);
			break ;
		}
		tmp = tmp->next;
	}
}
