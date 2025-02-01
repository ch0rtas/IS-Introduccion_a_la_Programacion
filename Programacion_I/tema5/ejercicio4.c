#include <stdio.h>
#include <stdbool.h>

// Función para comprobar si un número es primo
bool esPrimo(int numero) {
    // Si el número es menor o igual a 1, no es primo
    if (numero <= 1) {
        return false;
    }

    // Verificar divisibilidad desde 2 hasta la raíz cuadrada del número
    for (int i = 2; i * i <= numero; ++i) {
        if (numero % i == 0) {
            // Si el número es divisible por i, no es primo
            return false;
        }
    }

    // Si no se encontraron divisores, el número es primo
    return true;
}

int main() {
    // Leer el número desde la entrada estándar
    int numero;
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    // Verificar si el número es primo y mostrar el resultado
    if (esPrimo(numero)) {
        printf("%d SI es un numero primo.\n", numero);
    } else {
        printf("%d NO es un numero primo.\n", numero);
    }

    return 0;
}
