#include <stdio.h>

int main() {
    int numero;
    int anterior = -1;  // Inicializado a un valor que no puede ser un dígito válido
    int contadorConsecutivo = 0;
    int contadorTotal = 0;
    int contadorDigitos[10] = {0};  // Contador para cada dígito (0-9)

    printf("Introduce números del 1 al 9 (0 para salir):\n");

    do {
        printf("Número: ");
        scanf("%d", &numero);

        if (numero >= 1 && numero <= 9) {
            contadorTotal++;

            if (numero == anterior) {
                contadorConsecutivo++;
            } else {
                contadorConsecutivo = 1;
            }

            if (contadorConsecutivo == 1 || contadorConsecutivo > contadorDigitos[numero]) {
                contadorDigitos[numero] = contadorConsecutivo;
            }

            anterior = numero;
        } else if (numero != 0) {
            printf("Error: Introduce un número del 1 al 9 o 0 para salir.\n");
        }
    } while (numero != 0);

    printf("\nResultado:\n");
    printf("Número introducido mayor número de veces consecutivas: ");
    
    int maxDigitos = 0;
    int numeroMasFrecuente = 0;

    for (int i = 1; i <= 9; i++) {
        if (contadorDigitos[i] > maxDigitos) {
            maxDigitos = contadorDigitos[i];
            numeroMasFrecuente = i;
        }
    }

    printf("%d (se repitió %d veces consecutivas)\n", numeroMasFrecuente, maxDigitos);

    printf("Número total de dígitos introducidos: %d\n", contadorTotal);

    printf("Número total de cada uno de los dígitos:\n");
    for (int i = 1; i <= 9; i++) {
        printf("Dígito %d: %d\n", i, contadorDigitos[i]);
    }

    return 0;
}
