#include <stdio.h>

int main() {
    int numero, temp, digito, longitud = 0;

    // Solicitar al usuario un número natural
    printf("Ingrese un numero natural: ");
    scanf("%d", &numero);

    // Verificar que el número sea natural
    if (numero < 0) {
        printf("Error: El numero debe ser un numero natural.\n");
        return 1;  // Terminar el programa con código de error
    }

    temp = numero;

    // Determinar la longitud del número
    while (temp > 0) {
        temp /= 10;
        longitud++;
    }

    // Almacenar cada cifra en un array de enteros
    int cifras[longitud];
    temp = numero;
    for (int i = longitud - 1; i >= 0; i--) {
        digito = temp % 10;
        cifras[i] = digito;
        temp /= 10;
    }

    // Presentar el array de enteros
    printf("\nArray de cifras:\n");
    for (int i = 0; i < longitud; i++) {
        printf("%d ", cifras[i]);
    }

    // Determinar si el número es capicúa
    int esCapicua = 1; // Suponemos que el número es capicúa
    for (int i = 0; i < longitud / 2; i++) {
        if (cifras[i] != cifras[longitud - 1 - i]) {
            esCapicua = 0; // No es capicúa
            break;
        }
    }

    // Mostrar el resultado
    if (esCapicua) {
        printf("\nEl numero es capicua.\n");
    } else {
        printf("\nEl numero no es capicua.\n");
    }

    return 0;
}
