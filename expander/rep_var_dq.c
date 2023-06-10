/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_var_dq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:45:58 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/10 19:41:15 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*return_node_with_cond(t_env *env, char *str)
{
	t_env	*tmp;
	tmp = env;
	if (!tmp || !str)
		return NULL;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, str))
			return tmp;
		tmp = tmp->next;
	}
	return (NULL);
}


// t_list	*rep_var_dq(t_list *list, t_env *envir)
// {

// }