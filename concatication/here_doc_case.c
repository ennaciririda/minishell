/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:02:56 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/11 15:44:50 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// hna fin antchecki l flag
char	*here_doc_case(char *content, t_env *envir)
{
	char	*str;
	char	*join;
	int		fd;
	static int i = 0;
	char	*file;
	join = NULL;
	str = get_next_line(0);
	while (str && ft_strcmp(str, ft_strjoin(ft_strdup(content), ft_strdup("\n"))))
	{
		if (fll == 1337)
		{
			join = ft_strjoin(join, str);
			str = get_next_line(0);
		}
		else
		{
			if (ft_strchr(str, '$'))
			{
				str = extract_var_herdoc(str, envir);
				join = ft_strjoin(join, str);
				str = get_next_line(0);
			}
			else
			{
				join = ft_strjoin(join, str);
				str = get_next_line(0);
			}
		}

	}
	fd = open(ft_strjoin(ft_strdup("/tmp/file_"), ft_itoa(i)) , O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		return NULL;
	ft_putstr_fd(join, fd);
	file = ft_strjoin(ft_strdup("/tmp/file_"), ft_itoa(i));
	i++;
	return file;
}
