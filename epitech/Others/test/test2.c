#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word_list {
    char *word;
    struct word_list *next;
};

void reverse_word_list(struct word_list **head) {
    struct word_list *prev = NULL;
    struct word_list *current = *head;
    struct word_list *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void print_word_list(struct word_list *head) {
    printf("Word List: ");
    while (head != NULL) {
        printf("%s ", head->word);
        head = head->next;
    }
    printf("\n");
}

void append_word(struct word_list **head, const char *new_word) {
    struct word_list *new_node = (struct word_list *)malloc(sizeof(struct word_list));
    new_node->word = strdup(new_word);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct word_list *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

int main() {
    struct word_list *head = NULL;

    append_word(&head, "Bonjour");
    append_word(&head, "mon");
    append_word(&head, "ami");
    print_word_list(head);
    reverse_word_list(&head);
    print_word_list(head);
    return 0;
}
