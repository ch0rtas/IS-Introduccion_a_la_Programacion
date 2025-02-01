#include <stdio.h>

int main() {
    // Mostrar la representación interna del carácter 'A'
    char caracter_A = 'A';
    printf("La representacion interna de 'A' es: %d\n", caracter_A);

    // Transformar 'A' en 'a' sin usar funciones externas
    char caracter_a = caracter_A + ('a' - 'A');
    printf("El caracter 'A' transformado en 'a' es: %c\n", caracter_a);

    // Transformar 'A' en 'a' sin usar funciones externas forma 'tonta'
    char caracter_A2 = caracter_A + 32;
    printf("Caracter 'A' transformado en 'a' sumando 32: %c\n", caracter_A2);

    return 0;
}