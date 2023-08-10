/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_built.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:26:57 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/09 18:44:06 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_builtins(char *str)
{
	if (str && !check_word("echo", str) && !check_word("cd", str)
		&& !check_word("pwd", str) && !check_word("env", str)
		&& ft_strcmp("export", str) && ft_strcmp("exit", str)
		&& ft_strcmp("unset", str))
		return (1);
	return (0);
}
