/*
** EPITECH PROJECT, 2025
** init_list.h
** File description:
** Header of init_list (ex00) in Day04pm
*/

#ifndef INIT_LIST_H_
    #define INIT_LIST_H_

typedef struct int_list_s {
    int value;
    struct int_list_s *next;
} int_list_t;

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem);
void int_list_dump(int_list_t *list);
unsigned int int_list_get_size(int_list_t *list);
bool int_list_is_empty(int_list_t *list);
void int_list_clear(int_list_t **front_ptr);
bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem);
bool int_list_add_elem_at_position(int_list_t **front_ptr, int elem,
    unsigned int position);
int int_list_get_elem_at_front(int_list_t *list);
int int_list_get_elem_at_back(int_list_t *list);
int int_list_get_elem_at_position(int_list_t *list, unsigned int position);
bool int_list_del_elem_at_front(int_list_t **front_ptr);
bool int_list_del_elem_at_back(int_list_t **front_ptr);
bool int_list_del_elem_at_position(int_list_t **front_ptr,
    unsigned int position);

#endif /* !INIT_LIST_H_ */
