/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.25
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <string.h>


int main() {
    
    char cadena[] = "Manuel;Martinez;21";

    char nombre[100];
    char apellido[100];
    char edad[100];

    char *token = strtok(cadena, ";");

    strcpy(nombre, token);

    token = strtok(NULL, ";");
    strcpy(apellido, token);

    token = strtok(NULL, ";");
    strcpy(edad, token);

    printf("Nombre: %s\n", nombre);
    printf("Apellido: %s\n", apellido);
    printf("Edad: %s\n", edad);


    return 0;
}
