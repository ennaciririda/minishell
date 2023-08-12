/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:06:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/12 00:45:32 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (!str)
	{
		ft_printf(2, "getcwd: cannot access parent directories\n");
		g_gv.exit_status = 0;
	}
	else
		ft_printf(1, "%s\n", str);
	free(str);
}
