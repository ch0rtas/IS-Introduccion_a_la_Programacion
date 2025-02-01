/*
Autor: Manuel Martinez Ramón
Fecha: 2024.03.12
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipo de la función para leer una línea de forma dinámica
char *leeLineaDinamica();

int main() {
    // Solicitar al usuario que ingrese el nombre del alumno
    printf("Por favor, ingrese el nombre del alumno: ");
    
    // Llamar a la función para leer la línea de forma dinámica
    char *nombreAlumno = leeLineaDinamica();

    // Mostrar el nombre del alumno por pantalla
    printf("El nombre del alumno es: %s\n", nombreAlumno);

    // Liberar la memoria asignada dinámicamente
    free(nombreAlumno);

    return 0;
}

// Definición de la función para leer una línea de forma dinámica
char *leeLineaDinamica() {
    // Tamaño inicial del buffer para almacenar la línea
    int tamanoInicial = 10;
    // Asignar memoria inicial para el buffer
    char *buffer = (char *)malloc(tamanoInicial * sizeof(char));
    // Verificar si la asignación de memoria fue exitosa
    if (buffer == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1); // Salir del programa con error
    }

    // Inicializar un contador para la posición en el buffer
    int contador = 0;
    // Leer caracteres uno por uno hasta encontrar un salto de línea o fin de archivo
    while (1) {
        char caracter = getchar(); // Leer un carácter del flujo de entrada estándar (teclado)

        // Si se alcanzó el final de la línea, agregar el carácter nulo al final del buffer y salir del bucle
        if (caracter == '\n' || caracter == EOF) {
            buffer[contador] = '\0';
            break;
        }

        // Almacenar el carácter en el buffer
        buffer[contador] = caracter;
        contador++;

        // Si el contador alcanza el tamaño del buffer, realojar más memoria
        if (contador == tamanoInicial) {
            tamanoInicial *= 2; // Duplicar el tamaño del buffer
            buffer = (char *)realloc(buffer, tamanoInicial * sizeof(char)); // Realojar más memoria
            // Verificar si la realocación de memoria fue exitosa
            if (buffer == NULL) {
                printf("Error: No se pudo realojar memoria.\n");
                exit(1); // Salir del programa con error
            }
        }
    }

    return buffer; // Devolver el buffer con la línea leída
}
