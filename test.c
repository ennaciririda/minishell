/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:15 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/03 14:23:20 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char *str;
	int i = 0;
	str = readline("minishell$");
	while(str[i])
	{
		if (str[i] == '>')
			printf("%c : is a redirection\n", str[i]);
		if (str[i] == '|')
			printf("%c : is a pipe\n", str[i]);
		if (str[i] == '"')
			printf("%c : is a doublequote\n", str[i]);
		if (str[i] == '\'')
			printf("%c : is a singlequote\n", str[i]);
		i++;
	}
	return 0;
}