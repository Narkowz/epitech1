/*
** EPITECH PROJECT, 2023
** test_d.c
** File description:
** test d
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

const char *str = "Hello world!\n";
const int len = 11;

Test(test, test)
{
    cr_assert(strlen(str) == len);
}
