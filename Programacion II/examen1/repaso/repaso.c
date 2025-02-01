/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.29
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <string.h>

#define MAX_MESAS 100
#define MAX_TIPO_MATERIAL 10

typedef struct {
    int ancho;
    int alto;
    int fondo;
    char material[MAX_TIPO_MATERIAL];
    float precio;
} Mesa;

void mostrarMenu(){
    printf("\n1- Introducir caracteristicas de una nueva mesa\n");
    printf("2- Mostrar las mesas disponibles\n");
    printf("3- Calcular precio del pedido\n");
    printf("4- Salir\n");
}

void introducirMesa(Mesa *mesas, *num_mesas){
    if(*num_mesas >= MAX_MESAS){
        printf("Numero maximo de mesas alcanzado.");
        return;
    }

    scanf("%i", &mesas[*num_mesas].ancho);
}

int main(int argc, char *argv[]) {

    Mesa mesas[MAX_MESAS]
    int num_mesas = 0;
    int opcion = 0;

    do {
        mostrar_menu();
        printf("Seleccione una opcion: ");
        scanf("%di", &opcion);

        switch(opcion) {
            case 1:
                introducirMesa(mesas, &num_mesas);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 4);

    return 0;
}
