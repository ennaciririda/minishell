/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:57:42 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/15 13:08:22 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(t_env *envir)
{
	t_env	*tmp;
	char	*str;
	tmp = envir;
	while (tmp)
	{
		printf("%s=%s\n", tmp->variable + 1, tmp->value);
		tmp = tmp->next;
	}
}