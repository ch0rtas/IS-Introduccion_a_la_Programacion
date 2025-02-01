/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.23
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <string.h>

int main() {
    char cadena[100];
    char objetivo;
    char *resultado;
    int contador = 0;

    printf("Ingrese una cadena de caracteres: ");
    scanf("%s", cadena);

    printf("Ingrese el caracter objetivo: ");
    scanf(" %c", &objetivo);

    resultado = strchr(cadena, objetivo);

    // Mientras se encuentre el carácter objetivo en la cadena
    while (resultado != NULL) {
        // Calcular y mostrar la posición del carácter en la cadena
        int posicion = resultado - cadena;
        printf("El caracter %c se encuentra en la posicion %d de la cadena.\n", objetivo, posicion);
        contador++;

        // Buscar el siguiente carácter objetivo en la cadena
        resultado = strchr(resultado + 1, objetivo);
    }

    if (contador == 0) {
        printf("El caracter %c no esta presente en la cadena.\n", objetivo);
    } else {
        printf("El caracter %c aparece %d veces en la cadena.\n", objetivo, contador);
    }

    return 0;
}
