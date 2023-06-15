
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
	char *finalstr;
	int finalstrLen;
	finalstrLen = strLen + (newstrlen - oldstrlen);
	finalstr = (char *)malloc(finalstrLen + 1);
	if (!finalstr)
		return NULL;

	while (str[i] && strncmp(&str[i],oldstr,oldstrlen))
	{
		finalstr[j] = str[i];
		i++;
		j++;
	}
	if (j < finalstrLen)
		strncpy(&finalstr[j], newstr, newstrlen);
	j += newstrlen;
	i += oldstrlen;
	while (str[i])
	{
		finalstr[j] = str[i];
		i++;
		j++;
	}
	finalstr[j] = '\0';
	return finalstr;
}

int main() {
	char str[100] = "hello, world! hello, universe! hello, galaxy!";
	char oldSubstr[] = "hello";
	char newSubstr[] = "hi";
	char *sttr;

	printf("Before: [%s]\n", str);
	sttr = replace_string(str, oldSubstr, newSubstr);
	printf("After: [%s]\n", sttr);

	return 0;
}