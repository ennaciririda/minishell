
#include "minishell.h"
#include <stdio.h>
#include <string.h>

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