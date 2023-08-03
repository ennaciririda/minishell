/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:59:08 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/03 15:31:37 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	only_export_case(t_env **envir)
{
	t_env *tmp;
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

void	update_var(t_env **envir, char *variable, char *value)
{
	t_env	*tmp;
	char	*s;

	tmp = *envir;
	s = ft_strdup(value);
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, variable))
			tmp->value = s;
		tmp = tmp->next;
	}
	g_gv.ex_status = 0;
}

void	update_var_append_case(t_env **envir, char *sub, char *value)
{
	t_env *tmp;
	char *s;

	tmp = *envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, sub))
		{
			s = ft_strjoin(ft_strdup(tmp->value), ft_strdup(value));
			tmp->value = s;
			// free(s);
		}
		tmp = tmp->next;
	}
	free(sub);
	g_gv.ex_status = 0;
}

void	export_append_case(t_env **envir, char *str)
{
	int i = 0;
	int end;
	char *sub;
	char *s;
	while (str[i] && str[i] != '+')
		i++;
	end = i;
	if (str[i])
		i++;
	if (str[i] == '=')
	{
		s = ft_substr(str, 0, end);
		sub = ft_strjoin(ft_strdup("$"), ft_strdup(s));
		if (!ft_strcmp(s, "") || !export_check_var(s))
		{
			ft_printf(2, "export : \'%s\' not a valid identifier\n", str);
			g_gv.ex_status = 1;
			free(sub);
			free(s);
			return;
		}
		if (check_var_if_exist(*envir, sub))
			update_var_append_case(envir, sub, str + i + 1);
		else
		{
			add_back_env(envir, ft_lstnew_env(sub, str + i + 1));
			g_gv.ex_status = 0;
			// free(sub);
		}
		free(s);
	}
	else
	{
		ft_printf(2, "export : \'%s\' not a valid identifier\n", str);
		g_gv.ex_status = 1;
	}
}

void export(t_env **envir, char **cmd)
{
	int i = 1;
	int j;
	char *sub;
	char *s;
	char *s1;

	if (!cmd[i])
		only_export_case(envir);
	while (cmd[i])
	{
		j = 0;
		if (cmd[i] && !ft_strcmp(cmd[i]," "))
			i++;
		if (cmd[i] && ft_strstr(cmd[i], "+=") && get_pos(cmd[i], '+') < get_pos(cmd[i], '='))
			export_append_case(envir, cmd[i]);
		else if (cmd[i] && ft_strchr(cmd[i], '='))
		{
			while (cmd[i][j] && cmd[i][j] != '=')
				j++;
			sub = ft_substr(cmd[i], 0, j);
			if (!ft_strcmp(sub, "") || !export_check_var(sub))
			{
				ft_printf(2, "export : \'%s\' not a valid identifier\n", cmd[i]);
				g_gv.ex_status = 1;
				free(sub);
				i++;
				continue ;
			}
			j++;
			if (cmd[i][j])
			{
				s = ft_strjoin(ft_strdup("$"), sub);
				if (check_var_if_exist(*envir, s))
				{
					update_var(envir, s, cmd[i] + j);
					g_gv.ex_status = 0;
					free(s);
				}
				else
				{
					add_back_env(envir, ft_lstnew_env(s, cmd[i] + j));
					g_gv.ex_status = 0;
				}
			}
			else
			{
				s = ft_strjoin(ft_strdup("$"), sub);
				if (check_var_if_exist(*envir, s))
				{
					update_var(envir, s, ft_strdup(""));
					g_gv.ex_status = 0;
					free(s);
				}
				else
				{
					add_back_env(envir, ft_lstnew_env(s, ft_strdup("")));
					g_gv.ex_status = 0;
				}
			}
		}
		else
		{
			if (!export_check_var(cmd[i]) && ft_strcmp(cmd[i]," "))
			{
			ft_printf(2, "export : \'%s\' not a valid identifier\n", cmd[i]);
				g_gv.ex_status = 1;
				i++;
				continue ;
			}
			s = ft_strjoin(ft_strdup("$"), ft_strdup(cmd[i]));
			if (!check_var_if_exist(*envir, s))
			{
				add_back_env(envir, ft_lstnew_env(s , NULL));
				g_gv.ex_status = 0;
			}
			else
				free(s);
		}
		i++;
	}
}
