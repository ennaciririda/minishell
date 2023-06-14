/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:30:09 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/14 17:07:48 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	return_variable(char *str, int *i, t_env *envir)
{
	int	start = 0;
	char *substr;
	t_env	*node;
	int end = 0;
	if (ft_strchr(str, '$'))
	{
		while (str[(*i)])
		{
			end = 0;
			while (str[(*i)] && str[(*i)] != '$')
				(*i)++;
			start = (*i);
			(*i)++;
			if (str[(*i)] == '$')
			{
				while (str[(*i)] && str[(*i)] == '$')
				{
					(*i)++;
					end++;
				}
				// printf("substr : [%s]\n", ft_substr(str, start, end + 1));
				if ((end + 1) % 2 == 0)
				{
					printf("hello\n");
					str = replace_string(str, ft_substr(str, start, end + 1), ft_strdup(""));
					(*i) = 0;
				}
				else
				{
					str = replace_string(str, ft_substr(str, start, end + 1), ft_strdup("$"));
					(*i) = 0;
				}
			}
			else if (ft_isalnum(str[(*i)]) || str[(*i)] == '_')
			{
				while (str[(*i)] && (ft_isalnum(str[(*i)]) || str[(*i)] == '_'))
				{
					(*i)++;
					end++;
				}
				node = return_node_with_cond(envir, ft_substr(str, start, end + 1));
				if (node)
				{
					str = replace_string(str, ft_substr(str, start, end + 1), node->value);//replace string it replaces all the strings and i want it to replace only one
					// puts(str);
					(*i) = 0;// hna fin kayn chi blan
					printf("else %s\n", str);

				}
				else
				{
					// printf("%d\n",*i);
					str = replace_string(str, ft_substr(str, start, end + 1), ft_strdup(""));
					*i = 0;
					// puts(str);
				}
			}
		}
	}
	printf("str : [%s]\n", str);
}

// int main()
// {
// 	int i = 0;
// 	char *str ;
// 	str = return_variable("adsf$rida|$ilyas",&i);
// 	// printf("substr[%s]\n", str);
// 	return 0;
// }