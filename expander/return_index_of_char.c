/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_index_of_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:59:23 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/10 14:01:33 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	return_index_of_char(char *str, char c)
{
	int i = 0;
	while (str[i])
	{
		if(str[i] == c)
			return i;
		i++;
	}
	return -1;
}