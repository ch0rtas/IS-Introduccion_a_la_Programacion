#include <stdio.h>

#define SIZE 3

int main() {
    int matriz[SIZE][SIZE];
    int sumaDiagonal = 0;

    // Solicitar al usuario los valores para la matriz
    printf("Ingrese los valores de la matriz cuadrada %dx%d:\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Elemento en la fila %d y columna %d: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Mostrar la matriz por pantalla
    printf("\nMatriz ingresada:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Calcular la suma de la diagonal principal
    for (int i = 0; i < SIZE; i++) {
        sumaDiagonal += matriz[i][i];
    }

    // Mostrar la suma de la diagonal principal
    printf("\nLa suma de los elementos de la diagonal principal es: %d\n", sumaDiagonal);

    return 0;  // Salir con éxito
}
