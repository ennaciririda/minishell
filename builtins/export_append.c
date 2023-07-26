/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:24:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/26 18:58:51 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_var_append_case(t_env *envir, char *sub, char *value)
{
	t_env	*tmp;
	char	*s;

	tmp = envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, sub))
		{
			s = ft_strjoin(ft_strdup(tmp->value), ft_strdup(value));
			tmp->value = s;
			free(s);
		}
		tmp = tmp->next;
	}
	free(sub);
	g_gv.ex_status = 0;
}

void	print_and_exit(char *str)
{
	ft_printf(2, "export : \'%s\' not a valid identifier\n", str);
	g_gv.ex_status = 1;
}

void	export_append_case_2(char *str, int end, t_env *envir, int i)
{
	char	*sub;

	sub = ft_strjoin(ft_strdup("$"), ft_substr(str, 0, end));
	if (!ft_strcmp(ft_substr(str, 0, end), "")
		|| !export_check_var(ft_substr(str, 0, end)))
	{
		print_and_exit(str);
		free(sub);
		return ;
	}
	if (check_var_if_exist(envir, sub))
		update_var_append_case(envir, sub, str + i + 1);
	else
	{
		add_back_env(&envir, ft_lstnew_env(sub, str + i + 1));
		g_gv.ex_status = 0;
	}
}

void	export_append_case(t_env *envir, char *str)
{
	int		i;
	int		end;
	char	*sub;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '+')
		i++;
	end = i;
	if (str[i])
		i++;
	if (str[i] == '=')
		export_append_case_2(str, end, envir, i);
	else
		print_and_exit(str);
}
