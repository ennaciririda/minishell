/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:41:51 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/03 16:18:55 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*liste;

	liste = malloc(sizeof(t_list));
	if (!liste)
		return (0);
	liste->content = content;
	liste->next = NULL;
	return (liste);
}
