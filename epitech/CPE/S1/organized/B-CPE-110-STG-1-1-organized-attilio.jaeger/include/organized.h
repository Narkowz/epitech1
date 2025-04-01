/*
** EPITECH PROJECT, 2023
** organized.h
** File description:
** organized
*/

#include <stdarg.h>
#include <stddef.h>

#ifndef ORGANIZED_H_
    #define ORGANIZED_H_

typedef enum {
    ACTUATOR,
    DEVICE,
    PROCESSOR,
    SENSOR,
    WIRE
} type_t;

typedef struct my_data_s {
    type_t type;
    int id;
    char *name;
    int count;
    struct my_data_s *next;
} my_data_t;

char *tab_type(type_t type);
int test(my_data_t **data, char *args, type_t type);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
int type(char type, va_list args);
int print(char const *str, va_list args);
int mini_printf(const char *format, ...);
void my_put_nbr(int nb);
int put_nbr(int n);
int put_nbr1(int n);
void my_putchar(char c);
int my_putstr(char const *str);
void del_fun(my_data_t **current, my_data_t *prev, char *args,
    my_data_t **data);
int get_nbr(char *av);
void free_list(my_data_t *data);
void little_if_id(my_data_t **pivo, my_data_t **changer, my_data_t **temp);
void quick_sort_id(my_data_t **data, char **args);
void little_if_name(my_data_t **pivo, my_data_t **changer, my_data_t **temp);
void quick_sort_name(my_data_t **data, char **args);
void little_if_type(my_data_t **pivo, my_data_t **changer, int *temp);
void quick_sort_type(my_data_t **data, char **args);
void little_if_id_reverse(my_data_t **pivo, my_data_t **changer, int *temp);
void quick_sort_id_reverse(my_data_t **data, char **args);
void reverse(my_data_t **data);

#endif /* !ORGANIZED_H_ */
