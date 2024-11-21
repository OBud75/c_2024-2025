#include <stdio.h>
#include <stdlib.h>

void draw(int height) {
    if (height == 0) {
        return;
    }

    draw(height - 1);

    for (int i = 0; i < height; i++) {
        printf("#");
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    int height = atoi(argv[1]);
    draw(height);
    return 0;
}
