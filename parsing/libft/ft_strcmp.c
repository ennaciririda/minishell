/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:36:40 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/08 23:01:01 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strcmp(const char *first, const char *second)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *)first;
	s = (unsigned char *)second;
	i = 0;
	while ((f[i] || s[i]))
	{
		if (f[i] != s[i])
			return (f[i] - s[i]);
		i++;
	}
	return (0);
}
