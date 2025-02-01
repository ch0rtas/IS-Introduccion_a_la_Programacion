/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.08
Curso: INSO 1 - Introducción Programación II

Realizar un programa que recibe una matriz 3x3 de numeros float a través de la linea de comandos y nos la presente por pantalla.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    float matriz[3][3];

    if (argc != 10) {
        printf("Por favor, proporciona una matriz 3x3 de numeros float.\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = atof(argv[(i * 3) + (j + 1)]);
        }
    }

    printf("\nMatriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}



