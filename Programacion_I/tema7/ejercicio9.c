#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 25

int main() {
    char nombre[MAX_LENGTH];
    char apellido[MAX_LENGTH];
    char nombreCompleto[MAX_LENGTH * 2];  // Suponemos que el nombre y apellido no excederán MAX_LENGTH cada uno

    // Solicitar al usuario el nombre
    printf("Ingrese su nombre (max %d caracteres): ", MAX_LENGTH - 1);
    scanf("%s", nombre);

    // Solicitar al usuario el apellido
    printf("Ingrese su apellido (max %d caracteres): ", MAX_LENGTH - 1);
    scanf("%s", apellido);

    // Concatenar el nombre y el apellido en la cadena nombreCompleto
    strcpy(nombreCompleto, nombre);
    strcat(nombreCompleto, " ");  // Añadir un espacio entre el nombre y el apellido
    strcat(nombreCompleto, apellido);

    // Mostrar la cadena resultante
    printf("\nNombre completo: %s\n", nombreCompleto);

    return 0;  // Salir con éxito
}
