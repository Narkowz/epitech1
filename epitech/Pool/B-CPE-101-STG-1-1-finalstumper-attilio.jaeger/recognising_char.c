/*
** EPITECH PROJECT, 2023
** recognising_char
** File description:
** recognising_char
*/

#include <unistd.h>
#include "./include/rush3.h"

int my_size_y(char *buff)
{
    int count = 0;

    for (int i = 0; buff[i] != '\n'; i++){
        count = count + 1;
    }
    return (count);
}

void printing_be(char *buff)
{
    my_putstr("[Rush1-3] ");
    calculating_square(buff);
    my_putstr(" || [Rush1-4] ");
    calculating_square(buff);
    my_putstr(" || [Rush1-5] ");
    calculating_square(buff);
}

int recognising_to_b_or_not_to_b(char *buff, int len, int size_y)
{
    if (buff[0] == 'B'){
        printing_be(buff);
        return (0);
    }
    if ((buff[len - 2] == 'C' && buff[len - 2] != buff[size_y - 1])){
        my_putstr("[Rush1-3] ");
        calculating_square(buff);
        return (0);
    }
    if ((buff[len - 2] == buff[size_y - 1] && buff[len - 2] == 'C')){
        my_putstr("[Rush1-4] ");
        calculating_square(buff);
        return (0);
    }
    if (buff[len - 2] == 'A'){
        my_putstr("[Rush1-5] ");
        calculating_square(buff);
        return (0);
    }
}

int recognising_char(char *buff)
{
    int len = my_strlen(buff);
    int size_y = my_size_y(buff);

    if (buff[0] == 'o'){
        my_putstr("[Rush1-1] ");
        calculating_square(buff);
    }
    if (buff[0] == '/' || buff[0] == '*'){
        my_putstr("[Rush1-2] ");
        calculating_square(buff);
    }
    recognising_to_b_or_not_to_b(buff, len, size_y);
    return 0;
}
