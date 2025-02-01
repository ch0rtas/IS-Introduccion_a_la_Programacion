/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.08
Curso: INSO 1 - Introducción Programación II

Calculadora que reciba argc/argv. No usar las librerias stdlib.h ni string.h
Las operaciones válidas son "suma", "resta" y "multiplicacion"
El programa se ejecutara de la siguiente forma:
./calculadora.exe OP1=5 OP2=7 OPERACION=suma
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double suma(double op1, double op2) {
    return op1 + op2;
}

double resta(double op1, double op2) {
    return op1 - op2;
}

double multiplicacion(double op1, double op2) {
    return op1 * op2;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s OP1=valor1 OP2=valor2 OPERACION=(suma|resta|multiplicacion)\n", argv[0]);
        return 1;
    }

    double op1, op2, resultado;
    char operacion[20];

    sscanf(argv[1], "OP1=%lf", &op1);
    sscanf(argv[2], "OP2=%lf", &op2);
    sscanf(argv[3], "OPERACION=%s", operacion);

    if (strcmp(operacion, "suma") == 0) {
        resultado = suma(op1, op2);
    } else if (strcmp(operacion, "resta") == 0) {
        resultado = resta(op1, op2);
    } else if (strcmp(operacion, "multiplicacion") == 0) {
        resultado = multiplicacion(op1, op2);
    } else {
        printf("Operación no válida\n");
        return 1;
    }

    printf("Resultado: %.2lf\n", resultado);

    return 0;
}

