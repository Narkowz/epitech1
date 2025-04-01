/*
** EPITECH PROJECT, 2023
** final stumper
** File description:
** finale stumper
*/

#include <unistd.h>
#include "./include/rush3.h"

int calculating_square(char *buff)
{
    int y = 0;
    int x = 0;
    int count_y = 0;
    int count_x = 0;

    for (; buff[y] != '\0'; y++){
        if (buff[y] == '\n'){
            count_y = count_y + 1;
        }
    }
    for (; buff[x] != '\n'; x++){
        count_x = count_x + 1;
    }
    printing_function(count_y, count_x);
    return (0);
}

int rush3(char *buff)
{
    recognising_char(buff);
    my_putchar('\n');
}

int main(void)
{
    char buff[30000 + 1];
    int offset = 0;
    int len = read(0, (buff + offset), (30000 - offset));

    while (len > 0) {
        offset = offset + len;
        len = read(0, (buff + offset), (30000 - offset));
    }
    buff[offset] = '\0';
    if (buff[0] == '\0'){
        my_putstr_error("none\n");
        return (84);
    }
    if (len < 0){
        return (84);
    }
    rush3(buff);
    return (0);
}
