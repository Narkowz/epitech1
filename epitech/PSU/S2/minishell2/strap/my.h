/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

char **my_str_to_word_array(char *env, char **path);

#endif /* !MY_H_ */
