/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:12:22 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/05 02:55:54 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	error(char *str)
// {
// 	printf("%s\n", str);
// 	exit(1);
// }

void	check_is_close(char *str, char c)
{
	int	i = 0;
	int flag = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			flag = -1;
			i++;
			while (str[i] && str[i] != c)
				i++;
			if (str[i] == c)
				flag = 1;
			if (flag == -1)
				error("Error: about quotes");
		}
		i++;
	}
}

// int	main()
// {
// 	char *str;

// 	str = readline("test$ ");
// 	check_is_close(str, '\"');
// 	return 0;
// }