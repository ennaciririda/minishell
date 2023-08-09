/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:03:39 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/09 22:11:15 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	export_append_case_help(char *s, char *str, t_env **envir, int i)
{
	char	*sub;

	sub = ft_strjoin(ft_strdup("$"), ft_strdup(s));
	if (!ft_strcmp(s, "") || !export_check_var(s))
	{
		ft_printf(2, "export : \'%s\' not a valid identifier\n", str);
		g_gv.exit_status = 1;
		free(sub);
		free(s);
		return (0);
	}
	if (check_var_if_exist(*envir, sub))
		update_var_append_case(envir, sub, str + i + 1);
	else
	{
		add_back_env(envir, ft_lstnew_env(sub, ft_strdup(str + i + 1)));
		g_gv.exit_status = 0;
	}
	return (1);
}

void	cmd_ij_exists(char *sub, t_env **envir, char *cmdi_plus_j)
{
	char	*s;

	s = ft_strjoin(ft_strdup("$"), sub);
	if (check_var_if_exist(*envir, s))
	{
		update_var(envir, s, cmdi_plus_j);
		g_gv.exit_status = 0;
		free(s);
	}
	else
	{
		add_back_env(envir, ft_lstnew_env(s, cmdi_plus_j));
		g_gv.exit_status = 0;
	}
}

void	cmd_ij_not_exists(char *sub, t_env **envir)
{
	char	*s;

	s = ft_strjoin(ft_strdup("$"), sub);
	if (check_var_if_exist(*envir, s))
	{
		update_var(envir, s, ft_strdup(""));
		g_gv.exit_status = 0;
		free(s);
	}
	else
	{
		add_back_env(envir, ft_lstnew_env(s, ft_strdup("")));
		g_gv.exit_status = 0;
	}
}

int	equal_not_exist(char *cmdi, t_env **envir)
{
	char	*s;

	if (!export_check_var(cmdi) && ft_strcmp(cmdi, " "))
	{
		ft_printf(2, "export : \'%s\' not a valid identifier\n", cmdi);
		g_gv.exit_status = 1;
		return (0);
	}
	s = ft_strjoin(ft_strdup("$"), ft_strdup(cmdi));
	if (!check_var_if_exist(*envir, s))
	{
		add_back_env(envir, ft_lstnew_env(s, NULL));
		g_gv.exit_status = 0;
	}
	else
		free(s);
	return (1);
}

int	equal_exists(char *cmdi, t_env	**envir)
{
	char	*sub;
	int		j;

	j = 0;
	while (cmdi[j] && cmdi[j] != '=')
		j++;
	sub = ft_substr(cmdi, 0, j);
	if (!ft_strcmp(sub, "") || !export_check_var(sub))
	{
		ft_printf(2, "export : \'%s\' not a valid identifier\n", cmdi);
		g_gv.exit_status = 1;
		free(sub);
		return (0);
	}
	j++;
	if (cmdi[j])
		cmd_ij_exists(sub, envir, ft_strdup(cmdi + j));
	else
		cmd_ij_not_exists(sub, envir);
	return (1);
}
