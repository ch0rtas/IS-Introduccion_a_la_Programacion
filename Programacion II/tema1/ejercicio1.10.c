/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.13
Curso: INSO 1 - Introducción Programación II

Almacenar alumnos de una clase.
Alumno: Edad, altura, nombre, apellido
Alumno particular: Santiago Castillo, 20 años, 1.81 metros
*/

#include <stdio.h>
#include <string.h>


struct Alumno {
    char Nombre[50];
    char Apellido[100];
    int edad;
    float altura;
};

int main() {

    struct Alumno alumno01 = {"Santiago", "Castillo", 20, 1.81};

    printf("\n");
    printf("Nombre: %s\n", alumno01.Nombre);
    printf("Apellido: %s\n", alumno01.Apellido);
    printf("Edad: %i\n", alumno01.edad);
    printf("Altura: %.2f\n", alumno01.altura);

    return 0;
}






