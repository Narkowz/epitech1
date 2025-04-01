/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

int main(void)
{
    char str[] = "+++++------+-+-48";
    char dest[100000000];

    *dest = my_getnbr(str);
    printf("%s", dest);
    return (0);
}
