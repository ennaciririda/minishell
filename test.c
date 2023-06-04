/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:52:31 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/03 22:51:19 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av)
{
	char *str;
	char *word;
	int i = -1;
	int j = 0;
	int start = 0;
	int end = 0;

	str = readline("test$ ");
	while(str[++i])
	{
		j = 0;
		while(str[i])
		{
			if (str[i] == '\"')
			{
				start = i;
				break ;
			}
			i++;
		}
		while (str[i] && str[i] != '\"')
			i++;
		end = i;
		word = malloc(start - end + 2);
		if (!word)
			return (0);
		while(start <= end)
		{
			word[j] = str[start];
			start++;
			j++;
		}
		word[j] = '\0';
		printf("%s\n", word);
	}
	return 0;
}
