/*
** EPITECH PROJECT, 2023
** print_n.c
** File description:
** 
*/

int my_strnlen(char const *str, int n)
{
    int i = 0;

    while (str[i] != '\0' && i < n)
        i++;
    printf("%d 5", i);
    return (i);
}

int print_n(char *str)
{
    int nb = 8;
    int len = 0;
    len = my_strnlen(&str, nb);
    printf("\n%d", len);
    my_put_nbr(len);
}


int main(void)
{
    int n;
    char str[8] = "bonjour";
    print_n(&str);
    my_putchar('\n');
    printf("bonjour %n non", &n);
    printf(" %d", n);
    return 0;
}
