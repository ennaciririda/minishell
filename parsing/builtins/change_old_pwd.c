/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_old_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:28:18 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/15 23:07:44 by rennacir         ###   ########.fr       */
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

char	*return_var_env(t_env *envir, char *str)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, str))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
