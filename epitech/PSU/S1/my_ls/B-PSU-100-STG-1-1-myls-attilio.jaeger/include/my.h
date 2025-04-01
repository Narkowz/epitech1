/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my lib
*/

#ifndef MY_H_
    #define MY_H_

    #include <stddef.h>
    #include <stdarg.h>
    #include <dirent.h>
struct linked_list {
    char *name;
    struct linked_list *next;
};

void swap(struct linked_list *a, struct linked_list *b);
void first_if(struct linked_list *ptr, int *swapped);
int error_handling(char *path);
int identifier_flags(char **flags, int i, int ac);
int find_flags(int ac, char **str, int i);
char *my_revstr(char *str);
void free_list(struct linked_list *list);
int my_strcmp(char const *s1, char const *s2);
void my_put_in_list(struct linked_list **list, char *path);
int my_strncmp(char const *s1, char const *s2, size_t n);
void my_show_list(struct linked_list *list);
int structlength(struct linked_list *list);
int sort_by_reverse(char **str, int i, int ac);
int my_simple_ls(char *path);
void bubble_sort(struct linked_list *list);
char *my_strdup(char const *src);
int print_list_a(char **str, int i, int ac);
int open_dir_a(char **path, int j, int ac);
void print_a(struct linked_list *list);
static void put_in_list_a(struct linked_list **list, const char *new_word);
int type(char type, va_list args);
int print(char const *str, va_list args);
int mini_printf(const char *format, ...);
void my_put_nbr(int nb);
int put_nbr(int n);
int put_nbr1(int n);
void my_putchar(char c);
int my_putstr(char const *str);
void put_in_list(struct linked_list **list, const char *new_word);
static int open_dir_bis(void);
static void reverse(struct linked_list *list);
int sort_by_reverse(char **str, int i, int ac);
void bubble_sort_bis(struct linked_list *list);
void first_if_bis(struct linked_list *ptr, int *swapped);
void swap_bis(struct linked_list *a, struct linked_list *b);
void print_list(struct linked_list *list);
void whilee(struct linked_list **list, struct dirent *entries, DIR *dir);
void whilee_bis(struct linked_list **list, struct dirent *entries, DIR *dir);
static int open_dir(char **path, int j, int ac);

#endif
