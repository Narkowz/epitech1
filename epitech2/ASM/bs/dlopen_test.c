#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    void (*my_putstr)(const char *);

    // Charger la bibliothèque
    handle = dlopen("./libmy.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    // Récupérer le symbole
    my_putstr = (void (*)(const char *)) dlsym(handle, "my_putstr");
    if (!my_putstr) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    // Appeler la fonction
    my_putstr("Hello, dynamic world!\n");

    // Fermer la bibliothèque
    dlclose(handle);
    return 0;
}
