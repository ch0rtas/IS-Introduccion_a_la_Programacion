/*
Autor: Manuel Martinez Ramón
Fecha: 2024.06.18
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int id;
    char *nombre;
    int dia;
    int mes;
    int anio;
} datosAlumno_t;

typedef enum {
    FALSE,
    TRUE
} bool;

char* leeLineaDinamica() {
    char *linea = NULL;
    int ch;
    size_t len = 0;
    size_t capacity = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (len + 1 >= capacity) {
            capacity = capacity ? capacity * 2 : 1;
            linea = realloc(linea, capacity);
        }
        linea[len++] = ch;
    }
    linea = realloc(linea, len + 1);
    linea[len] = '\0';

    return linea;
}

bool fechaCorrecta(datosAlumno_t alumno) {
    if (alumno.dia < 1 || alumno.dia > 31) return FALSE;
    if (alumno.mes < 1 || alumno.mes > 12) return FALSE;
    if (alumno.anio < 1900 || alumno.anio >= 2025) return FALSE;

    if (alumno.mes == 2) {
        bool esBisiesto = (alumno.anio % 4 == 0 && (alumno.anio % 100 != 0 || alumno.anio % 400 == 0));
        if (esBisiesto) {
            if (alumno.dia > 29) return FALSE;
        } else {
            if (alumno.dia > 28) return FALSE;
        }
    }

    if (alumno.mes == 4 || alumno.mes == 6 || alumno.mes == 9 || alumno.mes == 11) {
        if (alumno.dia > 30) return FALSE;
    }

    return TRUE;
}

datosAlumno_t creaAlumno(char *linea) {
    datosAlumno_t alumno;
    char *token = strtok(linea, ";");
    alumno.nombre = malloc(strlen(token) + 1);
    strcpy(alumno.nombre, token);

    token = strtok(NULL, "/");
    alumno.dia = atoi(token);

    token = strtok(NULL, "/");
    alumno.mes = atoi(token);

    token = strtok(NULL, "\0");
    alumno.anio = atoi(token);

    return alumno;
}

int alumnoMasJoven(datosAlumno_t *ListaAlumnos, int numAlumnos) {
    int idMasJoven = 0;
    for (int i = 1; i < numAlumnos; i++) {
        if (ListaAlumnos[i].anio > ListaAlumnos[idMasJoven].anio ||
            (ListaAlumnos[i].anio == ListaAlumnos[idMasJoven].anio && ListaAlumnos[i].mes > ListaAlumnos[idMasJoven].mes) ||
            (ListaAlumnos[i].anio == ListaAlumnos[idMasJoven].anio && ListaAlumnos[i].mes == ListaAlumnos[idMasJoven].mes && ListaAlumnos[i].dia > ListaAlumnos[idMasJoven].dia)) {
            idMasJoven = i;
        }
    }
    return idMasJoven;
}

int main() {
    datosAlumno_t *ListaAlumnos = NULL;
    int numAlumnos = 0;
    int capacidad = 0;
    bool continuar = TRUE;

    while (continuar) {
        printf("Introduce los datos del alumno (nombre;dd/mm/yyyy): ");
        char *linea = leeLineaDinamica();
        datosAlumno_t alumno = creaAlumno(linea);
        free(linea);

        if (fechaCorrecta(alumno)) {
            if (numAlumnos >= capacidad) {
                capacidad = capacidad ? capacidad * 2 : 1;
                ListaAlumnos = realloc(ListaAlumnos, capacidad * sizeof(datosAlumno_t));
            }

            alumno.id = numAlumnos + 1;
            ListaAlumnos[numAlumnos++] = alumno;

            printf("Quieres introducir otro alumno? (1-Si, 2-No): ");
            int respuesta;
            scanf("%d", &respuesta);
            getchar(); // Limpiar el buffer
            if (respuesta != 1) {
                continuar = FALSE;
            }
        } else {
            printf("Fecha incorrecta, introduce los datos nuevamente.\n");
            free(alumno.nombre);
        }
    }

    printf("\nLista de alumnos en orden inverso:\n");
    for (int i = numAlumnos - 1; i >= 0; i--) {
        printf("ID: %d, Nombre: %s, Fecha de Nacimiento: %02d/%02d/%04d\n", ListaAlumnos[i].id, ListaAlumnos[i].nombre, ListaAlumnos[i].dia, ListaAlumnos[i].mes, ListaAlumnos[i].anio);
    }

    if (numAlumnos > 0) {
        int idMasJoven = alumnoMasJoven(ListaAlumnos, numAlumnos);
        printf("\nEl alumno mas joven es:\n");
        printf("ID: %d, Nombre: %s, Fecha de Nacimiento: %02d/%02d/%04d\n", ListaAlumnos[idMasJoven].id, ListaAlumnos[idMasJoven].nombre, ListaAlumnos[idMasJoven].dia, ListaAlumnos[idMasJoven].mes, ListaAlumnos[idMasJoven].anio);
    }

    for (int i = 0; i < numAlumnos; i++) {
        free(ListaAlumnos[i].nombre);
    }
    free(ListaAlumnos);

    return 0;
}

