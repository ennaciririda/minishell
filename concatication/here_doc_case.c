/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:02:56 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/08 15:22:06 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	here_doc_case_help1(char **str, char **join)
{
	*join = ft_strjoin(*join, *str);
	*str = get_next_line(0);
}

char	*here_doc_case_help(char *s, t_env *envir, char *str, int tabc)
{
	char	*join;

	join = NULL;
	while (str && ft_strcmp(str, s))
	{
		if (tabc)
			here_doc_case_help1(&str, &join);
		else
		{
			if (ft_strchr(str, '$'))
			{
				str = extract_var_herdoc(str, envir);
				join = ft_strjoin(join, str);
				str = get_next_line(0);
			}
			else
				here_doc_case_help1(&str, &join);
		}
	}
	free(str);
	return (join);
}

char	*here_doc_case(char *content, t_env *envir, int tabc)
{
	char		*s;
	int			fd;
	static int	i;
	char		*file;
	char		*join;

	s = ft_strjoin(ft_strdup(content), ft_strdup("\n"));
	join = here_doc_case_help(s, envir, get_next_line(0), tabc);
	free(s);
	s = NULL;
	s = ft_strjoin(ft_strdup("/tmp/file_"), ft_itoa(i));
	fd = open(s, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		return (NULL);
	ft_putstr_fd(join, fd);
	file = ft_strjoin(ft_strdup("/tmp/file_"), ft_itoa(i));
	i++;
	free(join);
	free(s);
	return (file);
}
