/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.06
Curso: INSO 1 - Introducción Programación II

Media de listas de enteros.
Recibe el número de enteros como argumento, seguidos de lso números a calcular.
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

    printf("Número total de argumentos %i\n", argc);

    for(int i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }

    return 0;
}

