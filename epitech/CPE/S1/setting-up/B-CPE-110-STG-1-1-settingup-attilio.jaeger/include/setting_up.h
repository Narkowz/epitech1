/*
** EPITECH PROJECT, 2023
** setting_up.h
** File description:
** setting_up
*/

#include <unistd.h>
#include <stdarg.h>

#ifndef SETTING_UP_H_
    #define SETTING_UP_H_

typedef struct data_s {
    int lines;
    int cols;
    int a;
    int b;
    int highest;
}data_t;

char *opening_file(char *path);
int number_of_lines(char *map);
char *allocate_line_memory(char *line, int char_count);
char **put_in_2d_list(char *map);
void print_2d(char **twod_map);
void free_2d_map(char **twod_map);
int **prepare_square(char **map);
static int int_first_line_y(char **map, int **int_map, int lines);
static int int_first_line_x(char **map, int **int_map);
int count_cols(char **map);
int count_lines(char **map);
void operating_square(int **int_map, char **twod_map);
char **find_square(char **map, int **int_map);
char **print_x_square(char **map, data_t *data);
int highest_possible_square(int **int_map, int x, int y, data_t *data);
int mini_printf(const char *format, ...);
int print(char const *str, va_list args);
int type(char type, va_list args);
void my_putchar(char c);
void my_put_nbr(int nb);
int put_nbr(int n);
int put_nbr1(int n);
int my_putstr(char const *str);
char *generating_square(char *map, char **av, int ac, char *pattern);
int get_nbr(char **av);

#endif /* !SETTING_UP_H_ */
