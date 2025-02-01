#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Semilla para la generación de números aleatorios
    srand(time(NULL));

    // Declaración e inicialización del array
    int array[10];

    // Rellenar el array con números aleatorios entre 0 y 30
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 31; // Módulo 31 para obtener números entre 0 y 30
    }

    // Mostrar el array por pantalla
    printf("Array generado: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
