#include <stdio.h>

int main() {
    int num1, num2, temp;

    printf("Introduce el primer numero: ");
    scanf("%d", &num1);

    printf("Introduce el segundo numero: ");
    scanf("%d", &num2);

    // Intercambio de valores utilizando una variable temporal (temp)
    temp = num1;
    num1 = num2;
    num2 = temp;

    printf("Despues del intercambio:\n");
    printf("Primer numero: %d\n", num1);
    printf("Segundo numero: %d\n", num2);

    return 0;
}
