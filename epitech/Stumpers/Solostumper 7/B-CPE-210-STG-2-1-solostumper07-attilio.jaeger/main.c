/*
** EPITECH PROJECT, 2024
** anagram
** File description:
** anagram
*/

#include "include/my.h"
#include <unistd.h>

int loop_for_ascii(char *str, char *st2, int i)
{
    int count_str = 0;
    int count_str2 = 0;

    for (int l = 0; str[l] != '\0'; l++)
        if (str[l] == str[i] || (str[l] >= 'A' && str[l] <= 'Z' &&
        str[l] + 32 == str[i]) || (str[l] >= 'a' && str[l] <= 'z' &&
        str[l] - 32 == str[i])) {
            count_str++;
        }
    for (int l = 0; st2[l] != '\0'; l++)
        if (st2[l] == str[i] || (st2[l] >= 'A' && st2[l] <= 'Z' &&
            st2[l] + 32 == str[i]) ||
            (st2[l] >= 'a' && st2[l] <= 'z' && st2[l] - 32 == str[i])) {
            count_str2++;
        }
    if (count_str2 != count_str)
        return 1;
    else
        return 0;
}

int test_all_ascii(char *str, char *str2)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (loop_for_ascii(str, str2, i) != 0)
            return 1;
    return 0;
}

int test_condition(char *str, int i, char *str2, int *count)
{
    for (int l = 0; str2[l] != '\0'; l++) {
        if (str[i] == str2[l] || str[i] - 32 == str2[l] ||
            str[i] + 32 == str2[l]) {
            (*count)++;
            break;
        }
    }
}

int start_process(char *str, char *str2)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        test_condition(str, i, str2, &count);
        if (count != (i + 1))
            return 1;
    }
    if (count == my_strlen(str) && count == my_strlen(str2) &&
        my_strlen(str) == my_strlen(str2))
        return 0;
    else
        return 1;
}

int main(int ac, char **av)
{
    if (ac < 3) {
        write(2, "Error: not enough arguments.\n", 29);
        return 84;
    }
    if (ac > 3) {
        write(2, "Error: too many arguments.\n", 27);
        return 84;
    }
    if (start_process(av[1], av[2]) == 0 && test_all_ascii(av[1], av[2]) == 0)
        write(1, "anagram!\n", 9);
    else
        write(1, "no anagrams.\n", 13);
    return 0;
}
