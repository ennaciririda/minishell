/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:59:08 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/07 16:14:23 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	only_export_case(t_env **envir)
{
	t_env	*tmp;

	tmp = *envir;
	while (tmp)
	{
		if (!tmp->value)
			ft_printf(1, "declare -x %s\n", tmp->variable + 1);
		else
			ft_printf(1, "declare -x %s=\"%s\"\n", tmp->variable + 1, tmp->value);
		tmp = tmp->next;
	}
	g_gv.ex_status = 0;
}

void	export_append_case(t_env **envir, char *str)
{
	int		i;
	int		end;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '+')
		i++;
	end = i;
	i++;
	if (str[i] == '=')
	{
		s = ft_substr(str, 0, end);
		if (!export_append_case_help(s, str, envir, i))
			return ;
		free(s);
	}
	else
	{
		ft_printf(2, "export : \'%s\' not a valid identifier\n", str);
		g_gv.ex_status = 1;
	}
}

int	export_while(char *cmdi, t_env **envir, int *i)
{
	if (cmdi && !ft_strcmp(cmdi, " "))
		(*i)++;
	if (cmdi && ft_strstr(cmdi, "+=")
		&& get_pos(cmdi, '+') < get_pos(cmdi, '='))
		export_append_case(envir, cmdi);
	else if (cmdi && ft_strchr(cmdi, '='))
	{
		if (!equal_exists(cmdi, envir))
		{
			(*i)++;
			return (0);
		}
	}
	else
	{
		if (!equal_not_exist(cmdi, envir))
		{
			(*i)++;
			return (0);
		}
	}
	return (1);
}

void	export(t_env **envir, char **cmd)
{
	int	i;

	i = 1;
	if (!cmd[i])
		only_export_case(envir);
	while (cmd[i])
	{
		if (!export_while(cmd[i], envir, &i))
			continue ;
		i++;
	}
}
