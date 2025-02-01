/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.18
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* leerLineaDinamicaFichero(FILE *fd) {
    int capacidad = 10;
    int longitud = 0;
    char *linea = (char *)malloc(capacidad * sizeof(char));
    int caracter;

    if (linea == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        exit(EXIT_FAILURE);
    }

    while ((caracter = fgetc(fd)) != EOF && caracter != '\n') {
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
    const char nombre_archivo[] = "C:\\Users\\manue\\Documents\\cygwin64\\home\\manue\\Programacion II\\tema5\\datos.txt";
    FILE *archivo = fopen(nombre_archivo, "r");

    if (archivo == NULL) {
        fprintf(stderr, "Error: No se pudo abrir el archivo %s\n", nombre_archivo);
        exit(EXIT_FAILURE);
    }

    char *nombre = leerLineaDinamicaFichero(archivo);
    char *apellido = leerLineaDinamicaFichero(archivo);

    fclose(archivo);

    if (nombre == NULL || apellido == NULL) {
        fprintf(stderr, "Error: No se pudieron leer todas las líneas del archivo\n");
        exit(EXIT_FAILURE);
    }

    char *nombre_completo = (char *)malloc((strlen(nombre) + strlen(apellido) + 2) * sizeof(char));
    if (nombre_completo == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    sprintf(nombre_completo, "%s %s", nombre, apellido);

    printf("Nombre completo: %s\n", nombre_completo);
    printf("Nombre: %s\n", nombre);
    printf("Apellido: %s\n", apellido);

    free(nombre);
    free(apellido);
    free(nombre_completo);

    return 0;
}
