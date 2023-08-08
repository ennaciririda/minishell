/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:41:51 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/04 12:00:34 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*new_tokens(char *content, int type)
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
	liste->red = redir;
	liste->next = NULL;
	return (liste);
}

t_finallist	*ft_lstnew_resume(char **str, t_list *redir)
{
	t_finallist	*liste;

	liste = malloc(sizeof(t_finallist));
	if (!liste)
		return (0);
	liste->cmd = str;
	liste->red = redir;
	liste->next = NULL;
	return (liste);
}
