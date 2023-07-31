/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:23:13 by hlabouit          #+#    #+#             */
/*   Updated: 2023/07/31 15:52:28 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*s01;
	unsigned char	*s02;

	i = 0;
	s01 = (unsigned char *)s1;
	s02 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s01[i] && s02[i] && i < n - 1)
	{
		if (s01[i] != s02[i])
			break ;
		i++;
	}
	return (s01[i] - s02[i]);
}