#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complejo;

// Funciones para operaciones con números complejos
Complejo suma(Complejo num1, Complejo num2) {
    Complejo resultado;
    resultado.real = num1.real + num2.real;
    resultado.imag = num1.imag + num2.imag;
    return resultado;
}

Complejo resta(Complejo num1, Complejo num2) {
    Complejo resultado;
    resultado.real = num1.real - num2.real;
    resultado.imag = num1.imag - num2.imag;
    return resultado;
}

Complejo multiplicacion(Complejo num1, Complejo num2) {
    Complejo resultado;
    resultado.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    resultado.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    return resultado;
}

int main() {
    Complejo num1, num2, resultado;
    int opcion;

    // Solicitar números complejos al usuario
    printf("Ingrese el primer numero complejo:\n");
    printf("Parte Real: ");
    scanf("%f", &num1.real);
    printf("Parte Imaginaria: ");
    scanf("%f", &num1.imag);

    printf("\nIngrese el segundo numero complejo:\n");
    printf("Parte Real: ");
    scanf("%f", &num2.real);
    printf("Parte Imaginaria: ");
    scanf("%f", &num2.imag);

    // Menú de operaciones
    printf("\nSeleccione la operacion a realizar:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n\n");
    printf("Ingrese el numero de la operacion: ");
    scanf("%d", &opcion);

    // Realizar la operación seleccionada
    switch (opcion) {
        case 1:
            resultado = suma(num1, num2);
            printf("\nResultado de la suma: %.2f + %.2fi\n", resultado.real, resultado.imag);
            break;
        case 2:
            resultado = resta(num1, num2);
            printf("\nResultado de la resta: %.2f + %.2fi\n", resultado.real, resultado.imag);
            break;
        case 3:
            resultado = multiplicacion(num1, num2);
            printf("\nResultado de la multiplicacion: %.2f + %.2fi\n", resultado.real, resultado.imag);
            break;
        default:
            printf("\nOpcion no valida\n");
            break;
    }

    return 0;
}
