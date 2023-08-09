/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:34:34 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/09 22:11:15 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	export_check_var(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (0);
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		else
			return (0);
	}
	return (1);
}

void	update_var(t_env **envir, char *variable, char *value)
{
	t_env	*tmp;
	char	*tmpr;

	tmp = *envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, variable))
		{
			tmpr = tmp->value;
			tmp->value = value;
			free(tmpr);
			break ;
		}
		tmp = tmp->next;
	}
	g_gv.exit_status = 0;
}

void	update_var_append_case(t_env **envir, char *sub, char *value)
{
	t_env	*tmp;
	char	*s;

	tmp = *envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, sub))
		{
			s = tmp->value;
			tmp->value = ft_strjoin(ft_strdup(tmp->value), ft_strdup(value));
			free(s);
			break ;
		}
		tmp = tmp->next;
	}
	free(sub);
	g_gv.exit_status = 0;
}
