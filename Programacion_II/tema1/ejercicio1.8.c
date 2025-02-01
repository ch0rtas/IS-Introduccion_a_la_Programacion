/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.13
Curso: INSO 1 - Introducción Programación II

Crear el DNI de un ciudadano concatenando un número de 8 cifras quese el
pasa como parámetro del main y la letra correspondiente
*/

#include <stdio.h>
#include <stdlib.h>

char obtenerLetra(int dni) {
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    int resto = dni % 23;
    return letras[resto];
}

int main(int argc, char *argv[]) {

    int dni = atoi(argv[1]);
    char letra = obtenerLetra(dni);

    printf("El numero de DNI es %d%c\n", dni, letra);

    return 0;
}





