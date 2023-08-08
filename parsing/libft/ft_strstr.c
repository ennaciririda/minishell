/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:43:47 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/29 17:07:22 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strstr(char	*big, char *little)
{
	size_t		k;
	int			i;
	int			j;

	i = 0;
	if (!big)
		return (0);
	if (!(*little))
		return (0);
	while (*big)
	{
		k = 0;
		j = 0;
		while (little[j] == big[j])
		{
			k++;
			j++;
			if (little[j] == '\0')
				return (1);
		}
		big++;
		i++;
	}
	return (0);
}
