/*
** EPITECH PROJECT, 2024
** ht_dump.c
** File description:
** ht_dump
*/

#include "include/secured.h"

void ht_dump(hashtable_t *ht)
{
    list_t **temp;
    list_t *head;
    int i = 0;

    if (!ht)
        return;
    temp = ht->hashtable;
    for (; i < ht->size; i++) {
        printf("[%d]:\n", i);
        head = temp[i];
        while (head != NULL) {
            printf("> %d - %s\n", head->key, head->value);
            head = head->next;
        }
    }
}
