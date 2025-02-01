#include <stdio.h>

int main() {
    // Declarar la matriz de 3x3
    int matriz[3][3];

    // Solicitar al usuario que ingrese los valores de la matriz
    printf("Ingresa los valores de la matriz 3x3:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("Ingresa el valor en la posicion [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Mostrar la matriz por pantalla
    printf("\nMatriz ingresada:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Calcular la suma de la diagonal principal
    int sumaDiagonal = 0;
    for (int i = 0; i < 3; ++i) {
        sumaDiagonal += matriz[i][i];
    }

    // Mostrar la suma de la diagonal principal por pantalla
    printf("\nLa suma de la diagonal principal es: %d\n", sumaDiagonal);

    return 0;
}
