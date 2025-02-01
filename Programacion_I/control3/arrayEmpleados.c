#include <stdio.h>

#define NUM_EMPLEADOS 5
#define NUM_TRIMESTRES 4

int main() {
    int ventas[NUM_EMPLEADOS][NUM_TRIMESTRES] = {
        {700, 234, 250, 960},
        {895, 800, 100, 432},
        {790, 634, 850, 560},
        {600, 854, 550, 460},
        {590, 987, 750, 660}
    };

    while (1) {
        // Menú
        printf("\nMenú:\n");
        printf("1. Calcular las ventas acumuladas de cada empleado\n");
        printf("2. Calcular el mínimo de todas las ventas\n");
        printf("3. Salir\n");

        int opcion;
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Calcular las ventas acumuladas de cada empleado
                printf("\nVentas acumuladas de cada empleado:\n");
                for (int i = 0; i < NUM_EMPLEADOS; i++) {
                    int sumaVentas = 0;
                    for (int j = 0; j < NUM_TRIMESTRES; j++) {
                        sumaVentas += ventas[i][j];
                    }
                    printf("E%d: %d\n", i + 1, sumaVentas);
                }
                break;

            case 2:
                // Calcular el mínimo de todas las ventas
                int minVentas = ventas[0][0];
                int empleadoMin = 1;
                int trimestreMin = 1;

                for (int i = 0; i < NUM_EMPLEADOS; i++) {
                    for (int j = 0; j < NUM_TRIMESTRES; j++) {
                        if (ventas[i][j] < minVentas) {
                            minVentas = ventas[i][j];
                            empleadoMin = i + 1;
                            trimestreMin = j + 1;
                        }
                    }
                }

                printf("\nEl mínimo de todas las ventas es %d, correspondiente a E%d en el trimestre %d\n", minVentas, empleadoMin, trimestreMin);
                break;

            case 3:
                // Salir del programa
                printf("Saliendo del programa...\n");
                return 0;

            default:
                printf("Opción no válida. Introduce un número del 1 al 3.\n");
        }
    }

    return 0;
}
