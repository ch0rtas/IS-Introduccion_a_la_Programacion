/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.01
Curso: INSO 1 - Introducción Programación II

Copia un array en otro utilizando punteros.
*/

#include <stdio.h>

#define TAMANO 50

void copiarCadena(char *origen, char *destino) {
    while (*origen != '\0') {
        *destino = *origen;
        destino++;
        origen++;
    }

    *destino = '\0';
}

int main() {
    char array1[TAMANO] = "Manu";
    char array2[TAMANO];

    copiarCadena(array1, array2);

    printf("Cadena Original: %s\n", array1);
    printf("Cadena Copiada: %s\n", array2);

    return 0;
}
