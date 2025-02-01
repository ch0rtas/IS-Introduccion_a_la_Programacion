/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.04
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>

int main() {
    FILE *archivo; // Declara un puntero a FILE

    // Abrir el archivo en modo de escritura ("w")
    archivo = fopen("C:\\Users\\manue\\Documents\\cygwin64\\home\\manue\\Programacion II\\tema4\\archivo.txt", "w");

    // Verificar si se pudo abrir el archivo correctamente
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1; // Salir del programa indicando un error
    }

    // Escribir las letras de la A a la Z y de la a a la z, separadas por comas
    for (char letra = 'A'; letra <= 'Z'; letra++) {
        fputc(letra, archivo);
        if (letra != 'Z') {
            fputc(',', archivo);
        }
    }

    // Coma entre las dos cadenas
    fputc(',', archivo);

    for (char letra = 'a'; letra <= 'z'; letra++) {
        fputc(letra, archivo);
        if (letra != 'z') {
            fputc(',', archivo);
        }
    }

    // Cerrar el archivo
    fclose(archivo);

    return 0; // Salir del programa exitosamente
}
