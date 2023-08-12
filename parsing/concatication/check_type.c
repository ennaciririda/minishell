/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:26:04 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/11 14:14:13 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_type(int type)
{
	if (type == DOUBLE_QUOTE || type == SINGLE_QUOTE
		|| type == VARIABLE || type == WORD || type == DOLLAR_WHY
		|| type == DOUBLE_DOLLAR)
		return (1);
	return (0);
}
