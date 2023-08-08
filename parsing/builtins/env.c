/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:57:42 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/07 23:00:21 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(t_env *envir)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (tmp->value)
			ft_printf(1, "%s=%s\n", tmp->variable + 1, tmp->value);
		tmp = tmp->next;
	}
	g_gv.ex_status = 0;
}
