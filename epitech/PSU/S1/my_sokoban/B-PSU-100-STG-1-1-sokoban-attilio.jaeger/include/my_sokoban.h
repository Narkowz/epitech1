/*
** EPITECH PROJECT, 2023
** my_sokoban.h
** File description:
** my_sokoban
*/
#include <stdarg.h>

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_

int my_strlen(char const *str);
char *opening_file(char *path);
char *right(char *player, char *copy);
char *left(char *player, char *copy);
char *upward(char *player, char *copy);
char *downward(char *player, char *copy);
int find_player(const char *str);
int mon_strlen(const char *str);
char *test_assets(char *player, char *copy);
static void initialize_game(char *player);
char *in_3d(char *player, int key, char *copy);
int check_event(char *player, char *copy);
char *my_strdup(char const *src);
int check_win(char *player, char *copy);
int error_handling(char *player);
static void without_border_2d(char *player, int i, int key);
static void without_border_1d(char *player, int i, int key);
int line_len_up(char *player, int pos);
int line_len(char *player, int pos);
char *reset(char *player, char *copy);
int type(char type, va_list args);
int print(char const *str, va_list args);
int mini_printf(const char *format, ...);
void my_put_nbr(int nb);
int put_nbr(int n);
int put_nbr1(int n);
void my_putchar(char c);
int my_putstr(char const *str);
void display_usage(void);
int initializing(int ac, char **av);
int check_loose(char *player);

#endif /* !MY_SOKOBAN_H_ */
