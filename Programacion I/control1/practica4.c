#include <stdio.h>

int main() {
    int num1, num2;

    // Solicitar dos números enteros de tres cifras
    printf("Introduce el primer numero de tres cifras: ");
    scanf("%d", &num1);

    printf("Introduce el segundo numero de tres cifras: ");
    scanf("%d", &num2);

    // Verificar que ambos números son de tres cifras
    if (num1 < 100 || num1 > 999 || num2 < 100 || num2 > 999) {
        printf("Por favor, introduce dos numeros enteros de tres cifras.\n");
        return 1;
    }

    // Realizar la multiplicación
    int parte1 = num1 * (num2 % 10);
    int parte2 = num1 * ((num2 / 10) % 10) * 10;
    int parte3 = num1 * ((num2 / 100) % 10) * 100;

    // Calcular el resultado final y mostrarlo
    int resultado = parte1 + parte2 + parte3;
    printf("El resultado de la multiplicacion es: %d\n", resultado);

    return 0;
}
