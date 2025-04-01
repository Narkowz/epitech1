/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

typedef struct linked_list {
    sfCircleShape *circle;
    struct linked_list *next;
} linked_list_t;

typedef struct window {
    sfRenderWindow *window;
    sfEvent event;
} window_t;

typedef struct corner {
    sfIntRect area;
} corner_t;

float power_rec(float nb, float power);

#endif /* !MY_H_ */
