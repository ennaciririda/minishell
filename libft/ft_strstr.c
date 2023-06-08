/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:43:47 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/08 22:41:51 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strstr(const char* haystack, const char* needle)
{
	const char	*h;
	const char	*n;

	if (!(*needle))
		return (char*) haystack;
	h = haystack;
	n = needle;
	while (*haystack)
	{
		while (*h && *n && (*h == *n))
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return (char*) haystack;
		haystack++;
	}

	return (NULL);
}
