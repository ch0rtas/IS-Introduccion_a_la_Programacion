#include <stdio.h>

// Función para calcular el MCD usando el algoritmo de Euclides
int calcularMCD(int num1, int num2) {
    // El bucle continúa hasta que num2 sea igual a 0
    while (num2 != 0) {
        // Se utiliza una variable temporal para intercambiar los valores
        int temp = num2;
        // Se actualiza num2 con el residuo de la división
        num2 = num1 % num2;
        // Se actualiza num1 con el valor temporal
        num1 = temp;
    }

    // El MCD se encuentra en num1 al final del bucle
    return num1;
}

int main() {
    // Leer dos números enteros positivos desde la entrada estándar
    int num1, num2;
    
    do {
        printf("Ingrese el primer numero entero positivo: ");
        scanf("%i", &num1);
    } while (num1 <= 0);

    do {
        printf("Ingrese el segundo numero entero positivo: ");
        scanf("%i", &num2);
    } while (num2 <= 0);

    // Calcular y mostrar el MCD
    int mcd = calcularMCD(num1, num2);
    printf("El MCD de %d y %d es: %d\n", num1, num2, mcd);

    return 0;
}
