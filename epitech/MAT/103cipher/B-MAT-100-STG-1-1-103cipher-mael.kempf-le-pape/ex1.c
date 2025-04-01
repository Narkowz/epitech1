#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av) {
    int *matrix = malloc(sizeof(int) * (strlen(av[1]) + 1)); // Allocate memory for the matrix

    int sqrt_length = sqrt(strlen(av[1])); // Calculate the square root
    printf("%f\n", sqrt_length);
    int index = 0;

    // Populate the matrix with ASCII values
    for (int i = 0; av[1][i] != '\0'; i++) {
        matrix[i] = (int)av[1][i];
        index++;
    }

    printf("(");

    // Print the matrix in the desired format
    for (int i = 0; i < index; i++) {
        printf("%d ", matrix[i]);
        if ((i + 1) % sqrt_length == 0 && i + 1 != index) {
            printf("\n");
        }
    }

    printf(")\n");

    free(matrix); // Free allocated memory
    return 0;
}
