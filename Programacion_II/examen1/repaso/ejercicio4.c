/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.29
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESAS 100
#define MAX_TIPO_MATERIAL 10 //Tamano

typedef struct {
    int ancho;
    int alto;
    int fondo;
    char material[MAX_TIPO_MATERIAL];
    float precio;
} Mesa;

void mostrar_menu() {
    printf("\n1- Introducir caracteristicas de una nueva mesa\n");
    printf("2- Mostrar las mesas disponibles\n");
    printf("3- Calcular precio del pedido\n");
    printf("4- Salir\n");
}

void introducir_mesa(Mesa *mesas, int *num_mesas) {
    if (*num_mesas >= MAX_MESAS) {
        printf("Se ha alcanzado el maximo de mesas permitido.\n");
        return;
    }

    printf("Introduzca alto: ");
    scanf("%d", &mesas[*num_mesas].alto);

    printf("Introduzca ancho: ");
    scanf("%d", &mesas[*num_mesas].ancho);

    printf("Introduzca fondo: ");
    scanf("%d", &mesas[*num_mesas].fondo);

    printf("Introduzca material:\n");
    printf("1 - Plastico\n");
    printf("2 - Cristal\n");
    printf("3 - Madera\n");
    printf("4 - Metal\n");
    printf("Seleccione el material (1-4): ");
    int opcion_material;
    scanf("%d", &opcion_material);
    switch(opcion_material) {
        case 1:
            strcpy(mesas[*num_mesas].material, "Plastico");
            break;
        case 2:
            strcpy(mesas[*num_mesas].material, "Cristal");
            break;
        case 3:
            strcpy(mesas[*num_mesas].material, "Madera");
            break;
        case 4:
            strcpy(mesas[*num_mesas].material, "Metal");
            break;
        default:
            printf("Opcion invalida. Se seleccionara Plastico por defecto.\n");
    }

    printf("Introduzca precio: ");
    scanf("%f", &mesas[*num_mesas].precio);

    (*num_mesas)++;
    printf("Mesa anadida correctamente.\n");
}

void mostrar_mesas(Mesa *mesas, int num_mesas) {
    if (num_mesas == 0) {
        printf("No hay mesas disponibles.\n");
        return;
    }

    printf("\nMesas disponibles:\n");
    for (int i = 0; i < num_mesas; i++) {
        printf("Mesa %d: Tamano: %d/%d/%d, Material: %s, Precio: %.2f\n", i+1, mesas[i].ancho, mesas[i].alto, mesas[i].fondo, mesas[i].material, mesas[i].precio);
    }
}

void calcular_precio_pedido(Mesa *mesas, int num_mesas) {
    if (num_mesas == 0) {
        printf("No hay mesas disponibles para calcular el precio del pedido.\n");
        return;
    }

    printf("Hay %d mesas disponibles.\n", num_mesas);
    printf("Introduzca la lista de indices de mesas separadas por comas sin espacios. Maximo 5 mesas:\n");

    int indices[5];
    int num_mesas_pedido = 0;
    float precio_total = 0;

    char entrada[50];
    fgets(entrada, 50, stdin); // Consumir el salto de línea pendiente en el buffer

    fgets(entrada, 50, stdin);
    char *token = strtok(entrada, ",");
    while (token != NULL && num_mesas_pedido < 5) {
        indices[num_mesas_pedido++] = atoi(token);
        token = strtok(NULL, ",");
    }

    printf("El precio final calculado es: ");

    for (int i = 0; i < num_mesas_pedido; i++) {
        if (indices[i] > 0 && indices[i] <= num_mesas) {
            precio_total += mesas[indices[i]-1].precio;
        } else {
            printf("Indice de mesa invalido: %d\n", indices[i]);
        }
    }

    printf("%.2f\n", precio_total);
}

int main() {
    Mesa mesas[MAX_MESAS];
    int num_mesas = 0;
    int opcion;

    do {
        mostrar_menu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                introducir_mesa(mesas, &num_mesas);
                break;
            case 2:
                mostrar_mesas(mesas, num_mesas);
                break;
            case 3:
                calcular_precio_pedido(mesas, num_mesas);
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
