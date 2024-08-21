#include "main.h"
#include <stdio.h>

int main() {
    char *path = mi_getenv("PATH");
    if (path != NULL) {
        printf("PATH: %s\n", path);
    } else {
        printf("Variable de entorno PATH no encontrada.\n");
    }

    return 0;
}

