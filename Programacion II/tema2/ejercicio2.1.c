/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.20
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 16

typedef struct {
    char NIF[10]; // 8 dígitos y 1 letra
    char CIF[10]; // 1 letra y 8 dígitos
    char pasaporte[9]; // 8 dígitos o números
    char NIE[10]; // 1 letra, 7 dígitos, y 1 letra
    char nombreUsuario[MAX_NAME_LENGTH + 1]; // Cadena de 16 letras
} identificador;

int main() {
    identificador id;

    // Asignando valores de ejemplo
    strcpy(id.NIF, "12345678A");
    strcpy(id.CIF, "A12345678");
    strcpy(id.pasaporte, "12345678");
    strcpy(id.NIE, "X1234567Z");
    strcpy(id.nombreUsuario, "usuario12345678");

    // Imprimiendo los valores
    printf("NIF: %s\n", id.NIF);
    printf("CIF: %s\n", id.CIF);
    printf("Pasaporte: %s\n", id.pasaporte);
    printf("NIE: %s\n", id.NIE);
    printf("Nombre de usuario: %s\n", id.nombreUsuario);


    printf("\n\n");


    int entero;
    char caracter;
    float flotante;
    double doble;
    long largo;
    
    printf("Tamano de un entero: %zu bytes\n", sizeof(entero));
    printf("Tamano de un caracter: %zu bytes\n", sizeof(caracter));
    printf("Tamano de un flotante: %zu bytes\n", sizeof(flotante));
    printf("Tamano de un double: %zu bytes\n", sizeof(doble));
    printf("Tamano de un long: %zu bytes\n", sizeof(largo));

    return 0;
}












