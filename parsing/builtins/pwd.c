/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:06:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/11 23:40:08 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (!str)
	{
		ft_printf(2, "getcwd: cannot access parent directories");
		g_gv.exit_status = 0;
	}
	else
		ft_printf(1, "%s\n", str);
	free(str);
}
