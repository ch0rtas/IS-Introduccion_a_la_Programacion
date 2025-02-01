#include <stdio.h>

// Función para verificar si un número es perfecto
int esPerfecto(int numero);

int main() {
    int contador = 0;
    int numero = 2; // Comenzamos desde el primer número perfecto conocido

    printf("Los primeros seis numeros perfectos son:\n");

    while (contador < 6) {
        if (esPerfecto(numero)) {
            printf("%d\n", numero);
            contador++;
        }
        numero++;
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

