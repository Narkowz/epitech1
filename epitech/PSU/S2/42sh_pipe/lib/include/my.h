/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** my
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef MY_H
    #define MY_H

//______________Lib Function______________//

// Alloc
char *my_alloc_str(int size);
char **my_alloc_tab(int size);

// Char content check
int my_isalphanumeric(char c);

// Free
void my_free_tab(char **tab);

// Print
int my_putchar(char c, int fd);
void my_print_tab(char **tab, int fd);
int my_putstr(char const *str, int fd);
int my_putstr_return(char *str, int fd, int val);

// Str content check
int my_count_char(char *str, char c);
int my_locate_char(char *str, char c);
int my_count_char_alone(char *str, char c);

// Str manipulation
char **recut_delim(char **tab);
int my_getnbr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char const *src);
char *my_strcat(char *s1, char *s2);
char *cut_at_char(char *str, char c);
char **my_str_to_word_array(char *str);
char *my_strcalloc(char *s1, char *s2);
char *delete_char(char *str, int index);
char *my_cleanstr(char *str, char *sep);
char *my_str_combine(char *str, char *str2);
char *my_strncat(char *s1, char *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *add_char(char *str, int index, char c);
char **simple_str_to_array(char *str, char c);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char *src, int n);
char *my_str_slice(char *line, int start, int end);
int my_strstr_delay(char *str, char *to_find, int pos);

// Tab manipulation
int my_tab_len(char **tab);
int my_putnbr(long long nbr, int fd);
char **my_tab_ncpy(char **tab, int n);
void append(char ***arr, char *new_str);
char **my_tab_add(char **tab, char *add);
char **my_delete_from_tab(char **tab, int i);

#endif
