#include <stdio.h>

int main() {
    float numero_flotante;
    int numero_entero;

    // Solicitar al usuario que ingrese un número en formato coma flotante
    printf("Ingresa un numero en formato coma flotante: ");
    scanf("%f", &numero_flotante);

    // Convertir el número en coma flotante a entero
    numero_entero = (int)numero_flotante;

    // Imprimir el número entero resultante
    printf("El numero entero resultante es: %d\n", numero_entero);

    return 0;
}
