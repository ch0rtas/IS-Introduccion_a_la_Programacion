#include <stdio.h>

int main() {

    int num1, num2, num3;

    // Pedir al usuario que ingrese los tres números enteros
    printf("Ingresa el primer numero entero: ");
    scanf("%d", &num1);

    printf("Ingresa el segundo numero entero: ");
    scanf("%d", &num2);

    printf("Ingresa el tercer numero entero: ");
    scanf("%d", &num3);

    // Comprobar cuál es el mayor de los tres números
    if (num1 >= num2 && num1 >= num3) {
        printf("El mayor numero es: %d\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("El mayor numero es: %d\n", num2);
    } else {
        printf("El mayor numero es: %d\n", num3);
    }

    return 0;
}
