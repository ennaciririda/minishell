/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:41:51 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/21 19:39:22 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstnew_tokens(char *content, int type)
{
	t_list	*liste;

	liste = malloc(sizeof(t_list));
	if (!liste)
		return (0);
	liste->content = content;
	liste->type = type;
	liste->next = NULL;
	return (liste);
}

t_env	*ft_lstnew_env(char *variable, char *value)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (0);
	env->variable = variable;
	env->value = value;
	env->next = NULL;
	return (env);
}

t_globallist	*ft_lstnew_global(t_list *cmd, t_list *redir)
{
	t_globallist	*liste;

	liste = malloc(sizeof(t_globallist));
	if (!liste)
		return (0);
	liste->cmd = cmd;
	liste->red= redir;
	liste->next = NULL;
	return (liste);
}