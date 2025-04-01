/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** idk
*/

#ifndef MY
    #define MY
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdarg.h>
    #include <dirent.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct champion_s {
    char prog_name[PROG_NAME_LENGTH + 1];
    int load_adress;
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
    struct champion_s *next;
} champion_t;

typedef enum Traduction_s {
    LIVE = 0x01,
    LD = 0x02,
    ST = 0x03,
    ADD = 0x04,
    SUB = 0x05,
    AND = 0x06,
    OR = 0x07,
    XOR = 0x08,
    ZJMP = 0x09,
    LDI = 0x0a,
    STI = 0x0b,
    FORK = 0x0c,
    LLD = 0x0d,
    LLDI = 0x0e,
    LFORK = 0x0f,
    AFF = 0x10
} Traduction_t;

typedef struct Flags_s {
    int cd;
    int env;
    int exit;
    int setenv;
    char format;
    int unsetenv;
    int last_return_val;
} Flags_t;

typedef struct sFlags_s {
    int dash;
    int tilde;
    char format;
} sFlags_t;

int my_isneg(int nb);
int fake_f(double nb);
int fake_f(double nb);
int fake_e(double nb);
int fake_e(double nb);
void my_putchar(char c);
void my_put_nbr(int nb);
int my_is_prime(int nb);
void my_put_nbr(int nb);
void my_putchar(char c);
int fake_f_bis(double nb);
int fake_e_bis(double nb);
char *my_revstr(char *str);
int lowcase_o_bis(long nb);
int lowcase_u_bis(long nb);
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
int lowcase_x(va_list args);
int uppcase_x(va_list args);
int lowcase_p(va_list args);
int lowcase_g(va_list args);
int lowcase_u(va_list args);
int lowcase_o(va_list args);
int uppcase_g(va_list args);
void my_swap(int *a, int *b);
int my_find_is_prime(int nb);
void fake_print_first(int i);
int low_percent(va_list args);
char *my_strdup(const char *);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_getnbr(char const *str);
int my_putstr(char const *str);
int supplines(double nb, int n);
void fake_print_first_bis(int i);
int my_compute_square_root(int nb);
int supplines_bis(double nb, int n);
char *my_strchr(const char *s, int c);
char *my_strrchr(const char *s, int c);
char *my_strcat(char *dest, char *src);
int my_printf(const char *format, ...);
void my_sort_in_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
char **my_str_to_word_array(const char *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
void my_memset(void *dest, int c, size_t count);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_fgets(char *str, int num, FILE *stream);
int my_fgetc(FILE *stream);

int print_h(void);
// int validate_file(char *filename, char **av);
// int check_args(int ac, char **av);
// int validate_header_line(const char *line, const char *directive, char **av,
//     header_t *Iden);
// int create_cor(int ac, char **av);
// void send_name(header_t *Iden, char **av);
// char *extract_quoted_string(const char *line);

struct Flag {
    char format;
    int (*fonction) (va_list);
};

#endif /* MY */
