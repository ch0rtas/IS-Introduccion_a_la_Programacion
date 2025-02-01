#include <stdio.h>

int main() {
    int numero;
    long long factorial = 1; // Usamos long long para manejar factoriales grandes

    // Solicitar un número entero positivo
    do {
        printf("Introduce un numero entero positivo: ");
        scanf("%i", &numero);

        if (numero < 0) {
            printf("El numero debe ser positivo. Intenta de nuevo.\n");
        }
    } while (numero < 0);

    // Calcular el factorial
    for (int i = 1; i <= numero; i++) {
        factorial *= i;
    }

    do
    {
        res *= num;
        num -= 1;
    } while (num != 1)

    // Imprimir el resultado
    printf("El factorial de %d es %lld\n", numero, factorial);

    return 0;
}
