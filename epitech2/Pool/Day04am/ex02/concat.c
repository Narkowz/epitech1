/*
** EPITECH PROJECT, 2025
** concat.c Ex02
** File description:
** Ex 02 of Day04am of the pool Tech2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concat.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strcat(char **str1, char *str2)
{
    size_t len1 = strlen(*str1);
    size_t len2 = strlen(str2);
    size_t newLength = len1 + len2 + 1;
    char *result = malloc(sizeof(char) * newLength);

    if (result != NULL) {
        strcpy(result, *str1);
        free(*str1);
        *str1 = result;
        for (size_t i = 0; i < len2; ++i)
            (*str1)[len1 + i] = str2[i];
        (*str1)[len1 + len2] = '\0';
    }
    return *str1;
}

void concat_strings(const char *str1, const char *str2, const char **result)
{
    size_t newLength = strlen(str1) + strlen(str2) + 1;

    *result = malloc(sizeof(char) * newLength);
    if (*result != NULL) {
        my_strcpy(*result, str1);
        my_strcat(result, str2);
    }
}

void concat_struct(concat_t *str)
{
    concat_strings(str->str1, str->str2, &str->res);
}


// static void test_concat_struct ( void )
// {
//     char str1[] = "";
//     char str2[] = " you're looking for.";
//     concat_t str = {
//     .str1 = str1,
//     .str2 = str2,
//     .res = NULL
//     };

//     concat_struct(&str);
//     printf("%s\n", str.res);
//     free(str.res);
// }

// void test_concat_strings ( void )
// {
//     char str1 [] = "";
//     char str2 [] = " disturbing.";
//     char * res = NULL ;
//     concat_strings ( str1 , str2 , & res ) ;
//     printf ("%s\n", res ) ;
//     free ( res ) ;
// }

// void main ( void )
// {
//     test_concat_strings();
//     test_concat_struct();
// }
