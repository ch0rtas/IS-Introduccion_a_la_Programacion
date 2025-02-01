/*
Autor: Manuel Martinez Ramón
Fecha: 2024.05.14
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRUPO 10

typedef struct {
    char nombre[50];
    float nota1;
    float nota2;
    float nota3;
    char grupo[MAX_GRUPO];
} Alumno;

char* leerLineaDinamica(FILE *archivo) {
    char *linea = NULL;
    char caracter;
    int longitud = 0;

    while ((caracter = fgetc(archivo)) != EOF && caracter != '\n') {
        linea = (char*)realloc(linea, (longitud + 1) * sizeof(char));
        if (linea == NULL) {
            printf("Error de memoria.\n");
            exit(1);
        }
        linea[longitud++] = caracter;
    }

    if (caracter == EOF && longitud == 0) {
        free(linea);
        return NULL;
    }

    linea = (char*)realloc(linea, (longitud + 1) * sizeof(char));
    if (linea == NULL) {
        printf("Error de memoria.\n");
        exit(1);
    }
    linea[longitud] = '\0';

    return linea;
}

void guardarAlumnosB(Alumno alumnos[], int numAlumnos);

int main() {
    FILE *archivo;
    char *linea;
    Alumno *alumnos = NULL;
    int numAlumnos = 0;
    int capacidadAlumnos = 0;

    archivo = fopen("alumnos.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while ((linea = leerLineaDinamica(archivo)) != NULL) {
        if (numAlumnos >= capacidadAlumnos) {
            capacidadAlumnos += 10;
            alumnos = (Alumno*)realloc(alumnos, capacidadAlumnos * sizeof(Alumno));
            if (alumnos == NULL) {
                printf("Error de memoria.\n");
                exit(1);
            }
        }

        sscanf(linea, "%[^/]/%f/%f/%f/%s", alumnos[numAlumnos].nombre, &alumnos[numAlumnos].nota1, &alumnos[numAlumnos].nota2, &alumnos[numAlumnos].nota3, alumnos[numAlumnos].grupo);
        numAlumnos++;

        free(linea);
    }

    printf("Media de cada alumno:\n");
    for (int i = 0; i < numAlumnos; i++) {
        printf("%s, Clase: %s, Nota 1: %.1f, Nota 2: %.1f, Nota 3: %.1f\n", alumnos[i].nombre, alumnos[i].grupo, alumnos[i].nota1, alumnos[i].nota2, alumnos[i].nota3);
    }

    fclose(archivo);

    guardarAlumnosB(alumnos, numAlumnos);

    free(alumnos);

    return 0;
}

void guardarAlumnosB(Alumno alumnos[], int numAlumnos) {
    FILE *archivo;
    archivo = fopen("alumnosB.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar los alumnos del grupo INSO1B.\n");
        return;
    }

    for (int i = 0; i < numAlumnos; i++) {
        if (strcmp(alumnos[i].grupo, "INSO1B") == 0) {
            fprintf(archivo, "%s/%.1f/%.1f/%.1f/%s\n", alumnos[i].nombre, alumnos[i].nota1, alumnos[i].nota2, alumnos[i].nota3, alumnos[i].grupo);
        }
    }

    fclose(archivo);
    printf("Se han guardado los alumnos del grupo INSO1B en el archivo alumnosB.txt.\n");
}
