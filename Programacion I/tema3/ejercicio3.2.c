#include <stdio.h>

int main() {
    int numero;

    // Pedir al usuario que ingrese un número
    printf("Ingrese un numero entero: ");
    scanf(" %d", &numero);
    getchar();

    // Verificar si el número es par o impar usando el operador módulo (%)
    if (numero % 2 == 0) {
        printf("%d es un numero par.\n", numero);
    } else {
        printf("%d es un numero impar.\n", numero);
    }

    return 0;
}
