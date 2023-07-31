/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:55:04 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/24 15:43:15 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_redir_type(int type)
{
	if (type == RED_IN || type == RED_OUT
		|| type == ARED_OUT || type == HER_DOC)
		return (1);
	return (0);
}
