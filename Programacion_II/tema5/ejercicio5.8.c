/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.23
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Estructura para almacenar cada línea del archivo junto con su número de línea
typedef struct {
    int line_number;
    char *line;
} Line;

int main() {
    const char nombre_archivo[] = "C:\\Users\\manue\\Documents\\cygwin64\\home\\manue\\Programacion II\\tema5\\datos.txt";

    FILE *file;
    char buffer[MAX_LINE_LENGTH];
    Line *lines = NULL; // Arreglo dinámico de estructuras Line
    int num_lines = 0;
    int i;

    // Abrir el archivo en modo lectura
    file = fopen(nombre_archivo, "r");
    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo.\n");
        return 1;
    }

    // Leer el archivo línea por línea
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        // Aumentar el tamaño del arreglo dinámico
        lines = realloc(lines, (num_lines + 1) * sizeof(Line));
        if (lines == NULL) {
            fprintf(stderr, "Error de asignación de memoria.\n");
            fclose(file);
            return 1;
        }

        // Asignar memoria para almacenar la línea y copiarla
        lines[num_lines].line = malloc(strlen(buffer) + 1);
        if (lines[num_lines].line == NULL) {
            fprintf(stderr, "Error de asignación de memoria.\n");
            fclose(file);
            return 1;
        }
        strcpy(lines[num_lines].line, buffer);

        // Guardar el número de línea
        lines[num_lines].line_number = num_lines + 1;

        num_lines++;
    }

    // Cerrar el archivo
    fclose(file);

    // Imprimir las líneas almacenadas con sus números de línea
    printf("Contenido del archivo:\n");
    for (i = 0; i < num_lines; i++) {
        printf("%d: %s", lines[i].line_number, lines[i].line);
        free(lines[i].line); // Liberar la memoria asignada para cada línea
    }

    // Liberar la memoria del arreglo dinámico
    free(lines);

    return 0;
}
