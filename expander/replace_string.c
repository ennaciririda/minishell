/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:38:44 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/21 15:48:36 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*replace_string(char *str, char *oldstr, char *newstr)
{
	int strlen = ft_strlen(str);
	int oldstrlen = ft_strlen(oldstr);
	int newstrlen = ft_strlen(newstr);
	int j = 0;
	int i = 0;
	char *finalstr;
	int finalstrlen;
	finalstrlen = strlen + (newstrlen - oldstrlen);
	finalstr = (char *)malloc(finalstrlen + 1);
	if (!finalstr)
		return NULL;
	while (str[i] && strncmp(&str[i],oldstr,oldstrlen))
	{
		finalstr[j] = str[i];
		i++;
		j++;
	}
	if (j < finalstrlen)
		strncpy(&finalstr[j], newstr, newstrlen);
	j += newstrlen;
	i += oldstrlen;
	while (str[i])
	{
		finalstr[j] = str[i];
		i++;
		j++;
	}
	finalstr[j] = '\0';
	return finalstr;
}
