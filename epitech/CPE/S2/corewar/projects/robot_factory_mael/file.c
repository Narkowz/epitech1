/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** branching
*/

#include "../my/my.h"

char *switch_name(char **av)
{
    int u = my_strlen(av[1]);
    char *filename = malloc(sizeof(char) * u + 2);

    my_strncpy(filename, av[1], u - 2);
    my_strcat(filename, ".cor");
    return filename;
}

int create_cor(int ac, char **av)
{
    int file;
    char *filename = switch_name(av);

    file = open(filename, O_WRONLY | O_CREAT, 0644);
    if (file == -1)
        return 84;
    close(file);
    return 0;
}

void send_name(header_t *Identation, char **av)
{
    char *filename = switch_name(av);
    FILE *file = fopen(filename, "wb");

    if (file != NULL) {
        fwrite(Identation, sizeof(header_t), 1, file);
        fclose(file);
    }
    return;
}

int validate_header_line(const char *line, const char *directive,
    char **av, header_t *Iden)
{
    char *quoted_string;
    static int k = 0;

    while (*line == ' ' || *line == '\t')
        line++;
    if (my_strncmp(line, directive, my_strlen(directive)) != 0)
        return 0;
    line += my_strlen(directive);
    quoted_string = extract_quoted_string(line);
    if (!quoted_string)
        return 0;
    if (k == 0) {
        my_strcpy(Iden->prog_name, quoted_string);
        k++;
    } else {
        my_strcpy(Iden->comment, quoted_string);
        send_name(Iden, av);
    }
    free(quoted_string);
    return 1;
}
