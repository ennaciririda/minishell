/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:06:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/14 16:19:52 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd(t_finallist	*lastlist, char **cmd)
{
	char *str;
	str = getcwd(NULL, 0);
	printf("%s\n", str);
}
