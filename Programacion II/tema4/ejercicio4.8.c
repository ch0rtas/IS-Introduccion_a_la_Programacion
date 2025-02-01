/*
Autor: Manuel Martinez Ramón
Fecha: 2024.04.09
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>

// Estructura para representar un jugador de fútbol
struct Jugador {
    char *nombre;
    int numero_camiseta;
    int goles;
};

// Función para leer una línea de entrada dinámicamente
char *leer_linea() {
    char *linea = NULL;
    size_t longitud = 0;

    if (getline(&linea, &longitud, stdin) == -1) {
        printf("Error al leer la entrada.");
        exit(1);
    }

    return linea;
}

int main() {
    struct Jugador jugador;
    FILE *archivo;
    char nombre_archivo[] = "C:\\Users\\manue\\Documents\\cygwin64\\home\\manue\\Programacion II\\tema4\\info_jugadores.txt";

    archivo = fopen(nombre_archivo, "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.");
        return 1;
    }

    printf("Ingrese el nombre del jugador: ");
    jugador.nombre = leer_linea();

    printf("Ingrese el número de camiseta del jugador: ");
    scanf("%d", &jugador.numero_camiseta);
    while (getchar() != "\n");

    printf("Ingrese el número de goles del jugador: ");
    scanf("%d", &jugador.goles);
    while (getchar() != "\n");

    fprintf(archivo, "Nombre: %s, Numero de camiseta: %d, Goles: %d\n", jugador.nombre, jugador.numero_camiseta, jugador.goles);

    fclose(archivo);

    free(jugador.nombre);

    printf("Los datos se han guardado correctamente en el archivo '%s'.\n", nombre_archivo);

    return 0;
}
