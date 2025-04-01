/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** get nbr
*/

int my_getnbr(char const str)
{
    long  n = 0;
    int i;
    int temp;
    int sign = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign= -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        temp = str[i] - 48;
        n = n * 10;
        n = n + temp;
        i++;
        if ((n * sign <= -2147483649) || (n * sign > 2147483647))
            return (0);
    }
    return (n * sign);
}
