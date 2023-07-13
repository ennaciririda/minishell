/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:22:46 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/13 23:40:42 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_word(char *str, char *mai)
{
	int i = 0;
	while (mai[i])
	{
		if ((mai[i] >= 'A' && mai[i] <= 'Z' && (mai[i] == str[i] || mai[i] == str[i] + 32))
		|| (mai[i] >= 'a' && mai[i] <= 'z' && (mai[i] == str[i] || mai[i] == str[i] - 32)))
			i++;
		else
			return 0;
		i++;
	}
	return 1;
}

int main()
{
	printf("%d", check_word("echo" ,"ecHo"));
	return 0;
}