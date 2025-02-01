/*
Autor: Manuel Martinez Ramón
Fecha: 2024.03.05
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>

int main() {
    char caracter;
    int entero;
    char *ptr_caracter;
    int *ptr_entero;

    printf("Tamano de char: %lu bytes\n", sizeof(char));
    printf("Tamano de int: %lu bytes\n", sizeof(int));
    printf("Tamano de puntero a char: %lu bytes\n", sizeof(ptr_caracter));
    printf("Tamano de puntero a int: %lu bytes\n", sizeof(ptr_entero));

    return 0;
}
