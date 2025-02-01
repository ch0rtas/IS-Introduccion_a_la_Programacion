#include <stdio.h>

int main() {
    int nUser;

    printf("Introduce la cantidad de numeros (n > 0): ");
    scanf("%d", &nUser);

    if (nUser <= 0) {
        printf("El valor de n debe ser mayor que 0.\n");
        return 1;
    }

    int numero;
    int maximo;
    int minimo;
    int suma = 0;

    printf("Introduce %d numeros:\n", nUser);

    for (int i = 0; i < nUser; i++) {
        scanf("%d", &numero);

        // Actualiza el máximo y el mínimo
        if (numero > maximo) {
            maximo = numero;
        }
        if (numero < minimo) {
            minimo = numero;
        }

        // Suma los números
        //suma += numero; <-- No funciona ¿Por qué?
        suma = suma + numero;
    }

    double media = (double)suma / nUser;

    printf("El numero mas grande es: %d\n", maximo);
    printf("El numero mas pequeño es: %d\n", minimo);
    printf("La media de los numeros es: %.2lf\n", media);

    return 0;
}
