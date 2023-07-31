/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:10:56 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/18 13:00:34 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s;
	char	*t;
	size_t	i;

	i = 0;
	if (!s1)
		len = 0;
	else
		len = ft_strlen(s1);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	t = s;
	while (i < len)
	{
		*s = *s1;
		s++;
		s1++;
		i++;
	}
	*s = '\0';
	return (t);
}
