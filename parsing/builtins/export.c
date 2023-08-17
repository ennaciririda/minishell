/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:59:08 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/17 23:44:57 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	only_export_case(t_env **envir)
{
	t_env	*tmp;
	t_env	*buf;
	t_env	*tmpnext;
	tmp = *envir;
	while (tmp && tmp->next)
	{
		tmpnext = tmp->next;
		while (tmpnext)
		{
			if (tmpnext->variable[1] < tmp->variable[1])
				buf = tmpnext;
			tmpnext = tmpnext->next;
		}
		if (buf && !buf->value)
			ft_printf(1, "declare -x %s\n", buf->variable + 1);
		else if (buf)
			ft_printf(1, "declare -x %s=\"%s\"\n", buf->variable + 1, buf->value);
		tmp = tmp->next;
	}
	g_gv.exit_status = 0;
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
		g_gv.exit_status = 1;
	}
}

void	empty_cmd(void)
{
	ft_printf(2, "export: `': not a valid identifier\n");
	g_gv.exit_status = 1;
}

int	export_while(char *cmdi, t_env **envir, int *i)
{
	if (cmdi && !ft_strcmp(cmdi, " "))
		(*i)++;
	if (cmdi && !ft_strcmp(cmdi, ""))
		empty_cmd();
	else if (cmdi && ft_strstr(cmdi, "+=")
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
