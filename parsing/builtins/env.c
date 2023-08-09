/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:57:42 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/09 17:05:11 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(t_env *envir)
{
	t_env	*tmp;
	char	*str;

	tmp = envir;
	while (tmp)
	{
		if (tmp->value)
			ft_printf(1, "%s=%s\n", tmp->variable + 1, tmp->value);
		tmp = tmp->next;
	}
	g_gv.exit_status = 0;
}
