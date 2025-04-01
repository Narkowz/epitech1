/*
** EPITECH PROJECT, 2023
** my_print_params.c
** File description:
** print params
*/

void my_putchar_1(char c)
{
    write(1, &c, 1);
}

int my_putstr_1(char const *str)
{
    int i = 0;
    char c;

    for (; str[i] != '\0' ; i++) {
        c = str[i];
        my_putchar_1(c);
    }
    return 0;
}

int main(int argc, char **argv[])
{
    int i = 0;

    for (;i != argc; i++) {
        my_putstr_1(argv[i]);
        my_putchar_1('\n');
    }
    return 0;
}
