/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var_if_exist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:44:12 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/26 15:56:57 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_var_if_exist(t_env *envir, char *to_check)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, to_check))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
