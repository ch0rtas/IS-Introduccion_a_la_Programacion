/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.09
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>

size_t calcular_longitud(const char *cadena) {
    size_t longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

void copiar_cadena(char *destino, const char *origen) {
    size_t i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
}

int main() {
    FILE *archivo;
    char **lineas = NULL;
    char linea[100];
    size_t num_lineas = 0;
    size_t capacidad = 10;
    size_t longitud;

    archivo = fopen("C:\\Users\\manue\\Documents\\cygwin64\\home\\manue\\Programacion II\\tema4\\archivo.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.");
        return 1;
    }

    lineas = (char **)malloc(capacidad * sizeof(char *));

    if (lineas == NULL) {
        printf("Error al asignar memoria.");
        fclose(archivo);
        return 1;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        longitud = calcular_longitud(linea);
        if (linea[longitud - 1] == '\n') {
            linea[longitud - 1] = '\0';
        }

        lineas[num_lineas] = (char *)malloc((longitud + 1) * sizeof(char));
        if (lineas[num_lineas] == NULL) {
            printf("Error al asignar memoria.");
            fclose(archivo);
            for (size_t i = 0; i < num_lineas; ++i) {
                free(lineas[i]);
            }
            free(lineas);
            return 1;
        }

        copiar_cadena(lineas[num_lineas], linea);

        ++num_lineas;

        if (num_lineas >= capacidad) {
            capacidad *= 2;
            lineas = (char **)realloc(lineas, capacidad * sizeof(char *));
            if (lineas == NULL) {
                printf("Error al asignar memoria.");
                fclose(archivo);
                for (size_t i = 0; i < num_lineas; ++i) {
                    free(lineas[i]);
                }
                free(lineas);
                return 1;
            }
        }
    }

    fclose(archivo);

    printf("Contenido del archivo:\n");
    for (size_t i = 0; i < num_lineas; ++i) {
        printf("%s\n", lineas[i]);
    }

    for (size_t i = 0; i < num_lineas; ++i) {
        free(lineas[i]);
    }
    free(lineas);

    return 0;
}
