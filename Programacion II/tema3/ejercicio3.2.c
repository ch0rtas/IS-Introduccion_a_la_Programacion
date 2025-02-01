/*
Autor: Manuel Martinez Ramón
Fecha: 2024.03.12
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo de la función para leer una línea de forma dinámica
char *leeLineaDinamica(int *TamLinea);

int main() {
    // Número de grupos en U-tad
    int numGrupos = 3;

    // Solicitar al usuario que ingrese los nombres de los alumnos para cada grupo
    for (int i = 1; i <= numGrupos; i++) {
        printf("Grupo %d de U-tad:\n", i);
        printf("Por favor, ingrese los nombres de los alumnos (separados por comas y sin espacios): ");

        // Variable para almacenar el tamaño total de memoria reservada para los nombres de los alumnos
        int tamanoTotal = 0;

        // Arreglo de punteros para almacenar los nombres de los alumnos
        char **nombresAlumnos = NULL;

        // Variable para almacenar la cantidad de nombres de alumnos ingresados
        int numAlumnos = 0;

        // Leer los nombres de los alumnos para el grupo actual
        char *nombreAlumno;
        while ((nombreAlumno = leeLineaDinamica(&tamanoTotal)) != NULL) {
            // Realojar memoria para el arreglo de punteros de nombres de alumnos
            nombresAlumnos = (char **)realloc(nombresAlumnos, (numAlumnos + 1) * sizeof(char *));
            // Verificar si la realocación de memoria fue exitosa
            if (nombresAlumnos == NULL) {
                printf("Error: No se pudo realojar memoria.\n");
                exit(1); // Salir del programa con error
            }

            // Almacenar el nombre del alumno en el arreglo de punteros
            nombresAlumnos[numAlumnos] = nombreAlumno;
            numAlumnos++;
        }

        // Mostrar los nombres de los alumnos por pantalla para el grupo actual
        printf("\nNombres de los alumnos para el grupo %d:\n", i);
        for (int j = 0; j < numAlumnos; j++) {
            printf("%s\n", nombresAlumnos[j]);
        }

        // Liberar la memoria asignada dinámicamente para los nombres de los alumnos
        for (int j = 0; j < numAlumnos; j++) {
            free(nombresAlumnos[j]);
        }
        free(nombresAlumnos);
    }

    return 0;
}

// Definición de la función para leer una línea de forma dinámica
char *leeLineaDinamica(int *TamLinea) {
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
    // Leer caracteres uno por uno hasta encontrar una coma, un salto de línea o fin de archivo
    while (1) {
        char caracter = getchar(); // Leer un carácter del flujo de entrada estándar (teclado)

        // Si se alcanzó el final de la línea, agregar el carácter nulo al final del buffer y salir del bucle
        if (caracter == '\n' || caracter == EOF || caracter == ',') {
            buffer[contador] = '\0';
            *TamLinea = contador + 1; // Actualizar el tamaño de la línea (incluyendo el carácter nulo)
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

    // Si la línea leída es vacía, devolver NULL
    if (contador == 0 && buffer[contador] == '\0') {
        free(buffer);
        return NULL;
    }

    // Eliminar los espacios en blanco al final del nombre del alumno
    while (contador > 0 && (buffer[contador - 1] == ' ' || buffer[contador - 1] == '\t')) {
        buffer[contador - 1] = '\0';
        contador--;
    }

    return buffer; // Devolver el buffer con la línea leída
}
