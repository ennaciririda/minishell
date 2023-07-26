/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:03:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/26 18:59:26 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_help_1(t_env **envir, int j, char *sub, char *cmd)
{
	char	*s;

	s = ft_strjoin(ft_strdup("$"), sub);
	if (check_var_if_exist(*envir, s))
	{
		update_var(envir, s, cmd + j);
		g_gv.ex_status = 0;
		free(s);
	}
	else
	{
		add_back_env(envir, ft_lstnew_env(s, cmd + j));
		g_gv.ex_status = 0;
	}
}

void	export_help_2(t_env **envir, char *sub)
{
	char	*s;

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

int	export_help_3(t_env **envir, char *str)
{
	int		j;
	char	*sub;

	j = 0;
	while (str[j] && str[j] != '=')
		j++;
	sub = ft_substr(str, 0, j);
	if (!ft_strcmp(sub, "") || !export_check_var(sub))
	{
		ft_printf(2, "export : \'%s\' not a valid identifier\n", str);
		g_gv.ex_status = 1;
		free(sub);
		return (0);
	}
	if (str[j])
		j++;
	if (str[j])
		export_help_1(envir, j, sub, str);
	else
		export_help_2(envir, sub);
	return (1);
}

int	export_help_4(t_env **envir, char *str)
{
	char	*s;

	if (!export_check_var(str) && ft_strcmp(str, " "))
	{
		ft_printf(2, "export : \'%s\' not a valid identifier\n", str);
		g_gv.ex_status = 1;
		return (0);
	}
	s = ft_strjoin(ft_strdup("$"), ft_strdup(str));
	if (!check_var_if_exist(*envir, s))
	{
		add_back_env(envir, ft_lstnew_env(s, NULL));
		g_gv.ex_status = 0;
	}
	free(s);
	return (1);
}
