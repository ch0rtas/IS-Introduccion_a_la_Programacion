/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.23
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRES 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return 1;
    }

    FILE *archivo;
    char *nombres[MAX_NOMBRES];
    char linea[100];
    int num_nombres = 0;

    archivo = fopen(argv[1], "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Leer los nombres del archivo y almacenarlos en un array
    while (fgets(linea, sizeof(linea), archivo) != NULL && num_nombres < MAX_NOMBRES) {
        // Eliminar el salto de línea al final de la línea
        linea[strcspn(linea, "\n")] = '\0';
        // Asignar memoria para almacenar el nombre
        nombres[num_nombres] = malloc(strlen(linea) + 1);
        strcpy(nombres[num_nombres], linea);
        num_nombres++;
    }

    fclose(archivo);

    // Ordenar los nombres alfabéticamente
    for (int i = 0; i < num_nombres - 1; i++) {
        for (int j = i + 1; j < num_nombres; j++) {
            if (strcmp(nombres[i], nombres[j]) > 0) {
                // Intercambiar los nombres si están en el orden incorrecto
                // Si es mayor a 0, el primer valor es mayor (A < Z)
                char *temp = nombres[i];
                nombres[i] = nombres[j];
                nombres[j] = temp;
            }
        }
    }

    printf("Nombres ordenados:\n");
    for (int i = 0; i < num_nombres; i++) {
        printf("%s\n", nombres[i]);
        free(nombres[i]);
    }

    return 0;
}
