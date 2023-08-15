/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:57:42 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/15 20:48:57 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	env(t_env *envir)
{
	t_env	*tmp;

	tmp = envir;
	if (g_gv.env_not_exist == 42)
	{
		while (tmp)
		{
			if (tmp->value && ft_strcmp(tmp->variable, "$PATH"))
				ft_printf(1, "%s=%s\n", tmp->variable + 1, tmp->value);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			if (tmp && tmp->value)
				ft_printf(1, "%s=%s\n", tmp->variable + 1, tmp->value);
			tmp = tmp->next;
		}
	}
	g_gv.exit_status = 0;
}
