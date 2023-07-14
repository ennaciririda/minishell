/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:25:17 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/14 08:25:34 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_word(char *mai, char *str)
{
	int i = 0;
	while (mai[i])
	{
		if (mai[i] == str[i] || mai[i] == str[i] + 32)
			i++;
		else
			return 0;
	}
	return 1;
}