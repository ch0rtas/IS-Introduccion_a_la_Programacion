#include <stdio.h>

int main() {
    int n, i, primero = 0, segundo = 1, siguiente;

    // Solicitar al usuario el número de términos que desea imprimir
    printf("Ingrese el valor de n para la serie de Fibonacci: ");
    scanf("%d", &n);

    // Imprimir los primeros n términos de la serie de Fibonacci
    printf("Serie de Fibonacci con %d terminos:\n", n);

    for (i = 0; i < n; i++) {
        if (i <= 1) {
            siguiente = i;
        } else {
            siguiente = primero + segundo;
            primero = segundo;
            segundo = siguiente;
        }

        printf("%d ", siguiente);
    }

    return 0;
}
