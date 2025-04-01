/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** branching
*/

#include "../my/my.h"

char *extract_quoted_string(const char *line)
{
    char *quote_start;
    char *quote_end;
    char *quoted_string;

    quote_start = my_strchr(line, '"');
    quote_end = my_strrchr(line, '"');
    if (!quote_start || quote_start == quote_end)
        return NULL;
    quoted_string = malloc(quote_end - quote_start);
    my_strncpy(quoted_string, quote_start + 1, quote_end - quote_start - 1);
    quoted_string[quote_end - quote_start - 1] = '\0';
    return quoted_string;
}

int validate_file(char *filename, char **av)
{
    char line[256];
    FILE *file = fopen(filename, "r");
    struct header_s Iden;
    int name = 0;
    int comment = 0;

    my_memset(Iden.prog_name, 0, sizeof(Iden.prog_name));
    my_memset(Iden.comment, 0, sizeof(Iden.comment));
    Iden.magic = 0xea83f3;
    Iden.prog_size = 0;
    if (!file)
        return 84;
    while (my_fgets(line, sizeof(line), file)) {
        name |= validate_header_line(line, ".name", av, &Iden);
        comment |= validate_header_line(line, ".comment", av, &Iden);
    }
    fclose(file);
    if (!name || !comment)
        return 84;
    return 0;
}
