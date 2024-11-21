#include <stdio.h>

int main(int argc, char const *argv[]) {
    printf("Nombre d'arguments : %i.\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Valeur de l'argument %i : %s.\n", i, argv[i]);
    }
}
