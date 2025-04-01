/*
** EPITECH PROJECT, 2024
** new_hashtable.c
** File description:
** new_hashtable
*/

#include "include/secured.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *temp;
    int i = 0;

    if (len <= 0)
        return NULL;
    temp = malloc(sizeof(hashtable_t));
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

    ht_dump(ht);
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_dump(ht);
    ht_search(ht, "Vision");
    ht_delete(ht, "Kratos");
    ht_dump(ht);
    delete_hashtable(ht);
    return 0;
}
