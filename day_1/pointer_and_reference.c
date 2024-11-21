#include <stdio.h>


int main() {
    char *text = "Ceci est du texte.\n";
    printf("%s.\n", text);
    printf("L'adresse mémoire de text ? : %p\n.", &text);

    for(int i = 0; i < 50; i++) {
        printf("L'adresse mémoire text + %i est : %p\n.", i, &text[i]);
        printf("Le contenu de l'adresse mémoire text + %i est : %c\n.", i, *&text[i]);
    }
}
