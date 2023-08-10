/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:25:17 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/08 22:58:57 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_word(char *mai, char *str)
{
	int	i;

	i = 0;
	while (mai[i] && str[i] && (mai[i] == str[i] || mai[i] == str[i] + 32))
		i++;
	if (i == (int)ft_strlen(mai))
		return (1);
	return (0);
}
