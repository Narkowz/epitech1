/*
** EPITECH PROJECT, 2023
** my_print_params.c
** File description:
** print params
*/

void my_putchar_2(char c)
{
    write(1, &c, 1);
}

int my_putstr_2(char const *str)
{
    int i = 0;
    char c;

    for (; str[i] != '\0' ; i++) {
        c = str[i];
        my_putchar_2(c);
    }
    return 0;
}

int main(int argc, char **argv[])
{
    int i = argc - 1;

    for (;i >= 0; i--) {
        my_putstr_2(argv[i]);
        my_putchar_2('\n');
    }
    return 0;
}
