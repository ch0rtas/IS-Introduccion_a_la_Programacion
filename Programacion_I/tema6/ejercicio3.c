#include <stdio.h>

// Prototipo de la función recursiva
int calcularPotencia(int base, int exponente);

int main() {
    int X, Y;
    char buffer[100];  // Buffer para limpiar la entrada no válida

    // Solicitar al usuario dos valores enteros
    do {
        printf("Ingrese el valor de X (entero): ");
        if (scanf("%d", &X) != 1) {
            printf("Entrada no valida. Por favor, ingrese un numero entero.\n");
            scanf("%s", buffer);  // Limpiar el búfer de entrada
        } else {
            break;  // Salir del bucle si la entrada es válida
        }
    } while (1);  // Bucle infinito, se sale con un "break" si la entrada es válida

    do {
        printf("Ingrese el valor de Y (entero): ");
        if (scanf("%d", &Y) != 1) {
            printf("Entrada no valida. Por favor, ingrese un numero entero.\n");
            scanf("%s", buffer);  // Limpiar el búfer de entrada
        } else {
            break;  // Salir del bucle si la entrada es válida
        }
    } while (1);  // Bucle infinito, se sale con un "break" si la entrada es válida

    // Calcular X elevado a la potencia Y utilizando la función recursiva
    int resultado = calcularPotencia(X, Y);

    // Mostrar el resultado
    printf("%d elevado a la potencia %d es: %d\n", X, Y, resultado);

    return 0;
}

// Definición de la función recursiva para calcular X^Y
int calcularPotencia(int base, int exponente) {
    if (exponente == 0) {
        return 1;
    } else if (exponente % 2 == 0) {
        // Caso par: X^Y = (X^(Y/2))^2
        int temp = calcularPotencia(base, exponente / 2);
        return temp * temp;
    } else {
        // Caso impar: X^Y = (X^(Y/2))^2 * X
        int temp = calcularPotencia(base, exponente / 2);
        return temp * temp * base;
    }
}