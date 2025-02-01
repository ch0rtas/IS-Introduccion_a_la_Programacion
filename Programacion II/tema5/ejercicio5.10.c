/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.25
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definir una estructura para almacenar los campos
struct Registro {
    char nombre[100];
    char apellido[100];
    char edad[100];
};

int main() {
    // Abrir el archivo CSV
    FILE *archivo = fopen("archivo_csv.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Abrir el archivo de copia de seguridad
    FILE *copia_seguridad = fopen("copia_seguridad.csv", "w");
    if (copia_seguridad == NULL) {
        printf("Error al abrir el archivo de copia de seguridad.\n");
        fclose(archivo);
        return 1;
    }

    // Definir el delimitador original y el delimitador de la copia de seguridad
    char delimitador_original = ';';
    char delimitador_copia = '/';

    // Leer cada línea del archivo CSV
    char linea[256];
    while (fgets(linea, sizeof(linea), archivo)) {
        // Separar los campos por el delimitador original
        char *token = strtok(linea, ";");

        // Almacenar los campos en la estructura
        struct Registro registro;
        strcpy(registro.nombre, token);

        token = strtok(NULL, ";");
        strcpy(registro.apellido, token);

        token = strtok(NULL, ";");
        strcpy(registro.edad, token);

        // Mostrar los miembros por pantalla
        printf("Nombre: %s\n", registro.nombre);
        printf("Apellido: %s\n", registro.apellido);
        printf("Edad: %s\n", registro.edad);

        // Escribir la línea modificada en el archivo de copia de seguridad
        fprintf(copia_seguridad, "%s%c%s%c%s\n", registro.nombre, delimitador_copia, registro.apellido, delimitador_copia, registro.edad);
    }

    // Cerrar archivos
    fclose(archivo);
    fclose(copia_seguridad);

    return 0;
}
