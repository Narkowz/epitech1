
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av, char **env)
{
    if (env == NULL)
        printf("test");
    for (int i = 0; env[i] != NULL; i++)
        printf("%s\n", env[i]);
}