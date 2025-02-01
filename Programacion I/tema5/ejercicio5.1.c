#include <stdio.h>

// Función para verificar si un número es perfecto
int esPerfecto(int numero);

int main() {
    int num;

    // Pedir al usuario un número entero positivo
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &num);

    // Verificar si el número es perfecto
    if (esPerfecto(num)) {
        printf("%d SI es un numero perfecto.\n", num);
    } else {
        printf("%d NO es un numero perfecto.\n", num);
    }

    return 0;
}

int esPerfecto(int numero) {
    int suma = 0;
    for (int i = 1; i <= numero / 2; i++) {
        if (numero % i == 0) {
            suma += i;
        }
    }
    return (suma == numero);
}
