/*
Autor: Manuel Martinez Ramón
Fecha: 2024.05.06
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// Estructura para almacenar la información de las palabras
typedef struct {
    char palabra[MAX_WORD_LENGTH];
    int num_ocurrencias;
    int *lineas;
} palabraInfo_t;

// Estructura para almacenar la lista de información de palabras
typedef struct {
    palabraInfo_t *palabras;
    int num_palabras;
} listaPalabras_t;

// Función para buscar una palabra en la lista de palabras
int buscarPalabra(char *palabra, listaPalabras_t *listaPalabras) {
    for (int i = 0; i < listaPalabras->num_palabras; i++) {
        if (strcmp(listaPalabras->palabras[i].palabra, palabra) == 0) {
            return i; // Se encontró la palabra en la lista
        }
    }
    return -1; // No se encontró la palabra en la lista
}

// Función para examinar una línea y actualizar la lista de palabras
void examinaLinea(char *linea, int numLinea, char **palabras_a_buscar, int num_palabras, listaPalabras_t *listaPalabras) {
    char *token = strtok(linea, " \t\n");
    while (token != NULL) {
        for (int i = 0; i < num_palabras; i++) {
            if (strcmp(token, palabras_a_buscar[i]) == 0) {
                int indice_palabra = buscarPalabra(token, listaPalabras);
                if (indice_palabra != -1) {
                    // La palabra ya está en la lista
                    listaPalabras->palabras[indice_palabra].num_ocurrencias++;
                    listaPalabras->palabras[indice_palabra].lineas = realloc(listaPalabras->palabras[indice_palabra].lineas,
                                                                                sizeof(int) * (listaPalabras->palabras[indice_palabra].num_ocurrencias));
                    listaPalabras->palabras[indice_palabra].lineas[listaPalabras->palabras[indice_palabra].num_ocurrencias - 1] = numLinea;
                } else {
                    // La palabra no está en la lista
                    listaPalabras->num_palabras++;
                    listaPalabras->palabras = realloc(listaPalabras->palabras, sizeof(palabraInfo_t) * listaPalabras->num_palabras);
                    strcpy(listaPalabras->palabras[listaPalabras->num_palabras - 1].palabra, token);
                    listaPalabras->palabras[listaPalabras->num_palabras - 1].num_ocurrencias = 1;
                    listaPalabras->palabras[listaPalabras->num_palabras - 1].lineas = malloc(sizeof(int));
                    listaPalabras->palabras[listaPalabras->num_palabras - 1].lineas[0] = numLinea;
                }
            }
        }
        token = strtok(NULL, " \t\n");
    }
}

// Función para leer dinámicamente una línea de un fichero
char *getline_dynamic(FILE *fd) {
    char *line = NULL;
    int bufsize = 0;
    int pos = 0;
    char c;

    line = malloc(sizeof(char));
    if (line == NULL) {
        perror("Error de asignacion de memoria");
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(fd)) != EOF && c != '\n') {
        if (pos == bufsize) {
            bufsize += 1024;
            line = realloc(line, bufsize * sizeof(char));
            if (line == NULL) {
                perror("Error en realloc");
                exit(EXIT_FAILURE);
            }
        }
        line[pos++] = c;
    }

    if (pos == 0 && c == EOF) {
        free(line);
        return NULL;
    }

    line[pos] = '\0';
    return line;
}

// Función para escribir los resultados en el fichero de salida
void escribirResultado(listaPalabras_t *lista, char *nombreFichOrigen) {
    FILE *output_file;
    char *output_filename = malloc(strlen(nombreFichOrigen) + 5); // ".out" + '\0'
    strcpy(output_filename, nombreFichOrigen);
    char *dot = strrchr(output_filename, '.');
    if (dot == NULL) {
        strcat(output_filename, ".out");
    } else {
        strcpy(dot + 1, "out");
    }
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error al abrir el fichero de salida");
        output_file = stderr; // Volcar errores a la salida de error estándar
    }

    for (int i = 0; i < lista->num_palabras; i++) {
        fprintf(output_file, "%s. Numero de ocurrencias: %d. Lineas:", lista->palabras[i].palabra, lista->palabras[i].num_ocurrencias);
        for (int j = 0; j < lista->palabras[i].num_ocurrencias; j++) {
            fprintf(output_file, " %d", lista->palabras[i].lineas[j]);
        }
        fprintf(output_file, "\n");
        free(lista->palabras[i].lineas);
    }
    free(lista->palabras);
    free(output_filename);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <Nombre de fichero> <Palabras a buscar>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];

    listaPalabras_t listaPalabras;
    listaPalabras.num_palabras = 0;
    listaPalabras.palabras = NULL;

    // Obtener las palabras a buscar de los argumentos de la línea de comandos
    int num_palabras_a_buscar = argc - 2;
    char **palabras_a_buscar = malloc(num_palabras_a_buscar * sizeof(char *));
    if (palabras_a_buscar == NULL) {
        perror("Error de asignacion de memoria");
        return 1;
    }
    for (int i = 0; i < num_palabras_a_buscar; i++) {
        palabras_a_buscar[i] = argv[i + 2];
    }

    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error al abrir el fichero de entrada");
        return 1;
    }

    char *line;
    int numLinea = 0;
    while ((line = getline_dynamic(input_file)) != NULL) {
        numLinea++;
        examinaLinea(line, numLinea, palabras_a_buscar, num_palabras_a_buscar, &listaPalabras);
        free(line);
    }

    fclose(input_file);

    escribirResultado(&listaPalabras, input_filename);

    // Liberar la memoria utilizada
    for (int i = 0; i < num_palabras_a_buscar; i++) {
        free(palabras_a_buscar[i]);
    }
    free(palabras_a_buscar);

    printf("Analisis completado.\n");

    return 0;
}
