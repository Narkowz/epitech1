#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linked_list {
    char *data;
    struct linked_list *next;
};

void swap(struct linked_list *a, struct linked_list *b) {
    char *temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubble_sort(struct linked_list *list) {
    int swapped;
    struct linked_list *ptr;

    if (list == NULL)
        return;

    do {
        swapped = 0;
        ptr = list;

        while (ptr->next != NULL) {
            if (strcmp(ptr->data, ptr->next->data) > 0) {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}

void print_and_free(struct linked_list *head) {
    struct linked_list *current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        struct linked_list *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
}

int main(void) {
    char *arr[] = {"bonjour", "je", "suis", "un", "test", "aaaab", "aaaac"};

    struct linked_list *head = malloc(sizeof(struct linked_list));
    struct linked_list *current = head;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        current->data = strdup(arr[i]);
        if (i < sizeof(arr) / sizeof(arr[0]) - 1) {
            current->next = malloc(sizeof(struct linked_list));
            current = current->next;
        } else {
            current->next = NULL;
        }
    }

    bubble_sort(head);

    print_and_free(head);

    return 0;
}
