/*
** EPITECH PROJECT, 2023
** Rush2
** File description:
** Rush2
*/

int lenght(char *str)
{
    int i;
    int k = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            k++;
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            k++;
        }
    }
    return k;
}

int frequencies(int a, char **argv)
{
    int len = lenght(argv[1]);
    long frequencies = 0;

    frequencies = (a * 100) / len;
    return (frequencies);
}

int display(int temp, char **argv, int q, int fr)
{
    int a = (q * 10000) / lenght(argv[1]) %100;

    my_putstr(argv[temp]);
    my_putchar(':');
    my_put_nbr(q);
    my_putchar(' ');
    my_putchar('(');
    my_put_nbr(fr);
    my_putchar('.');
    my_put_nbr(a);
    if (a == 0)
        my_put_nbr(0);
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');
}

int count_numbers(int temp, char **argv)
{
    int i = 0;
    int a = 0;

    while (argv[1][i] != '\0') {
        if (argv[1][i] == argv[temp][0] || argv[1][i] == argv[temp][0] + 32
            || argv[1][i] == argv[temp][0] - 32 && argv[1][i] > 65) {
            a++;
        }
        i++;
    }
    return (a);
}

int main(int argc, char **argv)
{
    int q;
    int temp = 2;
    int fr;

    for (; temp < argc; temp++) {
        q = count_numbers(temp, argv);
        fr = frequencies(q, argv);
        display(temp, argv, q, fr);
    }
    return (0);
}
