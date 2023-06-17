/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:02:56 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/17 22:23:26 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	here_doc_case(char *content)
{
	char *str;
	char *join;
	str = readline("heredoc> ");
	join = ft_strjoin(str, ft_strdup(""));
	while (str && ft_strcmp(str, content))
	{
		str = readline("heredoc> ");
		join = ft_strjoin(join, str);
	}
	printf("join [%s]", join);
}

int main()
{
	here_doc_case("rida");
	return 0;
}