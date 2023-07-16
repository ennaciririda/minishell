/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:02:56 by rennacir          #+#    #+#             */
/*   Updated: 2023/07/16 18:36:48 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// hna fin antchecki l flag
char	*here_doc_case(char *content, t_env *envir)
{
	char	*str;
	char	*join;
	char *s;
	char *s1;
	int		fd;
	static int i = 0;
	char	*file;
	join = NULL;
	str = get_next_line(0);
	s = ft_strjoin(ft_strdup(content), ft_strdup("\n"));
	while (str && ft_strcmp(str, s))
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
	free(s);
	free(str);
	s1 = ft_strjoin(ft_strdup("/tmp/file_"), ft_itoa(i));
	fd = open(s1 , O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		return NULL;
	ft_putstr_fd(join, fd);
	file = ft_strjoin(ft_strdup("/tmp/file_"), ft_itoa(i));
	i++;
	free(join);
	free(s1);
	return file;
}
