/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my
*/

#include <unistd.h>
#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_
int mini_printf(const char *format, ...);
void my_putchar(char c);
void my_putnbr(int nb);
int my_putstr(char *str);
int my_strlen(char const *str);
int put_nbr(int n);
int put_nbr1(int n);
int add_word_to_string(char *source, char *word, char **result, char *between);
int my_strncmp(char const *s1, char const *s2, size_t n, size_t start);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);

#endif /* !MY_H_ */
