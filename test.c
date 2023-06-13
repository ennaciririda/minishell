
#include "minishell.h"
#include <stdio.h>
#include <string.h>

void replaceString(char *str, const char *oldSubstr, const char *newSubstr) {
	char *tempStr = strstr(str, oldSubstr);
	size_t oldSubstrLen = strlen(oldSubstr);
	size_t newSubstrLen = strlen(newSubstr);
	size_t diff = newSubstrLen - oldSubstrLen;

	while (tempStr)
	{
		memmove(tempStr + newSubstrLen, tempStr + oldSubstrLen, strlen(tempStr + oldSubstrLen) + 1);
		memcpy(tempStr, newSubstr, newSubstrLen);
		tempStr = strstr(tempStr + newSubstrLen, oldSubstr);
		str = str + diff;
	}
}

int main() {
	char str[100] = "hi, world! hi, universe! hi, galaxy!";
	const char oldSubstr[] = "Hello";
	const char newSubstr[] = "Hi";

	printf("Before: %s\n", str);
	replaceString(str, oldSubstr, newSubstr);
	printf("After: %s\n", str);

	return 0;
}