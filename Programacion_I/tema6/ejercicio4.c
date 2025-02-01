#include <stdio.h>

int main() {
    // Declarar variables
    int valores[10];
    int suma = 0;
    double media;
    int maximo, minimo;

    // Solicitar al usuario que ingrese 10 valores enteros
    printf("Ingresa 10 valores enteros:\n");
    for (int i = 0; i < 10; ++i) {
        printf("Ingresa el valor #%d: ", i + 1);
        scanf("%d", &valores[i]);
        suma += valores[i];

        // Actualizar el máximo y el mínimo durante la entrada
        if (i == 0 || valores[i] > maximo) {
            maximo = valores[i];
        }
        if (i == 0 || valores[i] < minimo) {
            minimo = valores[i];
        }
    }

    // Calcular la media
    media = (double)suma / 10;

    // Mostrar resultados
    printf("\nResultados:\n");
    printf("Suma: %d\n", suma);
    printf("Media: %.2f\n", media);
    printf("Maximo: %d\n", maximo);
    printf("Minimo: %d\n", minimo);

    // Mostrar la lista en orden inverso
    printf("\nLista en orden inverso:\n");
    for (int i = 9; i >= 0; --i) {
        printf("%d\t", valores[i]);
    }
    printf("\n");

    return 0;
}
