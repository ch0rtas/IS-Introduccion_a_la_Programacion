#include <stdio.h>

// Función para multiplicar dos enteros
int multiplicar(int a, int b) {
    return a * b;
}

int main() {
    int num1, num2;

    printf("Ingrese el primer entero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo entero: ");
    scanf("%d", &num2);

    int resultado = multiplicar(num1, num2);

    printf("El resultado de multiplicar %i * %i es: %i\n", num1, num2, resultado);

    return 0;
}
