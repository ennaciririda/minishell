
#include "minishell.h"

char	*replaceString(char *str, char *oldstr, char *newstr)
{
	int strLen = ft_strlen(str); // len of the string
	int oldstrLen = ft_strlen(oldstr); // len of old word
	int newstrLen = ft_strlen(newstr); // len of new word
	int j = 0;
	int i = 0;
	char *tempStr = str;
	char *finalstr;
	int finalstrLen;
	while ((tempStr = ft_strstr(tempStr, oldstr)) != NULL) {
		i++;
		tempStr += oldstrLen;
	}
	finalstrLen = strLen + (newstrLen - oldstrLen) * i;
	finalstr = (char *)malloc(finalstrLen + 1);
	if (!finalstr)
		return NULL;
	i = 0;
	while (i < strLen)
	{
		if (ft_strncmp(&str[i], oldstr, oldstrLen) == 0)
		{
			ft_strncpy(&finalstr[j], newstr, newstrLen);
			j += newstrLen;
			i += oldstrLen;
		}
		else
		{
			finalstr[j] = str[i];
			j++;
			i++;
		}
	}
	finalstr[j] = '\0';
	return finalstr;
}

int main() {
	char str[100] = "ilyas, world! ilyas, universe! ilyas, galaxy!";
	char oldSubstr[] = "ilyas";
	char newSubstr[] = "mo";
	char *s;

	printf("Before: %s\n", str);
	s = replaceString(str, oldSubstr, newSubstr);
	printf("After: %s\n", s);

	return 0;
}