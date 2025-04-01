#include <stdio.h>

extern void disp_string(const char *str);

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {  // On commence à 1 pour éviter le nom du programme
        disp_string(argv[i]);
    }
    return 0;
}
