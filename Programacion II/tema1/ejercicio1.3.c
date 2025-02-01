/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.06
Curso: INSO 1 - Introducción Programación II

Mostrar por pantalla el número de argumentos introducidos.
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

    printf("Numero total de argumentos %i\n", argc);

    for(int i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }

    return 0;
}

