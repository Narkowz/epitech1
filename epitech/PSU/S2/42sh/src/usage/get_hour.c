/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** get_hour
*/

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_hour(void)
{
    char *hour = malloc((size_t)sizeof(char) * 6);
    time_t now = time(NULL);
    struct tm *now_tm = localtime(&now);
    char buf[10];

    if (now_tm->tm_hour < 10)
        strcpy(hour, "0");
    else
        hour[0] = '\0';
    sprintf(buf, "%d:", now_tm->tm_hour);
    strcat(hour, buf);
    if (now_tm->tm_min < 10)
        strcat(hour, "0");
    sprintf(buf, "%d", now_tm->tm_min);
    strcat(hour, buf);
    return hour;
}
