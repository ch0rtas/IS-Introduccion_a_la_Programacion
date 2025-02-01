/*
Autor: Manuel Martinez Ramón
Fecha: 2024.03.05
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *lista1, *lista2;
    int num_elementos, i;

    // Pedir al usuario el número de elementos para las listas
    printf("Introduce el numero de elementos para las listas: ");
    scanf("%d", &num_elementos);

    // Asignar memoria dinámica para las listas
    lista1 = (int*)malloc(num_elementos * sizeof(int));
    lista2 = (int*)malloc(num_elementos * sizeof(int));

    // Inicializar la primera lista con algunos valores
    printf("Introduce %d valores para la primera lista:\n", num_elementos);
    for (i = 0; i < num_elementos; i++) {
        scanf("%d", &lista1[i]);
    }

    // Copiar los valores de la primera lista a la segunda
    for (i = 0; i < num_elementos; i++) {
        lista2[i] = lista1[i];
    }

    // Mostrar los resultados
    printf("\nValores de la primera lista:\n");
    for (i = 0; i < num_elementos; i++) {
        printf("%d ", lista1[i]);
    }
    printf("\nValores de la segunda lista:\n");
    for (i = 0; i < num_elementos; i++) {
        printf("%d ", lista2[i]);
    }
    printf("\n");
    printf("Ubicacion donde incian los punteros: ");
    printf("%p %p", lista1, lista2);

    // Liberar memoria
    free(lista1);
    free(lista2);

    return 0;
}
