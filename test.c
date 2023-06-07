// adsfasd"hhhhhhh'hhhhhhhhhh"asdsdf . | >> 'ggggggg"gggggggg'

#include "minishell.h"

int	main()
{
	char *str = "hello rida";
	int i = 0;
	while(str[i] && str[i] != 'r')
		i++;
	printf("hhhh %c", str[i]);
	return 0;
}