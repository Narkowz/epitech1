/*
** EPITECH PROJECT, 2023
** test_mini_printf.c
** File description:
** test my mini printf 
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
//#include "/include/my.h"

void redirect_all_std(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test (mini_printf, simple_string, .init = redirect_all_std)
{
mini_printf("hello world");
cr_assert_stdout_eq_str("hello world");
}
