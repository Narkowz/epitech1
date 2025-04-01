/*
** EPITECH PROJECT, 2024
** ht_delete.c
** File description:
** ht_delete
*/

#include "include/secured.h"

int compare(list_t **head, list_t *prev, list_t *current, char *key)
{
    list_t *tmp;
    int found = 0;

    if (my_strcmp(key, current->key_string) == 0) {
        found += 1;
        if (prev == NULL) {
            tmp = current;
            *head = current->next;
        } else {
            tmp = current;
            prev->next = current->next;
        }
            free(tmp->key_string);
            free(tmp->value);
            free(tmp);
        return 1;
    }
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    list_t *head;
    list_t *prev;
    list_t *current;
    int res = 0;
    int i = 0;

    if (!ht || !key || my_strlen(key) == 0)
        return 84;
    for (; i < ht->size; i++) {
        prev = NULL;
        current = ht->hashtable[i];
        while (current != NULL && compare
            (&ht->hashtable[i], prev, current, key) == 0) {
            prev = current;
            current = current->next;
        }
    }
    if (res != 1)
        return 84;
    return 0;
}

void delete_hashtable(hashtable_t *ht)
{
    list_t *current;
    list_t *tmp;
    int i;

    if (ht == NULL)
        return;
    for (i = 0; i < ht->size; i++) {
        current = ht->hashtable[i];
        while (current && current != NULL) {
            tmp = current;
            current = current->next;
            free(tmp->key_string);
            free(tmp->value);
            free(tmp);
        }
    }
    free(ht->hashtable);
    free(ht);
    return;
}
