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

    // Bucle para permitir al usuario intentar ingresar un número hasta que lo encuentre
    int encontrado = 0;
    while (!encontrado) {
        // Pedir al usuario un número entre 0 y 30
        int numeroUsuario;
        printf("Ingresa un numero entre 0 y 30: ");

        // Verificar que se ingrese un entero válido
        while (scanf("%d", &numeroUsuario) != 1 || numeroUsuario < 0 || numeroUsuario > 30) {
            printf("Entrada no valida. Ingresa un numero entre 0 y 30: ");
            // Limpiar el búfer de entrada
            while (getchar() != '\n');
        }

        // Buscar el número en el array
        for (int i = 0; i < 10; i++) {
            if (array[i] == numeroUsuario) {
                encontrado = 1;
                printf("Numero encontrado\n");
                break; // Salir del bucle si el número es encontrado
            }
        }

        // Si el número no se encuentra, mostrar un mensaje y permitir al usuario intentar nuevamente
        if (!encontrado) {
            printf("Numero no encontrado. Intenta nuevamente.\n");
        }
    }

    return 0;
}
