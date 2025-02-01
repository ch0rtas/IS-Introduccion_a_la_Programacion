#include <stdio.h>

int calcularFibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return calcularFibonacci(n-1) + calcularFibonacci(n-2);
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
