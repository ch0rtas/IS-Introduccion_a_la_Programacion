/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.18
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* leerLineaDinamica() {
    int capacidad = 10;
    int longitud = 0;
    char *linea = (char *)malloc(capacidad * sizeof(char));
    char caracter;

    if (linea == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        caracter = getchar();

        if (caracter == '\n' || caracter == EOF) {
            break;
        }

        if (longitud >= capacidad - 1) {
            capacidad *= 2;
            linea = (char *)realloc(linea, capacidad * sizeof(char));

            if (linea == NULL) {
                fprintf(stderr, "Error: No se pudo reasignar memoria\n");
                exit(EXIT_FAILURE);
            }
        }

        linea[longitud++] = caracter;
    }

    linea[longitud] = '\0';

    return linea;
}

int main() {
    char *nombre = NULL;
    char *apellido = NULL;

    printf("Ingrese el nombre del alumno: ");
    nombre = leerLineaDinamica();

    printf("Ingrese el apellido del alumno: ");
    apellido = leerLineaDinamica();

    size_t nombreCompletoSize = strlen(nombre) + strlen(apellido) + 2;
    char *nombreCompleto = (char *)malloc(nombreCompletoSize * sizeof(char));

    strcpy(nombreCompleto, nombre);
    strcat(nombreCompleto, " ");
    strcat(nombreCompleto, apellido);

    printf("Nombre completo: %s\n", nombreCompleto);
    printf("Nombre: %s\n", nombre);
    printf("Apellido: %s\n", apellido);

    free(nombre);
    free(apellido);
    free(nombreCompleto);

    return 0;
}
