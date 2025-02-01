/*
Autor: Manuel Martinez Ramón
Fecha: 2024.03.24
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar la fecha
typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

// Estructura para archivos de grabacion
typedef struct {
    char nombre[50];
    Fecha fechaGrabacion;
    int formato; // 0: WAV, 1: MP3, 2: OGG
    char estacionAsignada[50];
} ArchivoGrabacion;

// Estructura para las coordenadas geograficas
typedef struct {
    float latitud;
    float longitud;
} Coordenadas;

// Estructura para las estaciones de grabacion
typedef struct {
    char nombre[50];
    Coordenadas coordenadas;
    ArchivoGrabacion **listaGrabaciones;
    int numGrabaciones;
} EstacionGrabacion;

// Funcion para introducir datos de un archivo de grabacion
void introducirArchivo(ArchivoGrabacion *archivos, int*numArchivos) {
    printf("Introduce el nombre del archivo: ");
    scanf("%s", archivos[*numArchivos].nombre);
    printf("Introduce la fecha de grabacion (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &archivos[

*numArchivos].fechaGrabacion.dia, &archivos[*

numArchivos].fechaGrabacion.mes, &archivos[*numArchivos].fechaGrabacion.anio);
    printf("Introduce el formato usado (0 - WAV, 1 - MP3, 2 - OGG): ");
    scanf("%d", &archivos[*numArchivos].formato);
    archivos[*numArchivos].estacionAsignada[0] = '\0'; // Inicializar como cadena vacia
    (*numArchivos)++;
}

// Funcion para introducir datos de una estacion de grabacion
void introducirEstacion(EstacionGrabacion *estaciones, int*numEstaciones) {
    printf("Introduce el nombre de la estacion: ");
    scanf("%s", estaciones[*numEstaciones].nombre);
    printf("Introduce las coordenadas geograficas (latitud longitud): ");
    scanf("%f %f", &estaciones[

*numEstaciones].coordenadas.latitud, &estaciones[*

numEstaciones].coordenadas.longitud);
    
    // Inicializar lista de grabaciones como NULL
    estaciones[*numEstaciones].listaGrabaciones = NULL;
    estaciones[*numEstaciones].numGrabaciones = 0;
    
    (*numEstaciones)++;
}

// Funcion para buscar una estacion por nombre
int buscarEstacion(EstacionGrabacion *estaciones, int numEstaciones, char*nombre) {
    for (int i = 0; i < numEstaciones; i++) {
        if (strcmp(estaciones[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1; // No se encontro la estacion
}

// Funcion para asignar grabaciones a estaciones
void asignarGrabaciones(EstacionGrabacion 

*estaciones, int numEstaciones, ArchivoGrabacion*

archivos, int numArchivos) {
    for (int i = 0; i < numArchivos; i++) {
        if (strlen(archivos[i].estacionAsignada) == 0) { // Si la grabacion no tiene estacion asignada
            printf("\nNombre del archivo: %s\n", archivos[i].nombre);
            printf("Fecha de grabacion: %d/%d/%d\n", archivos[i].fechaGrabacion.dia, archivos[i].fechaGrabacion.mes, archivos[i].fechaGrabacion.anio);
            printf("Formato usado: %d\n", archivos[i].formato);
            
            printf("Estaciones disponibles:\n");
            for (int j = 0; j < numEstaciones; j++) {
                printf("%d - %s\n", j + 1, estaciones[j].nombre);
            }
            
            int opcion;
            do {
                printf("Selecciona una estacion para asignar la grabacion (0 para salir): ");
                scanf("%d", &opcion);
                if (opcion > 0 && opcion <= numEstaciones) {
                    strcpy(archivos[i].estacionAsignada, estaciones[opcion - 1].nombre);
                    estaciones[opcion - 1].listaGrabaciones = (ArchivoGrabacion**)realloc(estaciones[opcion - 1].listaGrabaciones, (estaciones[opcion - 1].numGrabaciones + 1) *sizeof(ArchivoGrabacion*));
                    estaciones[opcion - 1].listaGrabaciones[estaciones[opcion - 1].numGrabaciones++] = &archivos[i];
                    printf("Grabacion asignada a la estacion %s\n", estaciones[opcion - 1].nombre);
                } else if (opcion != 0) {
                    printf("Opcion no valida. Intentalo de nuevo.\n");
                }
            } while (opcion != 0);
        }
    }
}

// Funcion para mostrar los datos de las estaciones
void mostrarDatosEstaciones(EstacionGrabacion *estaciones, int numEstaciones) {
    for (int i = 0; i < numEstaciones; i++) {
        printf("\nEstacion: %s\n", estaciones[i].nombre);
        printf("Coordenadas geograficas: %.6f, %.6f\n", estaciones[i].coordenadas.latitud, estaciones[i].coordenadas.longitud);
        printf("Grabaciones asignadas:\n");
        for (int j = 0; j < estaciones[i].numGrabaciones; j++) {
            printf("- %s\n", estaciones[i].listaGrabaciones[j]->nombre);
        }
    }
}

int main() {
    ArchivoGrabacion archivos[100];
    EstacionGrabacion estaciones[100];
    int numArchivos = 0;
    int numEstaciones = 0;
    
    int opcion;
    
    do {
        printf("\nMenu:\n");
        printf("1 - Introducir datos de un archivo de grabacion\n");
        printf("2 - Introducir datos de una estacion de grabacion\n");
        printf("3 - Asignar grabaciones a estaciones de grabacion\n");
        printf("4 - Mostrar datos de estaciones\n");
        printf("5 - Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                introducirArchivo(archivos, &numArchivos);
                break;
            case 2:
                introducirEstacion(estaciones, &numEstaciones);
                break;
            case 3:
                asignarGrabaciones(estaciones, numEstaciones, archivos, numArchivos);
                break;
            case 4:
                mostrarDatosEstaciones(estaciones, numEstaciones);
                break;
            case 5:
                // Liberar memoria dinamica asignada
                for (int i = 0; i < numEstaciones; i++) {
                    free(estaciones[i].listaGrabaciones);
                }
                break;
            default:
                printf("Opcion no valida. Intentalo de nuevo.\n");
        }
        
    } while(opcion != 5);
    
    return 0;
}