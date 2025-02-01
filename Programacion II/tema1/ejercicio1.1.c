/*
Autor: Manuel Martinez Ramón
Fecha: 2024.01.30
Curso: INSO 1 - Introducción Programación II

Suma de números reales, con parte real y parte imaginaria.
*/

#include <stdio.h>

// Función para sumar dos números imaginarios y almacenar el resultado en un tercer número imaginario
void sumarNumerosImaginarios(float real1, float imag1, float real2, float imag2, float *resultadoSumaReal, float *resultadoSumaImag) {
    *resultadoSumaReal = real1 + real2;
    *resultadoSumaImag = imag1 + imag2;
}

int main() {
    // Declaración de variables para los números imaginarios
    float real1, imag1, real2, imag2, resultadoSumaReal, resultadoSumaImag;

    // Lectura de los números imaginarios
    printf("Ingrese la parte real del primer numero imaginario: ");
    scanf("%f", &real1);
    printf("Ingrese la parte imaginaria del primer numero imaginario: ");
    scanf("%f", &imag1);

    printf("Ingrese la parte real del segundo numero imaginario: ");
    scanf("%f", &real2);
    printf("Ingrese la parte imaginaria del segundo numero imaginario: ");
    scanf("%f", &imag2);

    // Llamada a la función para sumar los números imaginarios
    sumarNumerosImaginarios(real1, imag1, real2, imag2, &resultadoSumaReal, &resultadoSumaImag);

    // Mostrar el resultado
    printf("La suma de los numeros imaginarios es: %.2f + %.2fi\n", resultadoSumaReal, resultadoSumaImag);

    return 0;
}


