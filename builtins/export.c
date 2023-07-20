/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:32:05 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/20 14:47:00 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	only_export_case(t_env *envir)
{
	t_env *tmp;
	tmp = envir;
	while (tmp)
	{
		if (!tmp->value)
			printf("declare -x %s\n", tmp->variable + 1);
		else
			printf("declare -x %s=\"%s\"\n", tmp->variable + 1, tmp->value);
		tmp = tmp->next;
	}
	gv.ex_status = 0;
}

void	update_var(t_env *envir, char *variable, char *value)
{
	t_env *tmp;

	tmp = envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, variable))
			tmp->value = value;
		tmp = tmp->next;
	}
	gv.ex_status = 0;
}

void	update_var_append_case(t_env *envir, char *sub, char *value)
{
	t_env *tmp;
	tmp = envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, sub))
			tmp->value = ft_strjoin(ft_strdup(tmp->value), ft_strdup(value));
		tmp = tmp->next;
	}
	gv.ex_status = 0;
}

void	export_append_case(t_env *envir, char *str)
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
		sub = ft_strjoin(ft_strdup("$"), ft_substr(str, 0, end));
		if (!ft_strcmp(ft_substr(str, 0, end), "") || !export_check_var(ft_substr(str, 0, end)))
		{
			printf("export : \'%s\' not a valid identifier\n", str);
			gv.ex_status = 1;
			free(sub);
			return;
		}
		if (check_var_if_exist(envir, sub))
			update_var_append_case(envir, sub, str + i + 1);
		else
		{
			ft_lstadd_back_env(&envir, ft_lstnew_env(sub, str + i + 1));
			gv.ex_status = 0;
		}
	}
	else
	{
		printf("export : \'%s\' not a valid identifier\n", str);
		gv.ex_status = 1;
	}


}

void export(t_env *envir, char **cmd)
{
	int i = 1;
	int j;
	char *sub;
	char *s;

	if (cmd[i] && !ft_strcmp(cmd[i]," "))
		i++;
	if (!cmd[i])
		only_export_case(envir);
	while (cmd[i])
	{
		j = 0;
		if (cmd[i] && ft_strstr(cmd[i], "+="))
			export_append_case(envir, cmd[i]);
		else if (cmd[i] && ft_strchr(cmd[i], '='))
		{
			while (cmd[i][j] && cmd[i][j] != '=')
				j++;
			sub = ft_substr(cmd[i], 0, j);
			if (!ft_strcmp(sub, ft_strdup("")) || !export_check_var(sub))
			{
				printf("export : \'%s\' not a valid identifier\n", cmd[i]);
				gv.ex_status = 1;
				return ;
			}
			if (cmd[i][j])
				j++;
			if (cmd[i][j])
			{
				s = ft_strjoin(ft_strdup("$"), sub);
				if (check_var_if_exist(envir, s))
					update_var(envir, s, cmd[i] + j);
				else
					ft_lstadd_back_env(&envir, ft_lstnew_env(s, cmd[i] + j));
			}
			else
			{
				s = ft_strjoin(ft_strdup("$"), sub);
				if (check_var_if_exist(envir, s))
					update_var(envir, s, ft_strdup(""));
				else
				{
					ft_lstadd_back_env(&envir, ft_lstnew_env(s, ft_strdup("")));
					gv.ex_status = 0;
				}
			}
		}
		else
		{
			if (!export_check_var(ft_strdup(cmd[i])) && ft_strcmp(cmd[i]," "))
			{
				printf("export : \'%s\' not a valid identifier\n", cmd[i]);
				gv.ex_status = 1;
				return ;
			}
			s = ft_strjoin(ft_strdup("$"), cmd[i]);
			if (!check_var_if_exist(envir, s))
			{
				ft_lstadd_back_env(&envir, ft_lstnew_env(s , NULL));
				gv.ex_status = 0;
			}
		}
		i++;
	}
}
