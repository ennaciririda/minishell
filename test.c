
#include "minishell.h"
#include <stdio.h>
#include <string.h>

void func(int i)
{
	i =10;
}

int main() {

	char *str;
	str = readline("minishell$ ");
	printf("[%s]\n", str);
	return 0;
} 