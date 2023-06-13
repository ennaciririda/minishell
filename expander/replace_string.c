/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:38:44 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/12 23:59:23 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*replace_string(char *str, char *oldstr, char *newstr)
{
	int strLen = ft_strlen(str);
	int oldstrlen = ft_strlen(oldstr);
	int newstrlen = ft_strlen(newstr);
	int j = 0;
	int i = 0;
	char *stmp = str;
	char *finalstr;
	int finalstrLen;
	while ((stmp = ft_strstr(stmp, oldstr)))
	{
		i++;
		stmp += oldstrlen;
	}
	finalstrLen = strLen + (newstrlen - oldstrlen) * i;
	finalstr = (char *)malloc(finalstrLen + 1);
	if (!finalstr)
		return NULL;
	i = 0;
	while (i < strLen)
	{
		if (ft_strncmp(&str[i], oldstr, oldstrlen) == 0)
		{
			strncpy(&finalstr[j], newstr, newstrlen);
			j += newstrlen;
			i += oldstrlen;
		}
		else
		{
			finalstr[j] = str[i];
			j++;
			i++;
		}
	}
	finalstr[j] = '\0';
	return finalstr;
}