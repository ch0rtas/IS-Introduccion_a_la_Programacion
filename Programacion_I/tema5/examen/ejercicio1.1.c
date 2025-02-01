#include <stdio.h>

int calcularFibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        int primero = 0, segundo = 1, siguiente;

        for (int i = 2; i <= n; i++) {
            siguiente = primero + segundo;
            primero = segundo;
            segundo = siguiente;
        }

        return siguiente;
    }
}

int main() {
    int n;

    // Solicitar al usuario la posición 'n' para calcular el número de Fibonacci
    printf("Ingrese la posicion 'n' para calcular el numero de Fibonacci: ");
    scanf("%d", &n);

    // Calcular y mostrar el número de Fibonacci en la posición 'n'
    int resultado = calcularFibonacci(n);
    printf("El numero de Fibonacci en la posicion %d es: %d\n", n, resultado);

    return 0;
}
