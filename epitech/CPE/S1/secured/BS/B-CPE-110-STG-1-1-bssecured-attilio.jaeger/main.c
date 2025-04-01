/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bootstrap.h"

entry_t **create_adress_book(int len)
{
    entry_t **book = malloc(sizeof(entry_t *) * len);
    return book;
}

entry_t *create_address(char *name, char *phone_number)
{
    entry_t *book = malloc(sizeof(entry_t));

    book->name = strdup(name);
    book->phone_number = strdup(phone_number);
    return book;
}

entry_t **add_address(entry_t **adress_book, int size, char *name, char *phone_number)
{
    entry_t **book = adress_book;
    for (int i = 0; i < size; i++) {
        if (book[i]->name == NULL && book[i]->phone_number == NULL)
        book[i] = create_address(name, phone_number);
    }
    printf("%s\n", (*book)->name);
    printf("new address added\n");
}

int main(void)
{
    int size = 5;
    entry_t **address_book = create_adress_book(size);

    printf("address book created\n");
    add_address(address_book, size, "Kevin", "55 55");
    add_address(address_book, size, "Poulet", "55 55");
    // printf("%s - ", (*address_book)->name);
    // printf("%s\n", (*address_book)->phone_number);
    return 0;
}
