/*
** EPITECH PROJECT, 2024
** secured.h
** File description:
** secured
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SECURED_H_
    #define SECURED_H_

typedef struct list_s {
    char *value;
    int key;
    char *key_string;
    struct list_s *next;
} list_t;

typedef struct hashtable_s {
    int size;
    int (*hash)(char *, int);
    list_t **hashtable;
} hashtable_t;

int hash(char *key, int len);
void ht_dump(hashtable_t *ht);
char *ht_search(hashtable_t *ht, char *key);
int ht_insert(hashtable_t *ht, char *key, char *value);
void delete_hashtable(hashtable_t *ht);
int ht_delete(hashtable_t *ht, char *key);
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *ht_search(hashtable_t *ht, char *key);
int my_strcmp(char const *s1, char const *s2);

#endif /* !SECURED_H_ */
