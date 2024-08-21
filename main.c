#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"  // Incluye la declaración de mi_getenv y wand_path

int main(void)
{
    const char *filename = "ls"; // Nombre del archivo a buscar en el PATH
    char *executable_path = wand_path(filename); // Usa wand_path en lugar de find_executable

    if (executable_path)
    {
        printf("El archivo ejecutable '%s' se encuentra en: %s\n", filename, executable_path);
        free(executable_path); // Libera la memoria asignada para la ruta encontrada
    }
    else
    {
        printf("El archivo ejecutable '%s' no se encuentra en el PATH.\n", filename);
    }

    return 0;
}

