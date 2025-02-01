/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.23
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <string.h>

int main() {
    char cadena[100];
    char objetivo;
    char *resultado;

    printf("Ingrese una cadena de caracteres: ");
    scanf("%s", cadena);

    printf("Ingrese el caracter objetivo: ");
    scanf(" %c", &objetivo);

    // Buscar caracter usando strchr
    resultado = strchr(cadena, objetivo);

    if (resultado == NULL) {
        printf("El caracter %c no esta presente en la cadena.\n", objetivo);
    } else {
        int posicion = resultado - cadena;
        printf("El caracter %c se encuentra en la posicion %d de la cadena.\n", objetivo, posicion);
    }

    return 0;
}
