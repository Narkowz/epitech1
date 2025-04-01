/*
** EPITECH PROJECT, 2024
** new_hashtable.c
** File description:
** new_hashtable
*/

#include "include/secured.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *temp = malloc(sizeof(hashtable_t));
    int i = 0;

    if (len <= 0)
        return NULL;
    temp->hashtable = malloc(sizeof(list_t *) * (len + 1));
    temp->size = len;
    for (; i < len; i++) {
        temp->hashtable[i] = NULL;
    }
    temp->hashtable[i] = NULL;
    return temp;
}

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "Vision", "ViSion");
    ht_insert(ht, "g", "g");
    ht_insert(ht, "a", "a");
    ht_dump(ht);
    ht_search(ht, "Vision");
    ht_insert(ht, "gee", "gee");
    ht_insert(ht, "gaaa", "gaaa");
    ht_dump(ht);
    free(ht);
    return 0;
}
