#include <stdio.h>

int main() {
    int filasA, columnasA, filasB, columnasB;

    // Solicitar al usuario las dimensiones de la matriz A
    printf("Ingrese el numero de filas de la matriz A: ");
    scanf("%d", &filasA);
    printf("Ingrese el numero de columnas de la matriz A: ");
    scanf("%d", &columnasA);

    // Solicitar al usuario las dimensiones de la matriz B
    printf("Ingrese el numero de filas de la matriz B: ");
    scanf("%d", &filasB);
    printf("Ingrese el numero de columnas de la matriz B: ");
    scanf("%d", &columnasB);

    // Verificar si es posible multiplicar las matrices
    if (columnasA != filasB) {
        printf("Error: No es posible multiplicar las matrices. El numero de columnas de la matriz A debe ser igual al numero de filas de la matriz B.\n");
        return 1;  // Terminar el programa con código de error
    }

    int matrizA[filasA][columnasA], matrizB[filasB][columnasB], resultado[filasA][columnasB];

    // Ingresar elementos de la matriz A
    printf("\nIngrese los elementos de la matriz A (%dx%d):\n", filasA, columnasA);
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasA; ++j) {
            printf("Ingrese el elemento en la posicion [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrizA[i][j]);
        }
    }

    // Ingresar elementos de la matriz B
    printf("\nIngrese los elementos de la matriz B (%dx%d):\n", filasB, columnasB);
    for (int i = 0; i < filasB; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            printf("Ingrese el elemento en la posicion [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrizB[i][j]);
        }
    }

    // Inicializar la matriz resultado con ceros
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            resultado[i][j] = 0;
        }
    }

    // Calcular la multiplicación de las matrices
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            for (int k = 0; k < columnasA; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    // Mostrar la matriz resultado
    printf("\nMatriz resultado:\n");
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            printf("%d\t", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
