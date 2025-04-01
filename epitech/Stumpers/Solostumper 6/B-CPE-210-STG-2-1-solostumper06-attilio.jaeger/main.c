/*
** EPITECH PROJECT, 2024
** Text-to-multi-tap
** File description:
** text
*/

#include <unistd.h>

int test_characters(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < 'a' || str[i] > 'z') && str[i] != ' ')
            return 84;
    return 0;
}

void write_loop(char car, int n, int *num)
{
    if (*num == car)
        write(1, " ", 1);
    *num = car;
    for (int i = 0; i != n; i++)
        write(1, &car, 1);
}

void first_if(char *str, int i, int *num)
{
    if (str[i] == 'a' || str[i] == 'b' || str[i] == 'c')
        write_loop('2', str[i] - 96, num);
    if (str[i] == 'd' || str[i] == 'e' || str[i] == 'f')
        write_loop('3', str[i] - 99, num);
    if (str[i] == 'g' || str[i] == 'h' || str[i] == 'i')
        write_loop('4', str[i] - 102, num);
    if (str[i] == 'j' || str[i] == 'k' || str[i] == 'l')
        write_loop('5', str[i] - 105, num);
    if (str[i] == 'm' || str[i] == 'n' || str[i] == 'o')
        write_loop('6', str[i] - 108, num);
}

void operating_algorithm(char *str)
{
    int num = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            write(1, "#", 1);
            str[i] = str[i] + 32;
            num = 0;
        }
        first_if(str, i, &num);
        if (str[i] == 'p' || str[i] == 'q' || str[i] == 'r' || str[i] == 's')
            write_loop('7', str[i] - 111, &num);
        if (str[i] == 't' || str[i] == 'u' || str[i] == 'v')
            write_loop('8', str[i] - 115, &num);
        if (str[i] == 'w' || str[i] == 'x' || str[i] == 'y' || str[i] == 'z')
            write_loop('9', str[i] - 118, &num);
        if (str[i] == ' ')
            write(1, "0", 1);
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if (ac < 2 || ac > 2)
        return 84;
    if (test_characters(av[1]) != 0)
        return 84;
    operating_algorithm(av[1]);
    return 0;
}
