/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** idk
*/

#ifndef MY
    #define MY
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdarg.h>

typedef struct temp_s {
    char temps;
    char temps_bis;
    char temps_x;
    char temps_x_bis;
    int key;
} temp_t;

void my_putchar(char c);
int my_isneg(int nb);
void my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_in_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_is_prime(int nb);
int my_compute_square_root(int nb);
int my_find_is_prime(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_printf(const char *format, ...);
void my_putchar(char c);
void my_put_nbr(int nb);
int my_putstr(char const *str);
int fake_e(double nb);
int fake_f(double nb);
int lowcase_e(va_list args);
int lowcase_f(va_list args);
int uppcase_e(va_list args);
int uppcase_f(va_list args);
int lowcase_o(va_list args);
int lowcase_u(va_list args);
int lowcase_s(va_list args);
int lowcase_d(va_list args);
int lowcase_i(va_list args);
int lowcase_c(va_list args);
int low_percent(va_list args);
int lowcase_x(va_list args);
int uppcase_x(va_list args);
int lowcase_p(va_list args);
int lowcase_g(va_list args);
int uppcase_g(va_list args);
int supplines_bis(double nb, int n);
int fake_f_bis(double nb);
void fake_print_first_bis(int i);
int fake_e_bis(double nb);
int supplines(double nb, int n);
int fake_f(double nb);
void fake_print_first(int i);
int fake_e(double nb);
int lowcase_u(va_list args);
int lowcase_u_bis(long nb);
int lowcase_o(va_list args);
int lowcase_o_bis(long nb);
int file_checker(char **av, char *buf);
char *analyzer(char *buf, int i, int j);
int transcriptor(char **av, char *buf);
int transcriptor_reverse(char **av, char *buf, int j);
int recursive(int ac, char **av, int j, int *compt);
int flags(int ac, char **av, int *compt, int j);
int av_non_null(int ac, char **av, int j, int *compt);
void touch(char *buffer, int pos, int lon, temp_t *temp);
char *go_left(temp_t *temp, char *buffer, int pos);
char *go_right(temp_t *temp, char *buffer, int pos);
char *go_up(temp_t *temp, char *buffer, int pos, int lon);
char *go_down(temp_t *temp, char *buffer, int pos, int lon);
int help(int ac, char **av);
int check_file(char *buf);
int check_win(char *buffer);
int leeft(char *buffer, temp_t *temp, int pos);
int riight(char *buffer, temp_t *temp, int pos);
int uup(char *buffer, temp_t *temp, int pos, int lon);
int doown(char *buffer, temp_t *temp, int pos, int lon);

struct Flag {
    char format;
    int (*fonction) (va_list);
};

#endif /* MY */
