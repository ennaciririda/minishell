/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:02:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/10 19:55:56 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*return_node(t_list *tmp, t_env *etmp)
{
	t_list	*tmpp;
	t_env	*etmpp;

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
				if (!ft_strcmp(tmpp->content, etmpp->variable))
					return etmpp;
				etmpp = etmpp->next;
			}
		}
		tmpp = tmpp->next;
	}
	return (NULL);
}

void	rep_var_help(t_list	*tmp, t_list **new_list, t_env *envir)
{
	t_env	*node;
	char	**split;
	int		i;

	while (tmp)
	{
		while (tmp && tmp->type != VARIABLE)
		{
			ft_lstadd_back(new_list, ft_lstnew_tokens(tmp->content, tmp->type));
			tmp = tmp->next;
		}
		node = return_node(tmp, envir);
		if (node)
		{
			i = 0;
			split = ft_split(node->value,' ');
			while (split[i])
			{
				ft_lstadd_back(new_list, ft_lstnew_tokens(split[i], VARIABLE));
				if (split[i + 1])
					ft_lstadd_back(new_list, ft_lstnew_tokens(ft_strdup(" "), VARIABLE));
				i++;
			}
		}
		if (tmp)
			tmp = tmp->next;
	}
}

t_list	*rep_var(t_list *list, t_env *envir)
{
	int		i;
	t_list	*tmp;
	t_list	*new_list;
	tmp = list;
	new_list = NULL;
	rep_var_help(tmp, &new_list, envir);
	return new_list;
}
