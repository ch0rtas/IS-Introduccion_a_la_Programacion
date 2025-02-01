/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.13
Curso: INSO 1 - Introducción Programación II

Utilizando punteros ->
*/

#include <stdio.h>
#include <string.h>

// Definición de la estructura Alumno
struct Alumno {
    int numLista;
    char nombre[30];
};

int main() {
    // Declaración de una variable struct Alumno llamada JJ
    struct Alumno JJ;
    // Declaración de un puntero a struct Alumno llamado pJJ
    struct Alumno *pJJ; // Cambiado '+' a '*' para declarar un puntero

    // Asignación de la dirección de JJ al puntero pJJ
    pJJ = &JJ; // Utiliza '&' para obtener la dirección de JJ
    // Asignación de un valor a la variable numLista mediante el puntero pJJ
    pJJ->numLista = 5; // Utiliza '=' para asignar y corrige el operador
    // Copia la cadena "Juan" en el miembro nombre de la estructura mediante el puntero pJJ
    strcpy(pJJ->nombre, "Juan"); // Utiliza '->' para acceder a los miembros de un puntero de estructura

    // Mostrar los datos del alumno por pantalla
    printf("Numero de lista: %d\n", pJJ->numLista);
    printf("Nombre: %s\n", pJJ->nombre);

    return 0;
}








