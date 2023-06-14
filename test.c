
#include "minishell.h"
#include <stdio.h>
#include <string.h>

char	*replace_string(char *str, char *oldstr, char *newstr)
{
	int strLen = strlen(str);
	int oldstrlen = strlen(oldstr);
	int newstrlen = strlen(newstr);
	int j = 0;
	int i = 0;
	// char *stmp = str;
	char *finalstr;
	int finalstrLen;
	// while ((stmp = ft_strstr(stmp, oldstr)))
	// {
	// 	i++;
	// 	stmp += oldstrlen;
	// }
	finalstrLen = strLen + (newstrlen - oldstrlen);
	finalstr = (char *)malloc(finalstrLen + 1);
	if (!finalstr)
		return NULL;
	i = 0;
	while (i < strLen)
	{
		if (strncmp(&str[i], oldstr, oldstrlen) == 0)
		{
			strncpy(&finalstr[j], newstr, newstrlen);
			j += newstrlen;
			i += oldstrlen;
			break;
		}
		i++;
	}
	while (str[i])
	{
		finalstr[j] = str[i];
		j++;
		i++;
	}
	finalstr[j] = '\0';
	return finalstr;
}

int main() {
	char str[100] = "hello, world! hello, universe! hello, galaxy!";
	const char oldSubstr[] = "hello";
	const char newSubstr[] = "Hi";
	char *sttr;

	printf("Before: %s\n", str);
	sttr = replaceString(str, oldSubstr, newSubstr);
	printf("After: %s\n", sttr);

	return 0;
}