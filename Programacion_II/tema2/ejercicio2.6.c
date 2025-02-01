/*
Autor: Manuel Martinez Ramón
Fecha: 2024.03.05
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *edades;
    int num_alumnos, i;
    int suma_edades = 0;
    int max_edad, min_edad;

    // Pedir al usuario el número de alumnos
    printf("Introduce el numero de alumnos: ");
    scanf("%d", &num_alumnos);

    // Asignar memoria dinámica para almacenar las edades
    edades = (int*)malloc(num_alumnos * sizeof(int));
    if (edades == NULL) {
        printf("Error: No hay suficiente memoria.\n");
        return 1;
    }

    // Pedir al usuario que ingrese las edades de los alumnos
    printf("Introduce las edades de los alumnos:\n");
    for (i = 0; i < num_alumnos; i++) {
        printf("Edad del alumno %d: ", i + 1);
        scanf("%d", &edades[i]);
        suma_edades += edades[i];

        // Actualizar máximo y mínimo
        if (i == 0 || edades[i] > max_edad) {
            max_edad = edades[i];
        }
        if (i == 0 || edades[i] < min_edad) {
            min_edad = edades[i];
        }
    }

    // Calcular la edad media
    float edad_media = (float)suma_edades / num_alumnos;

    // Imprimir resultados
    printf("\nEdades de los alumnos:\n");
    for (i = 0; i < num_alumnos; i++) {
        printf("%d ", edades[i]);
    }
    printf("\n\nEdad media: %.2f\n", edad_media);
    printf("Maximo de las edades: %d\n", max_edad);
    printf("Minimo de las edades: %d\n", min_edad);

    // Liberar memoria
    free(edades);

    return 0;
}
