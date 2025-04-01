/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-titouan.pradoura
** File description:
** my_locate_char.c
*/

int my_locate_char(char *str, char c)
{
    if (!str)
        return -1;
    for (int i = 0; str && str[i]; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}
