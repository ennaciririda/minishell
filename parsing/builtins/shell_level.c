/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:53:46 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/15 22:39:21 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

long long	get_shellvl(t_env *envir)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, "$SHLVL"))
			return (ft_atoi(tmp->value));
		tmp = tmp->next;
	}
	return (0);
}

void	get_shellvl_value(t_env *envir)
{
	long long	shelllvl;
	char		*s;

	shelllvl = get_shellvl(envir);
	if (shelllvl > 999)
	{
		s = ft_itoa(shelllvl);
		ft_printf(2,
			"minishell: warning: shell level (%d) too high, resetting to 1\n",
			(int)ft_atoi(s) + 1);
		g_gv.shelvl = 1;
		free(s);
	}
	else if (shelllvl < 0)
		g_gv.shelvl = 0;
	else
		g_gv.shelvl = shelllvl + 1;
}

void	update_shelllevel_value(t_env **envir)
{
	t_env	*tmp;
	char	*s;

	tmp = *envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, "$SHLVL"))
		{
			s = tmp->value;
			tmp->value = ft_itoa(g_gv.shelvl);
			free(s);
			break ;
		}
		tmp = tmp->next;
	}
}
