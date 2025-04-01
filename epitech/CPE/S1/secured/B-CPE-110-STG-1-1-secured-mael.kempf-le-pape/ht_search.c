/*
** EPITECH PROJECT, 2024
** ht_search.c
** File description:
** ht_search
*/

#include "include/secured.h"

char *test_search(list_t *head, char *key)
{
    if (my_strcmp(key, head->key_string) == 0)
        return head->value;
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    list_t **temp;
    list_t *head;
    char *find = NULL;
    int i = 0;

    if (!ht || !key || my_strlen(key) == 0)
        return NULL;
    temp = ht->hashtable;
    for (; i < ht->size; i++) {
        head = temp[i];
        while (head != NULL && find == NULL) {
            find = test_search(head, key);
            head = head->next;
        }
    }
    if (find == NULL)
        return NULL;
    printf("Looking for \"%s\": \"%s\"\n", key, find);
    return find;
}
