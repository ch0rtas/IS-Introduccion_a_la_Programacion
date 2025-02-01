#include <stdio.h>

int main() {
    // Declarar cadenas para el nombre y apellido
    char nombre[20];
    char apellido[20];

    // Solicitar al usuario que ingrese su nombre
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);

    // Solicitar al usuario que ingrese su apellido
    printf("Ingrese su apellido: ");
    scanf("%s", apellido);

    // Imprimir las cadenas por pantalla
    printf("\nTus datos son:\n");
    printf("Nombre: %s\n", nombre);
    printf("Apellido: %s\n", apellido);

    return 0;
}
