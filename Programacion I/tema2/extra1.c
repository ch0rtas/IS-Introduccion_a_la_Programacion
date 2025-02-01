#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declarar variables para las letras
    char letra1, letra2;

    // Solicitar al usuario que ingrese la primera letra
    printf("Ingrese la primera letra: ");
    scanf(" %c", &letra1);

    // Solicitar al usuario que ingrese la segunda letra
    printf("Ingrese la segunda letra: ");
    scanf(" %c", &letra2);

    // Calcular la distancia entre las letras en el alfabeto
    int distancia = abs(letra2 - letra1);

    // Mostrar la distancia por pantalla
    printf("La distancia entre %c y %c en el alfabeto es: %d\n", letra1, letra2, distancia);

    return 0;
}
