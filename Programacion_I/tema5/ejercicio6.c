#include <stdio.h>
#include <math.h>

int main() {
    // Imprimir encabezado de la tabla
    printf("Ejercicio 6. Mostrar la funcion dada con 4 valores.\n");
    printf("\nx\t|\tf(x)=seno(2x)-x\n");
    printf("----------------------\n");

    // Calcular y mostrar los valores de la función para x = 0, 0.5, 1, 1.5, ..., 10
    for (double x = 0; x <= 10; x += 0.5) {
        double resultado = sin(2 * x) - x;
        printf("%.1f\t|\t%.4f\n", x, resultado);
    }

    return 0;
}
