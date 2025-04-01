/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** oui
*/

char* my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int a = 0;

    if (*str[i] == '\0') {
            return (str);
        }

    while (*str[i] != '\0') {
        if (str[i] != to_find[a]) {
            i++;
        }
        a++;
    }
    return NULL;
}

void main()
{
    char str[]="Je m'appelle Jean";
    char to_find[]="Je";
    printf("%s", (my_strstr(&str, &to_find)));
}
