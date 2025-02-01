/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.13
Curso: INSO 1 - Introducción Programación II

La entrada será /nombre primer_apellido segundo_apellido, nombre
Mostrar por pantalla el nombre completo de un alumno: <nombre> <primer apellido> <segundo apellido>

*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i = 1;
    int j = 1;
    int found = 0;

    while (i < argc && !found) {
        if (strcmp(argv[i], "%s,") == 0) {
            found = 1;
        } else {
            i++;
        }
    }

    printf("Elementos argv leidos: %i\n", i);
    printf("%s ", argv[i]);

    for (j = 1; j < i-1; j++) {
        printf("%s ", argv[j]);
    }

    printf("\n");

    return 0;
}




