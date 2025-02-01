#include <stdio.h>

int main() {
    int numero_entero;
    char caracter;

    // Solicitar al usuario que ingrese un número entero
    printf("Ingresa un numero entero: ");
    scanf("%d", &numero_entero);

    // Convertir el número entero a carácter
    caracter = (char)numero_entero;

    // Imprimir el carácter por pantalla
    printf("El caracter correspondiente al numero entero %d es: %c\n", numero_entero, caracter);

    return 0;
}
