/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:38:44 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/08 22:38:48 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*replaceString(char *str, char *oldstr, char *newstr)
{
	int strLen = ft_strlen(str); // len of the string
	int oldstrLen = ft_strlen(oldstr); // len of old word
	int newstrLen = ft_strlen(newstr); // len of new word
	int j = 0;
	int i = 0;
	char *stmp = str;
	char *finalstr;
	int finalstrLen;
	while ((stmp = ft_strstr(stmp, oldstr))) {
		i++;
		stmp += oldstrLen;
	}
	finalstrLen = strLen + (newstrLen - oldstrLen) * i;
	finalstr = (char *)malloc(finalstrLen + 1);
	if (!finalstr)
		return NULL;
	i = 0;
	while (i < strLen)
	{
		if (ft_strncmp(&str[i], oldstr, oldstrLen) == 0)
		{
			ft_strncpy(&finalstr[j], newstr, newstrLen);
			j += newstrLen;
			i += oldstrLen;
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