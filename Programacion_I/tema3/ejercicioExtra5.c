#include <stdio.h>

int main() {
    double num1, num2;
    char operador;

    printf("Realizar la operacion de dos numeros decimales\n");

    printf("Introduce el primer numero decimal: ");
    scanf(" %lf", &num1);

    printf("Introduce el segundo numero decimal: ");
    scanf(" %lf", &num2);

    printf("Introduce un operador (+ o -): ");
    scanf(" %c", &operador);

    if (operador == '+') {
        double resultado = num1 + num2;
        printf("El resultado de la suma es: %lf\n", resultado);
    } else if (operador == '-') {
        double resultado = num1 - num2;
        printf("El resultado de la resta es: %lf\n", resultado);
    } else {
        printf("El operador introducido no es valido. Debe ser '+' o '-'.\n");
    }

    return 0;
}
