/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.20
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>

#define INT 1
#define FLOAT 2
#define CHAR 3

struct lectura_datos {
    int tipo; // INT, FLOAT o CHAR
    union {
        int i;
        float f;
        char str[4];
    };
};

// Función para pedir datos y rellenar la estructura
void pedirDatos(struct lectura_datos *datos) {
    printf("Ingrese el tipo de dato (1: Integer, 2: Float, 3: Char[3]): ");
    scanf("%d", &datos->tipo);
    switch (datos->tipo) {
        case INT:
            printf("Ingrese un entero: ");
            scanf("%i", &datos->i);
            break;
        case FLOAT:
            printf("Ingrese un flotante: ");
            scanf("%f", &datos->f);
            break;
        case CHAR:
            printf("Ingrese una cadena de hasta 3 caracteres: ");
            scanf("%s", datos->str);
            break;
        default:
            printf("Tipo de dato no válido\n");
            break;
    }
}

// Función para mostrar el contenido de la estructura
void mostrarDatos(struct lectura_datos datos) {
    switch (datos.tipo) {
        case INT:
            printf("Integer: %d\n", datos.i);
            break;
        case FLOAT:
            printf("Float: %.2f\n", datos.f);
            break;
        case CHAR:
            printf("Char: %s\n", datos.str);
            break;
        default:
            printf("Tipo de dato no válido\n");
            break;
    }
}

int main() {
    struct lectura_datos datos;

    // Pedir y mostrar datos
    pedirDatos(&datos);
    mostrarDatos(datos);

    return 0;
}
