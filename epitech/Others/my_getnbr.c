/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** get nbr
*/

int my_getnbr(char const *str)
{
    int len = my_strlen(str);
    int i = 0;
    int tmp = 0;

    for (;i < len; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            tmp = (str[i]-48)*10;
        }
    }
    return (tmp);
}

void main(void)
{
    char str[2]="12";
    my_put_str(str);
}
