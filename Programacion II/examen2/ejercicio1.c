/*
Autor: Manuel Martinez Ramón
Fecha: 2024.03.23
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCOGNITA '?'
#define AGUA 'O'

typedef struct {
    int fila;
    int columna;
} coordenadas_t;

typedef struct {
    int fila;
    int columna;
    char resultado[50];
} intento_t;

typedef struct {
    intento_t* intentos;
    int numIntentos;
} listaIntentos_t;

char** crearMatriz(int numFilasColumnas) {
    char** matriz = (char**)malloc(numFilasColumnas *sizeof(char*));
    for (int i = 0; i < numFilasColumnas; i++) {
        matriz[i] = (char*)malloc(numFilasColumnas* sizeof(char));
    }
    return matriz;
}

void rellenaMatriz(char** matriz, char valor, int numFilasColumnas) {
    for (int i = 0; i < numFilasColumnas; i++) {
        for (int j = 0; j < numFilasColumnas; j++) {
            matriz[i][j] = valor;
        }
    }
}

intento_t pedirIntento() {
    intento_t nuevoIntento;
    printf("Introduce la fila y columna (ejemplo: 1 2): ");
    scanf("%d %d", &nuevoIntento.fila, &nuevoIntento.columna);
    return nuevoIntento;
}

void testeaIntento(char** matriz, intento_t* nuevoIntento, coordenadas_t coordenadasBomba, int numFilasColumnas) {
    if (nuevoIntento->fila == coordenadasBomba.fila && nuevoIntento->columna == coordenadasBomba.columna) {
        strcpy(nuevoIntento->resultado, "Bomba encontrada");
        printf("**********BOOM**********\n");
        exit(0);
    } else if (nuevoIntento->fila == coordenadasBomba.fila) {
        strcpy(nuevoIntento->resultado, "La bomba esta en esta fila");
        matriz[nuevoIntento->fila][nuevoIntento->columna] = AGUA;
    } else if (nuevoIntento->columna == coordenadasBomba.columna) {
        strcpy(nuevoIntento->resultado, "La bomba esta en esta columna");
        matriz[nuevoIntento->fila][nuevoIntento->columna] = AGUA;
    } else {
        strcpy(nuevoIntento->resultado, "Intento fallido");
        matriz[nuevoIntento->fila][nuevoIntento->columna] = AGUA;
    }
}

void insertaIntentoEnLista(intento_t*intentos, intento_t nuevoIntento, int* numIntentos) {
    intentos[*numIntentos] = nuevoIntento;
    (*numIntentos)++;
}

void mostrarMatriz(char** matriz, int numFilasColumnas) {
    for (int i = 0; i < numFilasColumnas; i++) {
        for (int j = 0; j < numFilasColumnas; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarIntentos(intento_t* intentos, int numIntentos) {
    for (int i = 0; i < numIntentos; i++) {
        printf("Intento %d - Fila: %d, Columna: %d, Resultado: %s\n", i+1, intentos[i].fila, intentos[i].columna, intentos[i].resultado);
    }
}

void mostrarMenu(char** matriz, coordenadas_t coordenadasBomba, listaIntentos_t* intentos, int numFilasColumnas) {
    int opcion;
    do {
        printf("\nMenu:\n");
        printf("1. Buscar la bomba\n");
        printf("2. Visualizar los intentos\n");
        printf("3. Visualizar la matriz\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                intento_t nuevoIntento = pedirIntento();
                testeaIntento(matriz, &nuevoIntento, coordenadasBomba, numFilasColumnas);
                insertaIntentoEnLista(intentos->intentos, nuevoIntento, &intentos->numIntentos);
                break;
            }
            case 2: {
                mostrarIntentos(intentos->intentos, intentos->numIntentos);
                break;
            }
            case 3: {
                mostrarMatriz(matriz, numFilasColumnas);
                break;
            }
            case 4: {
                printf("Mostrando la matriz con la ubicacion de la bomba:\n");
                matriz[coordenadasBomba.fila][coordenadasBomba.columna] = 'X';
                mostrarMatriz(matriz, numFilasColumnas);
                printf("Liberando memoria dinamica...\n");
                for (int i = 0; i < numFilasColumnas; i++) {
                    free(matriz[i]);
                }
                free(matriz);
                free(intentos->intentos);
                exit(0);
                break;
            }
            default:
                printf("Opcion invalida. Intentalo de nuevo.\n");
        }
    } while (opcion != 4);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s <tamaño_matriz>\n", argv[0]);
        return 1;
    }

    int numFilasColumnas = atoi(argv[1]);
    char** matriz = crearMatriz(numFilasColumnas);
    rellenaMatriz(matriz, INCOGNITA, numFilasColumnas);

    coordenadas_t coordenadasBomba;
    coordenadasBomba.fila = rand() % numFilasColumnas;
    coordenadasBomba.columna = rand() % numFilasColumnas;

    listaIntentos_t intentos;
    intentos.intentos = (intento_t*)malloc(numFilasColumnas* numFilasColumnas * sizeof(intento_t));
    intentos.numIntentos = 0;

    mostrarMenu(matriz, coordenadasBomba, &intentos, numFilasColumnas);

    free(matriz);
    free(intentos.intentos);

    return 0;
}