/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.20
Curso: INSO 1 - Introducción Programación II

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    // Declaramos e inicializamos la variable 'valor' a 5
    int valor;
    valor = 5;

    // Imprimimos el valor de 'valor'
    printf("valor = %d\n", valor);

    // Declaramos un puntero 'ptr' y lo inicializamos a NULL
    void *ptr = NULL;

    // Asignamos memoria dinámica para un entero y asignamos su dirección a 'ptr'
    ptr = malloc(sizeof(int));

    // Declaramos un puntero a entero 'ptr_int' y lo inicializamos a NULL
    int *ptr_int = NULL;

    // Convertimos el puntero 'ptr' a un puntero a entero y lo asignamos a 'ptr_int'
    ptr_int = (int *) ptr;

    // Almacenamos el valor 5 en la ubicación de memoria apuntada por 'ptr_int'
    *ptr_int = 5;

    // Imprimimos el valor almacenado en la ubicación de memoria apuntada por 'ptr_int'
    printf("ptr_int: %d\n", *ptr_int);

    // Liberamos la memoria asignada dinámicamente
    free(ptr);

    // Indicamos que el programa se ha ejecutado correctamente
    return 0;
}
