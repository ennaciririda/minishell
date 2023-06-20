
#include "minishell.h"
#include <stdio.h>
#include <string.h>

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

char	**ft_splitt(char const *s)
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
