/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:12:22 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/13 21:48:53 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_is_close(char *str, char c)
{
	int i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		i++;
	else
		error("quote is not close");
}
