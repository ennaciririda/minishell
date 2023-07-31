/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:38:44 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/23 14:32:01 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*rep_str(char *str, char *oldstr, char *newstr)
{
	int		strlen;
	int		j;
	int		i;
	char	*finalstr;
	int		finalstrlen;

	i = 0;
	j = 0;
	strlen = ft_strlen(str);
	finalstrlen = strlen + (ft_strlen(newstr) - ft_strlen(oldstr));
	finalstr = (char *)malloc(finalstrlen + 1);
	if (!finalstr)
		return (NULL);
	while (str[i] && ft_strncmp(&str[i], oldstr, ft_strlen(oldstr)))
		finalstr[j++] = str[i++];
	if (j < finalstrlen)
		ft_strncpy(&finalstr[j], newstr, ft_strlen(newstr));
	j += ft_strlen(newstr);
	i += ft_strlen(oldstr);
	while (str[i])
		finalstr[j++] = str[i++];
	finalstr[j] = '\0';
	free(oldstr);
	free(newstr);
	return (finalstr);
}
