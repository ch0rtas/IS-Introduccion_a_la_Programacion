/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.18
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <string.h>

int main() {
    char nombre[20];
    char apellido[20];

    printf("Ingrese el nombre del alumno: ");
    scanf("%s", nombre);
    printf("Ingrese el apellido del alumno: ");
    scanf("%s", apellido);

    char nombreCompleto[40];
    strcpy(nombreCompleto, nombre);
    strcat(nombreCompleto, " ");
    strcat(nombreCompleto, apellido);

    printf("Nombre completo: %s\n", nombreCompleto);
    printf("Nombre: %s\n", nombre);
    printf("Apellido: %s\n", apellido);

    return 0;
}
