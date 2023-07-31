#include <libc.h>

int main(int ac, char **av, char **env)
{
    char *path_n = "/bin/ls";
    char *envp[] = {NULL};
    char *argv[] = {"ls", "-l", NULL};
    if (execve(path_n, argv, envp) == -1)
        exit(1);
    return 0;
}
