/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:26:04 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/09 22:16:04 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_type(int type)
{
	if (type == DOUBLE_QUOTE || type == SINGLE_QUOTE
		|| type == VARIABLE || type == WORD)
		return (1);
	return (0);
}
