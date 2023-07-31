/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:34:34 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/24 15:56:39 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**fill_str(t_list *tmp)
{
	int		count;
	char	**str;
	int		i;

	i = 0;
	count = count_cmd(tmp);
	str = malloc (sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	while (tmp && tmp->type == WHITE_SPACE)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->type == WHITE_SPACE && (!tmp->next
				|| tmp->next->type == WHITE_SPACE))
			tmp = tmp->next;
		else
		{
			str[i] = ft_strdup(tmp->content);
			i++;
			tmp = tmp->next;
		}
	}
	str[i] = NULL;
	return (str);
}
