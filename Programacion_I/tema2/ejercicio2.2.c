#include <stdio.h>

int main() {
    int numero1, numero2;

    // Pedir al usuario que ingrese los dos números enteros
    printf("Ingresa el primer numero entero: ");
    scanf("%d", &numero1);

    printf("Ingresa el segundo numero entero: ");
    scanf("%d", &numero2);

    // Mostrar la representación hexadecimal de los números
    printf("\nNumero 1 (decimal): %d\n", numero1);
    printf("Numero 1 (hexadecimal): %X\n", numero1);

    printf("\nNumero 2 (decimal): %d\n", numero2);
    printf("Numero 2 (hexadecimal): %X\n", numero2);

    return 0;
}