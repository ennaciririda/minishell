/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:19:55 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/13 23:13:41 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	commands(t_finallist *lastlist, t_env *envir)
{
	echo(lastlist);
	cd(lastlist, envir);
	//pwd(lastlist, envir);
}