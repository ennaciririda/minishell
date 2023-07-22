/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:34:34 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/22 16:39:08 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	export_check_var(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		else
		{
			free(str);
			return 0;
		}
	}
	return 1;
}