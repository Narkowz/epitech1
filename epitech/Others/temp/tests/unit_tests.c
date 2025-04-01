/*
** EPITECH PROJECT, 2023
** test_d.c
** File description:
** test d
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_printf(const char *, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout() ;
    cr_redirect_stderr() ;
}

Test (my_printf, testing_negative_i, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%i", -875);
    my_printf("%i", -875);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_positive_i, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%i", 875);
    my_printf("%i", 875);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_positive_d, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%d", 875);
    my_printf("%d", 875);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_negative_d, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%d", -875);
    my_printf("%d", -875);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_positive_x, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%x", 875);
    my_printf("%x", 875);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_negative_x, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%x", -875);
    my_printf("%x", -875);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_c, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%c", '@');
    my_printf("%c", '@');
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_positive_f, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%f", 875.97854512);
    my_printf("%f", 875.97854512);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_negative_f, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%f", -875.97854512);
    my_printf("%f", -875.97854512);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_nan_f, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%f", 'a');
    my_printf("%f", 'a');
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_inf_f, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%f", 1.0/0.0);
    my_printf("%f", 1.0/0.0);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_nan_up_f, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%F", 'a');
    my_printf("%F", 'a');
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_inf_up_f, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%F", 1.0/0.0);
    my_printf("%F", 1.0/0.0);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_positive_o, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%o", 875);
    my_printf("%o", 875);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_negative_o, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%o", -875);
    my_printf("%o", -875);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_short_string_s, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%s", "a");
    my_printf("%s", "a");
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_long_string_s, .init=redirect_all_std)
{
    char temp[435];
    sprintf(temp, "%s", "This is a string with %d complex \\\"special characters\\\" and a mixture of escape sequences like \\n newlines, \\t tabs, and even color codes \x1b[31mred\x1b[0m and \x1b[32mgreen\x1b[0m. Additionally, it includes various symbols such as !@#$%^&*()_+{}|:\"<>? and a significantly long text that goes on and on and on with seemingly no end, providing a mind-boggling challenge for printing with printf using the %%s format specifier.");
    my_printf("%s", "This is a string with %d complex \\\"special characters\\\" and a mixture of escape sequences like \\n newlines, \\t tabs, and even color codes \x1b[31mred\x1b[0m and \x1b[32mgreen\x1b[0m. Additionally, it includes various symbols such as !@#$%^&*()_+{}|:\"<>? and a significantly long text that goes on and on and on with seemingly no end, providing a mind-boggling challenge for printing with printf using the %%s format specifier.");
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_pointer_int_p, .init=redirect_all_std)
{
    char temp[20];
    int num = 25;
    void* ptr = &num;
    sprintf(temp, "%p", ptr);
    my_printf("%p", ptr);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_positive_scientific_e, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%e", 45876.32);
    my_printf("%e", 45876.32);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_negative_scientific_e, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%e", -45876.32);
    my_printf("%e", -45876.32);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_positive_scientific_up_e, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%E", 45876.32);
    my_printf("%E", 45876.32);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_negative_scientific_up_e, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%E", -45876.32);
    my_printf("%E", -45876.32);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_percentage, .init=redirect_all_std)
{
    char temp[20];
    sprintf(temp, "%%");
    my_printf("%%");
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_positive_unsigned_u, .init=redirect_all_std)
{
    char temp[20];
    unsigned int unsigned_num = 65535;
    sprintf(temp, "%u", unsigned_num);
    my_printf("%u", unsigned_num);
    cr_assert_stdout_eq_str(temp);
}

Test (my_printf, testing_negative_unsigned_u, .init=redirect_all_std)
{
    char temp[20];
    unsigned int b = -20;
    sprintf(temp, "%u", b);
    my_printf("%u", b);
    cr_assert_stdout_eq_str(temp);
}
