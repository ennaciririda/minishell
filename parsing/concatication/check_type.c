/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:26:04 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/10 22:33:19 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_type(int type)
{
	if (type == DOUBLE_QUOTE || type == SINGLE_QUOTE
		|| type == VARIABLE || type == WORD || type == DOLLAR_WHY)
		return (1);
	return (0);
}
