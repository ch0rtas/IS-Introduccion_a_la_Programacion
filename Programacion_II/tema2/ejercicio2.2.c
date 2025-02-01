/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.20
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>

// Estructura datos_t
typedef struct {
    int edad;
    float peso;
    char nombre[10];
} datos_t;

// Unión datos_u
typedef union {
    int edad;
    float peso;
    char nombre[10];
} datos_u;

void leerCadena(char cadena[], int maxSize) {
    char c;
    int i = 0;
    int intentos = 0;

    do {
        intentos = 0;
        i = 0;

        while ((c = getchar()) != '\n' && i < maxSize) {
            cadena[i++] = c;
        }

        cadena[i] = '\0';


        if (i == 0 || i >= maxSize) {
            printf("Entrada invalida. Intente de nuevo: ");
            intentos++;
            limpiarBuffer();
        }
    } while (intentos > 0);
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    datos_t usuario1;
    datos_u usuario2;

    // Pedir datos_t
    printf("Ingrese la edad: ");
    scanf("%d", &usuario1.edad);
    limpiarBuffer();
    printf("Ingrese el peso: ");
    scanf("%f", &usuario1.peso);
    limpiarBuffer();
    printf("Ingrese el nombre (hasta 10 caracteres): ");
    leerCadena(usuario1.nombre, 10);

    // Mostrar datos_t
    printf("\nDatos ingresados para datos_t:\n");
    printf("Edad: %d\n", usuario1.edad);
    printf("Peso: %.2f\n", usuario1.peso);
    printf("Nombre: %s\n", usuario1.nombre);

    printf("Tamano de edad: %zu bytes\n", sizeof(usuario1.edad));
    printf("Tamano de peso: %zu bytes\n", sizeof(usuario1.peso));
    printf("Tamano de nombre: %zu bytes\n", sizeof(usuario1.nombre));

    // Pedir datos_u
    printf("\nIngrese la edad: ");
    scanf("%d", &usuario2.edad);
    limpiarBuffer();
    printf("Ingrese el peso: ");
    scanf("%f", &usuario2.peso);
    limpiarBuffer();
    printf("Ingrese el nombre (hasta 10 caracteres): ");
    leerCadena(usuario2.nombre, 10);

    // Mostrar datos_u
    printf("\nDatos ingresados para datos_u:\n");
    printf("Edad: %d\n", usuario2.edad);
    printf("Peso: %.2f\n", usuario2.peso);
    printf("Nombre: %s\n", usuario2.nombre);

    printf("Tamano de edad: %zu bytes\n", sizeof(usuario2.edad));
    printf("Tamano de peso: %zu bytes\n", sizeof(usuario2.peso));
    printf("Tamano de nombre: %zu bytes\n", sizeof(usuario2.nombre));

    return 0;
}
