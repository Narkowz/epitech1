/*
** EPITECH PROJECT, 2025
** concat.h
** File description:
** header file for concat exercice
*/

#ifndef CONCAT_H_
    #define CONCAT_H_

typedef struct concat_s {
    char *str1;
    char *str2;
    char *res;
    struct concat_s *next;
} concat_t;

#endif /* !CONCAT_H_ */
