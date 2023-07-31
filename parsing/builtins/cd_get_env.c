/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:05:05 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/25 16:02:20 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*cd_get_env(t_env *envir, char *str)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, str))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
