/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:15 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/05 02:30:00 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_quotes(char *str)
{
	int	i;
	int	count_d;
	int	count;
	i = 0;
	count = 0;
	count_d = 0;
	if (!str)
		return ;
	while(str[i])
	{
		if (str[i] == '\"')
			count_d++;
		if (str[i] == '\'')
			count++;
		i++;
	}
	printf(" single quotes :%d\n", count);
	printf(" double quotes :%d\n", count_d);
	// if (count % 2 || count_d % 2)
	// {
	// 	printf("Error syntex\n");
	// 	exit(1);
	// }
}


t_list *tokenizing(char *str)
{
	t_list	*list;
	int i = 0;
	int j = 0;
	int start;
	int count = 0;
	char *s;
	while(str[i])
	{
		if (str[i] == ' ')
		{
			ft_lstadd_back(&list, ft_lstnew(" ", WHITE_SPACE));
			i++;
		}
		else if (str[i] == '|')
		{
			ft_lstadd_back(&list, ft_lstnew("|", PIPE));
			i++;
		}
		else if (str[i] == '>' && str[i + 1] == '>')
		{
			check_dir(str);
			ft_lstadd_back(&list, ft_lstnew(">>", ARED_OUT));
			i+=2;
		}
		else if (str[i] == '>' && str[i + 1] != '>')
		{
			ft_lstadd_back(&list, ft_lstnew(">", RED_OUT));
			i++;
		}
		else if (str[i] == '<')
		{
			ft_lstadd_back(&list, ft_lstnew("<", RED_IN));
			i++;
		}
		else if (str[i] == '\"')
		{
			check_is_close(str, '\"');
			i++;
			start = i;
			j = 0;
			while(str[i] && str[i] != '\"')
			{
				i++;
				j++;
			}
			ft_lstadd_back(&list, ft_lstnew(ft_substr(str, start, j), DOUBLE_QUOTE));
			i++;
		}
		else if (str[i] == '\'')
		{
			check_is_close(str, '\'');
			i++;
			start = i;
			j = 0;
			while(str[i] && str[i] != '\'')
			{
				i++;
				j++;
			}
			ft_lstadd_back(&list, ft_lstnew(ft_substr(str, start, j), SINGLE_QUOTE));
			i++;
		}
		else if(str[i] != ' ' && str[i] != '|' && str[i] != '>' && str[i] != '<' && str[i] != '\'' && str[i] != '\"')
		{
			start = i;
			j = 0;
			while(str[i] && str[i] != ' ' && str[i] != '|' && str[i] != '>' && str[i] != '<' && str[i] != '\'' && str[i] != '\"')
			{
				i++;
				j++;
			}
			ft_lstadd_back(&list, ft_lstnew(ft_substr(str, start, j), WORD));
		}
		else
			i++;
	}
	return list;
}

int main()
{
	char *str;
	t_list *list;
	t_list *tmp;
	// int i = 0;
	str = readline("minishell$ ");
	list = tokenizing(str);
	tmp = list;
	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	return 0;
}