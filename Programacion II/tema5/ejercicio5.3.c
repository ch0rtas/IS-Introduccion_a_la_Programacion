/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.18
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char nombre_archivo[] = "C:\\Users\\manue\\Documents\\cygwin64\\home\\manue\\Programacion II\\tema5\\datos.txt";
    FILE *archivo = fopen(nombre_archivo, "r");

    if (archivo == NULL) {
        fprintf(stderr, "Error: No se pudo abrir el archivo %s\n", nombre_archivo);
        exit(EXIT_FAILURE);
    }

    char nombre[50];
    char apellido[50];


    if (fgets(nombre, sizeof(nombre), archivo) == NULL) {
        fprintf(stderr, "Error: No se pudo leer el nombre del archivo\n");
        exit(EXIT_FAILURE);
    }

    nombre[strcspn(nombre, "\n")] = '\0';

    if (fgets(apellido, sizeof(apellido), archivo) == NULL) {
        fprintf(stderr, "Error: No se pudo leer el apellido del archivo\n");
        exit(EXIT_FAILURE);
    }

    apellido[strcspn(apellido, "\n")] = '\0';

    char nombre_completo[100];
    strcpy(nombre_completo, nombre);
    strcat(nombre_completo, " ");
    strcat(nombre_completo, apellido);

    printf("Nombre completo: %s\n", nombre_completo);
    printf("Nombre: %s\n", nombre);
    printf("Apellido: %s\n", apellido);

    fclose(archivo);

    return 0;
}
