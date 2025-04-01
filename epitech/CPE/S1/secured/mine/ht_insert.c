/*
** EPITECH PROJECT, 2024
** ht_insert.c
** File description:
** ht_insert
*/

#include "include/secured.h"

list_t *test_if_empty(list_t **ht, char *key, char *value, int keys)
{
    list_t *new_node = malloc(sizeof(list_t));

    new_node->value = my_strdup(value);
    new_node->key_string = my_strdup(key);
    new_node->key = keys;
    new_node->next = *ht;
    *ht = new_node;
    return new_node;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int keys;
    int i;

    if (ht == NULL || key == NULL || value == NULL ||
        my_strlen(key) == 0 || my_strlen(value) == 0)
        return 84;
    keys = hash(key, my_strlen(key));
    i = keys % ht->size;
    ht->hashtable[i] = test_if_empty(&ht->hashtable[i], key, value, keys);
    return 0;
}
