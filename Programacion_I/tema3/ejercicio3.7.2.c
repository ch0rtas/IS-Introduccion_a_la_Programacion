#include <stdio.h>

int main() {
    unsigned char numero;

    // Solicitar al usuario que ingrese un número de 8 bits
    printf("Por favor, ingresa un numero de 8 bits (0-255): ");
    scanf("%hhu", &numero);

    // Verificar si el tercer bit a partir de la derecha es par o impar
    int tercer_bit = (numero >> 2) & 1;

    if (tercer_bit == 0) {
        printf("El tercer bit a partir de la derecha es PAR.\n");
    } else {
        printf("El tercer bit a partir de la derecha es IMPAR.\n");
    }

    return 0;
}
