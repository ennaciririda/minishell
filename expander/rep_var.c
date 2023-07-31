/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:02:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/31 14:14:49 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*return_node(t_list *tmp, t_env *etmp)
{
	t_list	*tmpp;
	t_env	*etmpp;

	if (!tmp || !etmp)
		return (NULL);
	tmpp = tmp;
	etmpp = etmp;
	while (tmpp)
	{
		if (tmpp->type == VARIABLE)
		{
			while (etmpp)
			{
				if (!ft_strcmp(tmpp->content, etmpp->variable))
					return (etmpp);
				etmpp = etmpp->next;
			}
		}
		tmpp = tmpp->next;
	}
	return (NULL);
}

void	rep_var_help_1(t_env *envir, t_list **new_list, t_list *tmp)
{
	t_env	*node;
	char	**split;
	int		i;

	i = 0;
	node = return_node(tmp, envir);
	if (node)
	{
		i = 0;
		split = ft_split(node->value);
		while (split[i])
		{
			add_back(new_list, new_tokens(ft_strdup(split[i]),
					VARIABLE));
			if (split[i + 1])
				add_back(new_list, new_tokens(ft_strdup(" "),
						VARIABLE));
			i++;
		}
		free_2d_tab(split);
	}
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
			add_back(new_list, new_tokens(ft_strdup(tmp->content),
					tmp->type));
			tmp = tmp->next;
		}
		if (tmp && !ft_strcmp(tmp->content, "$"))
			add_back(new_list, new_tokens(ft_strdup(tmp->content),
					tmp->type));
		else
			rep_var_help_1(envir, new_list, tmp);
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
	free_any_stack(&list);
	return (new_list);
}
