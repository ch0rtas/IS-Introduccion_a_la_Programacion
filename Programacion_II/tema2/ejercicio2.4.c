/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.20
Curso: INSO 1 - Introducción Programación II

El ejercicio requiere implementar un programa en C para realizar
operaciones con números complejos. Se deben definir estructuras para
almacenar números complejos y funciones para realizar operaciones como
suma, resta, multiplicación y división. El programa principal toma
como entrada los operandos y la operación, devolviendo el resultado de
la operación especificada.
*/

#include <stdio.h>

// Estructura para representar números complejos
typedef struct {
    float real;
    float imag;
} Complejo;

// Función para sumar dos números complejos
Complejo suma(Complejo a, Complejo b) {
    Complejo resultado;
    resultado.real = a.real + b.real;
    resultado.imag = a.imag + b.imag;
    return resultado;
}

int main(int argc, char *argv[]) {
    // Verificar que se proporcionen suficientes argumentos
    if (argc != 6) {
        printf("Uso: %s <operación> <real operando 1> <imag operando 1> <real operando 2> <imag operando 2>\n", argv[0]);
        return 1;
    }

    // Convertir argumentos a números flotantes
    char operacion = argv[1][0];
    float real1 = atof(argv[2]);
    float imag1 = atof(argv[3]);
    float real2 = atof(argv[4]);
    float imag2 = atof(argv[5]);

    // Crear números complejos
    Complejo num1 = {real1, imag1};
    Complejo num2 = {real2, imag2};
    Complejo resultado;

    // Realizar la operación según la operación especificada
    switch (operacion) {
        case '+':
            resultado = suma(num1, num2);
            printf("El resultado es: %.1f+%.1fi\n", resultado.real, resultado.imag);
            break;
        default:
            printf("Operación no válida. Las operaciones válidas son: +\n");
            return 1;
    }

    return 0;
}
