/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** my_lib.h
*/

#ifndef MY_LIB_H
    #define MY_LIB_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

//string handling
char *my_sanitizestr(char *dirty_str);
char *extract_after_char(const char *str, char c);
int my_atoi(const char *str);
int my_isdigit(int ch);
int my_isalpha(const char *str);
int my_strlen(const char *str);
void my_putchar(char c);
void my_putstr(char *str);
void my_puterror(char *str);
void my_strcpy(char *dest, const char *src);
void my_strncpy(char *dest, const char *src, int n);
char *my_strcat(char *dest, const char *src);
char *my_strdup(const char *str);
int my_strcmp(const char *str1, const char *str2);
int my_strncmp(const char *str1, const char *str2, size_t n);
size_t my_strcspn(const char *s, const char *reject);
char *my_strchr(const char *s, int c);
void my_putnbr(int n);
char *my_strndup(const char *str, size_t n);
int my_isin(char *str, char c);
int my_isspace(int c);
int my_get_char_count(char *str, char c);

#endif
