/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.04
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>

int main() {
    FILE *archivo; // Declara un puntero a FILE

    // Abrir el archivo en modo de lectura ("r")
    archivo = fopen("C:\\Users\\manue\\Documents\\cygwin64\\home\\manue\\Programacion II\\tema4\\archivo.txt", "r");

    // Verificar si se pudo abrir el archivo correctamente
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1; // Salir del programa indicando un error
    }

    // Leer y mostrar el contenido del archivo por pantalla
    int caracter;
    while ((caracter = fgetc(archivo)) != EOF) {
        printf("%c", caracter);
    }

    // Cerrar el archivo
    fclose(archivo);

    return 0; // Salir del programa exitosamente
}
