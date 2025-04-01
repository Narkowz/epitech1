/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-bsnavy-raphael.petrequin
** File description:
** my_crocus
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef CROCUS_H_
    #define CROCUS_H_

    #define ZERO " 000 \n0   0\n0   0\n0   0\n 000 \0"
    #define ONE " 000 \n0 00 \n  00 \n  00 \n 0000\0"
    #define TWO " 000 \n0   0\n   0 \n 0   \n00000\0"
    #define THREE "0000 \n    0\n 000 \n    0\n0000 \0"
    #define FOUR "  00 \n 0 0 \n0  0 \n00000\n   0 \0"
    #define FIVE "00000\n0    \n0000 \n    0\n0000 \0"
    #define SIX " 000 \n0    \n0000 \n0   0\n 000 \0"
    #define SEVEN "00000\n    0\n   0 \n  0  \n 0   \0"
    #define EIGHT " 000 \n0   0\n 000 \n0   0\n 000 \0"
    #define NINE " 000 \n0   0\n 0000\n    0\n 000 \0"

int my_isalpha(char c);
int my_isnum(char c);
int handle_error(int ac, char **av);
char **my_str_to_word_array(const char *str, char **tab);
int add_word_to_string(char *source, char *word, char **result, char *between);

#endif /* !CROCUS_H_ */
