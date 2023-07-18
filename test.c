/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:09:17 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/18 13:07:28 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include "minishell.h"

int	ft_strnstr(const char	*big, const char *little)
{
	size_t		k;
	int			i;
	int			j;

	i = 0;
	if (!big)
		return (0);
	if (!(*little))
		return 0;
	while (*big)
	{
		k = 0;
		j = 0;
		while (little[j] == big[j])
		{
			k++;
			j++;
			if (little[j] == '\0')
				return 1;
		}
		big++;
		i++;
	}
	return (0);
}

int main()
{
	printf("%d\n", ft_strnstr("hello+-+", "+-"));
}