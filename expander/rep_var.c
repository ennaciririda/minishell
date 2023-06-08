/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:02:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/08 03:48:36 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*return_node(t_list *tmp, t_env *etmp)
{
	t_list *tmpp;
	t_env *etmpp;

	if (!tmp || !etmp)
		return NULL;
	tmpp = tmp;
	etmpp = etmp;
	while (tmpp)
	{
		if (tmpp->type == VARIABLE)
		{
			while (etmpp)
			{
				if (!ft_strcmp(tmpp->content + 1, etmpp->variable))
				{
					// printf("%s ", etmpp->variable);
					// printf("%s \n", etmpp->value);
					return etmpp;
				}
				etmpp = etmpp->next;
			}
		}
		tmpp = tmpp->next;
	}
	return (NULL);
}

t_list	*rep_var(t_list *list, t_env *envir)
{
	int i = 0;
	t_list	*tmp;
	t_env	*etmp;
	t_env	*node;
	char	**split;
	t_list	*new_list;
	tmp = list;
	etmp = envir;
	new_list = NULL;
	while (tmp)
	{
		while (tmp && tmp->type != VARIABLE)
		{
			ft_lstadd_back(&new_list, ft_lstnew_tokens(tmp->content, tmp->type));
			tmp = tmp->next;
		}
		node = return_node(tmp, etmp);
		if (node)
		{
			split = ft_split(node->value,' ');
			while (split[i])
			{
				ft_lstadd_back(&new_list, ft_lstnew_tokens(split[i], VARIABLE));
				i++;
			}
		}
		if (tmp && tmp->next)
			tmp = tmp->next;
		while (tmp && tmp->type != VARIABLE)
		{
			ft_lstadd_back(&new_list, ft_lstnew_tokens(tmp->content, tmp->type));
			tmp = tmp->next;
		}
	}
	return new_list;
}
