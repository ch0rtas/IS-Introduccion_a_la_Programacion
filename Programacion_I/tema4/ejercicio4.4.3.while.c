#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeroAleatorio, numeroUsuario, intentos = 0;

    // Inicializamos la semilla para la generación de números aleatorios.
    srand(time(NULL));

    // Generamos un número aleatorio entre 0 y 10.
    numeroAleatorio = rand() % 11;

    printf("Adivina el numero entre 0 y 10.\n");

    while (1) {
        printf("Introduce un numero: ");
        scanf("%d", &numeroUsuario);

        intentos++; // Incrementamos el contador de intentos.

        if (numeroUsuario == numeroAleatorio) {
            printf("¡Felicitaciones! Adivinaste el numero %d en %d intentos.\n", numeroAleatorio, intentos);
            break; // Salimos del bucle al adivinar el número.
        } else {
            if (numeroUsuario < 0 || numeroUsuario > 10) {
                printf("El numero debe estar entre 0 y 10.\n");
            } else {
                printf("Intenta de nuevo. ");
                if (numeroUsuario < numeroAleatorio) {
                    printf("El numero es mayor.\n");
                } else {
                    printf("El numero es menor.\n");
                }
            }
        }
    }

    return 0;
}
