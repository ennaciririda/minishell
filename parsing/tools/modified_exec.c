/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 23:06:46 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/17 14:06:38 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_cmd_fnl(t_finallist *commands_list)
{
	int		count;
	int		i;
	int		j;
	char	**split;

	i = 0;
	count = 0;
	while (commands_list->cmd[i])
	{
		j = 0;
		split = ft_split(commands_list->cmd[i]);
		while (split && split[j++])
			count++;
		free_2d_tab(split);
		i++;
	}
	return (count);
}

void	change_2d_tab(t_finallist **commands_list)
{
	char				**split;
	char				**cmd;
	char				**cmdtofree;
	t_norm_struggles	ns;

	ns.i = 0;
	ns.k = 0;
	ns.count = count_cmd_fnl(*commands_list);
	cmd = malloc(sizeof(char *) * (ns.count + 1));
	if (!cmd)
		return ;
	while ((*commands_list)->cmd[ns.i])
	{
		ns.j = 0;
		split = ft_split((*commands_list)->cmd[ns.i]);
		while (split && split[ns.j])
			cmd[ns.k++] = ft_strdup(split[ns.j++]);
		ns.i++;
		free_2d_tab(split);
	}
	cmd[ns.k] = NULL;
	cmdtofree = (*commands_list)->cmd;
	(*commands_list)->cmd = cmd;
	free(cmdtofree);
}
