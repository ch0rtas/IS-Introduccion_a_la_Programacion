#include <stdio.h>

int calcularMCD(int num1, int num2) {
    int mayor, menor, resto;

    // Encuentra el número mayor y el número menor
    if (num1 > num2) {
        mayor = num1;
        menor = num2;
    } else {
        mayor = num2;
        menor = num1;
    }

    // Calcula el MCD utilizando el algoritmo de Euclides
    while (menor != 0) {
        resto = mayor % menor;
        mayor = menor;
        menor = resto;
    }

    return mayor;
}

int main() {
    int num1, num2;

    printf("Introduce dos numeros enteros y positivos para encontrar su MCD:\n");

    if (scanf("%d %d", &num1, &num2) != 2 || num1 <= 0 || num2 <= 0) {
        printf("Por favor, introduce dos numeros enteros y positivos.\n");
    } else {
        int mcd = calcularMCD(num1, num2);
        printf("El MCD de %d y %d es %d\n", num1, num2, mcd);
    }

    return 0;
}
