/*
** EPITECH PROJECT, 2025
** string.h
** File description:
** string
*/

#ifndef STRING_H_
    #define STRING_H_

typedef struct string_s {
    char *str;

    void (*assign_c)(struct string_s *this, const char *s);
    void (*assign_s)(struct string_s *this, const struct string_s *str);
    void (*append_s)(struct string_s *this, const struct string_s *ap);
    void (*append_c)(struct string_s *this, const char *ap);
    char (*at)(const struct string_s *this, size_t pos);
    void (*clear)(struct string_s *this);
    int (*length)(const struct string_s *this);
    int (*compare_s)(const struct string_s *this, const struct string_s *str);
    int (*compare_c)(const struct string_s *this, const char *str);
    size_t (*copy)(const struct string_s *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const struct string_s *this);
    int (*empty)(struct string_s *this);
    int (*find_s)(const struct string_s *this, const struct string_s *str,
        size_t pos);
    int (*find_c)(const struct string_s *this, const char *str, size_t pos);
    void (*insert_c)(struct string_s *this, size_t pos, const char *str);
    void (*insert_s)(struct string_s *this, size_t pos,
        const struct string_s *str);
    int (*to_int)(const struct string_s *this);
    char **(*split_c)(const struct string_s *this, char separator);
    struct string_s **(*split_s)(const struct string_s *this, char separator);
    void (*print)(const struct string_s *this);
    void (*join_c)(struct string_s *this, char delim,
        const char *const *array);
    void (*join_s)(struct string_s *this, char delim,
        const struct string_s *const *array);
    struct string_s *(*substr)(const struct string_s *this,
        int offset, int length);

} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_c(string_t *this, const char *s);
void assign_s(string_t *this, const string_t *str);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char string_at(const string_t *this, size_t pos);
void clear(string_t *this);
int length(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);
int to_int(const string_t *this);
char **split_c(const string_t *this, char separator);
string_t **split_s(const string_t *this, char separator);
void print(const string_t *this);
void join_c(string_t *this, char delim, const char *const *array);
void join_s(string_t *this, char delim, const string_t *const *array);
string_t *substr(const string_t *this, int offset, int length);

#endif /* !STRING_H_ */
