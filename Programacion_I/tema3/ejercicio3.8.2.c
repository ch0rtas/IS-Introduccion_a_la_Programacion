#include <stdio.h>
// Está a medias
int main() {

    int num=0;
    int exp=0;

    // Pedir al usuario la base y el exponente
    printf("Ingrese número a multiplicar: ");
    scanf("%lf", &base);
    
    printf("Ingrese el exponente (debe ser mayor a cero): ");
    scanf("%d", &exponente);

    // Verificar que el exponente sea mayor a cero
    if (exponente <= 0) {
        printf("El exponente debe ser mayor a cero.\n");
        return 1; // Salir del programa con un código de error
    }

    // Calcular la potencia
    for (int i = 1; i <= exponente; i++) {
        resultado *= base;
    }

    // Mostrar el resultado
    printf("%.2lf elevado a la %d es igual a %.2lf\n", base, exponente, resultado);

    return 0;
}
