/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** prompt
*/

#include "my.h"
#include "shell.h"
#include "macro.h"

char *get_current_branch(void)
{
    FILE *pipe;
    char buffer[1024];
    char *branch = NULL;

    pipe = popen("git rev-parse --abbrev-ref HEAD 2>/dev/null", "r");
    if (pipe == NULL)
        return NULL;
    if (fgets(buffer, 1024, pipe) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
        branch = strdup(buffer);
    }
    pclose(pipe);
    if (branch == NULL || strcmp(branch, "HEAD") == 0) {
        if (branch)
            free(branch);
        return NULL;
    }
    return branch;
}

/**
 * @brief Print the prompt of the 42sh
 * @param shell_t* The main sheel structure
 * @return Nothing
 */
void prompt(shell_t *shell)
{
    char *branch = get_current_branch();

    if (isatty(0)) {
        printf("%s%s%s %s%s%s%s%s %s %s",
            LIGHT_GRAY, "", WHITE_BG,
            BLACK, "⚡", WHITE, BLUE_BG, "",
            "",
            "~ ");
        if (branch) {
            printf("%s%s%s %s%s%s %s%s%s %s",
                BLUE, YELLOW_BG, "",
                BLACK, "  ", branch,
                RESET, YELLOW, "",
                RESET);
        } else {
            printf("%s%s%s%s ",
            RESET, BLUE, "", RESET);
        }
    }
    fflush(stdout);
}
