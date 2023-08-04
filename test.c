/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:29:56 by rennacir          #+#    #+#             */
/*   Updated: 2023/08/04 12:55:48 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static char	*get_str(const char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (!is_white_space(str[i]) && str[i])
		i++;
	word = malloc(i + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (!is_white_space(str[i]) && str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**freeall(char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
	return (NULL);
}

static char	**spl(char **split, const char *s)
{
	int	j;

	j = 0;
	while (*s)
	{
		while (*s && is_white_space(*s))
			s++;
		if (*s)
		{
			split[j] = get_str(s);
			if (!split[j])
				freeall(split);
			j++;
		}
		while (*s && !is_white_space(*s))
			s++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		while (s[i] && is_white_space(s[i]))
			i++;
		if (s[i])
			j++;
		while (s[i] && !is_white_space(s[i]))
			i++;
	}
	split = malloc (sizeof(char *) * (j + 1));
	if (!split)
		return (NULL);
	split = spl(split, s);
	return (split);
}



int main(int argc, char **argv, char **env)
{
	int id;
	int p[2];
	int in;
	int i = 0;
	char *str;


	// in = 0;
	// while(i < argc  )
	// {
	// 	if (i < argc - 1)
	// 		pipe(p);
	// 	id = fork();
	// 	if (id == 0)
	// 	{
	// 		dup2(p[1], 1);
	// 		if (i != 1)
	// 			dup2(in, 0);
	// 		close(p[0]);
	// 		close(p[1]);
	// 		split = ft_split(argv[i]);
	// 		execve(split[0], split, env);
	// 	}
	// 	else
	// 	{
	// 		close(p[1]);
	// 		in = p[0];
	// 		i +=2;
	// 	}
	// }
	// close(in);
	// close(p[0]);
	// while (waitpid(-1, NULL, 0)!= -1);
}
