/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-robotfactory-lois.hattenberger
** File description:
** main
*/

#include "../include/robotfactory.h"

void free_list(char *cont, header_t *content, char **array)
{
    free(cont);
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    return;
}

int start_process(char *cont, char **array, header_t *content, char *name)
{
    open_file(name, &cont);
    array = my_str_to_word_array(cont, array);
    if (test_content(array) != 0)
        return 84;
    if (translate_to_cor(cont, content, array, name) != 0)
        return 84;
    free_list(cont, content, array);
    return 0;
}

int main(int ac, char **av)
{
    char *cont = NULL;
    header_t *content = malloc(sizeof(header_t));
    char **array = NULL;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_usage();
        return 0;
    }
    if (ac > 2 || ac < 2)
        return 84;
    if (test_file(av[1]) == 0)
        return start_process(cont, array, content, av[1]);
    return 84;
}
