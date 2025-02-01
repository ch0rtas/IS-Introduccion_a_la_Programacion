#include <stdio.h>

int main() {
    int num1, num2, resultado;

    // Solicitar al usuario que ingrese los dos números
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    // Verificar si el primer número es mayor o igual que el segundo
    if (num1 >= num2) {
        // Realizar la resta si num1 es mayor o igual que num2
        resultado = num1 - num2;
        printf("El resultado de la resta es: %d\n", resultado);
    } else {
        // Realizar la suma si num1 es menor que num2
        resultado = num1 + num2;
        printf("El resultado de la suma es: %d\n", resultado);
    }

    return 0;
}
