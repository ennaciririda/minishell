
#include "minishell.h"
#include <stdio.h>
#include <string.h>

int main() {
	char *str= "rida";
	int fd = open(str, O_RDWR | O_CREAT | O_APPEND, 0777);
	if (fd < 0)
		printf("erro");
	write(fd,"hello rida\n", 11);
	return 0;
}