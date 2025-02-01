#include <stdio.h>

int main() {
    // Declarar variables para los caracteres
    char char1, char2, char3;
    int inputCount;

    // Solicitar al usuario que ingrese los caracteres
    printf("Ingrese tres caracteres: ");
    inputCount = scanf(" %c %c %c", &char1, &char2, &char3);

    // Verificar que se hayan ingresado tres caracteres correctamente
    if (inputCount == 3) {
        printf("Se han introducido 3 caracteres: %c, %c, %c\n", char1, char2, char3);
    } else {
        printf("No se han introducido los datos correctamente.\n");
    }

    return 0;
}
