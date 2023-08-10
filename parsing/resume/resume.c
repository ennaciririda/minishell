/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resume.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:35:06 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/08 23:01:34 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_finallist	*resume(t_globallist *list)
{
	t_globallist	*tmplist;
	t_list			*tmpcmd;
	char			**str;
	t_list			*tmpred;
	t_finallist		*res;

	tmplist = list;
	res = NULL;
	while (tmplist)
	{
		tmpcmd = tmplist->cmd;
		tmpred = tmplist->red;
		str = fill_str(tmpcmd);
		add_back_resume(&res, ft_lstnew_resume(str, tmpred));
		tmplist = tmplist->next;
	}
	free_any_stack_global(&list);
	return (res);
}
