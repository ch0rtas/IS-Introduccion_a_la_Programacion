/*
Autor: Manuel Martinez Ramón
Fecha: 2024.03.12
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fd; //file descriptor
    fd = fopen ("datos.txt", "w");

    if(fd == NULL){
        printf("El archivo NO existe.");
    } else {
        printf("El archivo SI existe.");
    }

    fclose (fd);

}
