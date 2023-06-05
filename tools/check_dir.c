/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:52:44 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/05 02:11:05 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	error(char *str)
// {
// 	printf("%s\n", str);
// 	exit(1);
// }

void	check_dir(char *str)
{
	int count = 0;
	int i = 0;

	while(str[i])
	{
		if (str[i] == '>')
		{
			count = 0;
			while(str[i] && str[i] == '>')
			{
				count++;
				i++;
			}
			if (count > 2)
			error("Error : about redirection");
		}
		i++;
	}
	// printf("count : %d\n", count);
}

// int	main()
// {
// 	char *str;

// 	str = readline("test$ ");
// 	check_dir(str);
// 	return 0;
// }