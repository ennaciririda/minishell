/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:52:44 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/21 14:54:59 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_dir(char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == c)
		{
			count = 0;
			while(str[i] && str[i] == c)
			{
				count++;
				i++;
			}
			if (count > 2)
			error("Error : about redirection");
		}
		i++;
	}
}
