/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.09
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo;
    char *nombre;
    char texto[100];

    nombre = (char *)malloc(100 * sizeof(char));

    if (nombre == NULL) {
        printf("Error al asignar memoria.");
        return 1;
    }

    archivo = fopen("C:\\Users\\manue\\Documents\\cygwin64\\home\\manue\\Programacion II\\tema4\\archivo.txt", "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.");
        free(nombre);
        return 1;
    }

    printf("Introduce tu nombre: ");
    fgets(nombre, 100, stdin);

    fputs(nombre, archivo);

    fclose(archivo);

    printf("El nombre se ha escrito correctamente en el archivo.\n");

    free(nombre);

    return 0;
}
