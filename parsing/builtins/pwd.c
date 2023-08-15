/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:06:49 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/14 22:33:25 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pwd(void)
{
	char	str[1024];

	getcwd(str, 1024);
	ft_printf(1, "%s\n", str);
	g_gv.exit_status = 0;
		// ft_printf(2, "getcwd: cannot access parent directories\n");
	// free(str);
}
