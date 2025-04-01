#include <unistd.h>

// Affiche un caractère
void my_putchar(char c) {
    write(1, &c, 1);
}

// Affiche une chaîne de caractères
void my_putstr(const char *str) {
    while (*str)
        my_putchar(*str++);
}

// Retourne la longueur d'une chaîne
int my_strlen(const char *str) {
    int len = 0;
    while (str[len])
        len++;
    return len;
}

// Fonction malloc personnalisée
void *malloc(size_t size) {
    write(2, "The stone is in your pocket!\n", 29);
    return NULL; // On ne fait pas réellement d'allocation
}

