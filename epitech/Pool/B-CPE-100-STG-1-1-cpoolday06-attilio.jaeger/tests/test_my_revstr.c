/*
** EPITECH PROJECT, 2023
** test_my_revstr.c
** File description:
** rev str
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, copy_five_characters_in_empty_array)
{
    char dest[11] = "HelloWorld";

    my_revstr(dest);
    cr_assert_str_eq(dest, "dlroWolleH");
}
