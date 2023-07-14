/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:22:46 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/14 15:32:56 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == 'b')
			str[i] = 'x';
		i++;
	}
}

int main()
{
	char *str;
	str = malloc(5);
	int i = 0;
	while(i < 5)
	{
		str[i] = 'a' + i;
		i++;
	}
	printf("befoure : [%s]\n", str);
	change(str);
	printf("after : [%s]\n", str);
}
