#include <stdio.h>


int main() {
    int numbers[] = {72, 69, 76, 76, 79};

    for(int i = 0; i < 20; i++) {
        printf(
            "%c réside à l'adresse %p qui contient %i.\n",
            numbers[i], &numbers[i], *&numbers[i]
        );
    }
    printf("\n");
    printf("%ls\n", numbers);
}
