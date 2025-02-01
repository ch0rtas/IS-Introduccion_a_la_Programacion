#include <stdio.h>
#include <math.h>

int main() {
    double numero, raiz, margen_error, aproximacion_anterior;

    // Paso 1: Pedir al usuario el número y el margen de error
    printf("Ingrese un numero: ");
    scanf("%lf", &numero);

    printf("Ingrese el margen de error permitido: ");
    scanf("%lf", &margen_error);

    // Inicializar la aproximación con la mitad del número
    aproximacion_anterior = numero / 2.0;

    // Paso 2: Realizar el cálculo de la raíz cuadrada
    do {
        raiz = 0.5 * (aproximacion_anterior + numero / aproximacion_anterior);
        // Actualizar la aproximación anterior para la siguiente iteración
        aproximacion_anterior = raiz;
    } while (fabs(aproximacion_anterior - raiz) > margen_error);

    // Paso 3: Mostrar por pantalla el resultado y el error obtenido
    printf("La raiz cuadrada de %.2lf es aproximadamente %.6lf\n", numero, raiz);
    printf("El error obtenido en el calculo es %.6lf\n", fabs(sqrt(numero) - raiz));

    return 0;
}
