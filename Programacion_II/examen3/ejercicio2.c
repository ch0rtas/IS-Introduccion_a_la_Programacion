/*
Autor: Manuel Martinez Ramón
Fecha: 2024.05.06
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void split_and_write(FILE *input, FILE *output, int max_line_length) {
    char buffer[MAX_LINE_LENGTH];
    char *word;
    while (fgets(buffer, sizeof(buffer), input) != NULL) {
        int len = strlen(buffer);
        int start = 0;
        while (start < len) {
            int end = start + max_line_length;
            if (end >= len)
                end = len - 1;
            else {
                while (buffer[end] != ' ' && buffer[end] != '\n' && end > start)
                    end--;
                if (end == start)
                    end = start + max_line_length;
            }
            if (start != end && buffer[end] != '\n') {
                if (end < len - 1) {
                    if (buffer[end] != ' ') {
                        while (buffer[end] != ' ' && end > start)
                            end--;
                        if (end == start)
                            end = start + max_line_length;
                        fwrite(buffer + start, sizeof(char), end - start, output);
                        fprintf(output, "-\n");
                    } else {
                        fwrite(buffer + start, sizeof(char), end - start, output);
                        fprintf(output, "\n");
                    }
                } else {
                    fwrite(buffer + start, sizeof(char), end - start, output);
                    fprintf(output, "\n");
                }
            }
            start = end + 1;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s <nombre_del_fichero_entrada> <nombre_del_fichero_salida> <numero_de_caracteres_maximo>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    int max_line_length = atoi(argv[3]);

    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("No se pudo abrir el archivo de entrada %s\n", input_filename);
        return 1;
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("No se pudo abrir el archivo de salida %s\n", output_filename);
        fclose(input_file);
        return 1;
    }

    split_and_write(input_file, output_file, max_line_length);

    fclose(input_file);
    fclose(output_file);

    printf("Archivo copiado y cortado correctamente.\n");

    return 0;
}
