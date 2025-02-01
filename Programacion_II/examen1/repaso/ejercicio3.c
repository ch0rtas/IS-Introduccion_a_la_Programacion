/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.29
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 11
#define MAX_PAREJAS 4
#define MAX_JORNADAS 3

typedef struct {
    char jugador1[MAX_NAME_LENGTH];
    char jugador2[MAX_NAME_LENGTH];
} Pareja;

typedef struct {
    int set1;
    int set2;
} ResultadoPartido;

typedef struct {
    Pareja pareja;
    ResultadoPartido resultados;
} Partido;

typedef struct {
    Partido partidos[MAX_JORNADAS];
} Jornada;

typedef struct {
    Jornada jornadas[MAX_PAREJAS - 1];
} Torneo;

void introducirResultados(Partido *partido) {
    scanf("%d %d", &partido->resultados.set1, &partido->resultados.set2);
}

void mostrarResultadosPartido(const Partido *partido) {
    printf("%s-%s: %d %d\n", partido->pareja.jugador1, partido->pareja.jugador2,
            partido->resultados.set1, partido->resultados.set2);
}

void mostrarTodosLosResultados(const Torneo *torneo, int numeroJornadas, const Pareja *parejas) {
    printf("Resultados de todos los partidos hasta la jornada %d:\n", numeroJornadas);
    for (int i = 0; i < numeroJornadas; ++i) {
        printf("Resultado de la jornada %d:\n", i + 1);
        printf("%s-%s vs %s-%s: ", parejas[0].jugador1, parejas[0].jugador2,
               parejas[1 + i].jugador1, parejas[1 + i].jugador2);
        mostrarResultadosPartido(&torneo->jornadas[i].partidos[0]);

        printf("%s-%s vs %s-%s: ", parejas[2].jugador1, parejas[2].jugador2,
               parejas[3 - i].jugador1, parejas[3 - i].jugador2);
        mostrarResultadosPartido(&torneo->jornadas[i].partidos[1]);
    }
}

void obtenerGanador(const Torneo *torneo, const Pareja *parejas, Pareja *ganadores) {
    int puntos[MAX_PAREJAS] = {0};

    for (int i = 0; i < MAX_JORNADAS; ++i) {
        for (int j = 0; j < MAX_PAREJAS / 2; ++j) {
            if (torneo->jornadas[i].partidos[j].resultados.set1 > torneo->jornadas[i].partidos[j].resultados.set2) {
                puntos[i * 2] += 2;
            } else if (torneo->jornadas[i].partidos[j].resultados.set1 < torneo->jornadas[i].partidos[j].resultados.set2) {
                puntos[i * 2 + 1] += 2;
            } else {
                puntos[i * 2]++;
                puntos[i * 2 + 1]++;
            }
        }
    }

    int maxPuntos = puntos[0];
    int indiceMax = 0;

    for (int i = 1; i < MAX_PAREJAS; ++i) {
        if (puntos[i] > maxPuntos) {
            maxPuntos = puntos[i];
            indiceMax = i;
        }
    }

    *ganadores = parejas[indiceMax];
}

int main(int argc, char *argv[]) {
    if (argc != MAX_PAREJAS * 2 + 1) {
        printf("Debe proporcionar exactamente %d nombres como argumentos.\n", MAX_PAREJAS * 2);
        return 1;
    }

    Pareja parejas[MAX_PAREJAS];
    Torneo torneo = {};
    int indiceArg = 1;

    for (int i = 0; i < MAX_PAREJAS; ++i) {
        strcpy(parejas[i].jugador1, argv[indiceArg++]);
        strcpy(parejas[i].jugador2, argv[indiceArg++]);
    }

    int opcion;
    int numeroJornadas = 0;
    Pareja ganadores;

    do {
        printf("\nMenu:\n");
        printf("1. Introducir resultados de una jornada\n");
        printf("2. Mostrar los resultados de todos los partidos\n");
        printf("3. Obtener la pareja ganadora\n");
        printf("0. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (numeroJornadas < MAX_JORNADAS) {
                    printf("Resultado de la jornada %d:\n", numeroJornadas + 1);
                    printf("%s-%s vs %s-%s: ", parejas[0].jugador1, parejas[0].jugador2,
                           parejas[1 + numeroJornadas].jugador1, parejas[1 + numeroJornadas].jugador2);
                    introducirResultados(&torneo.jornadas[numeroJornadas].partidos[0]);

                    printf("%s-%s vs %s-%s: ", parejas[2].jugador1, parejas[2].jugador2,
                           parejas[3 - numeroJornadas].jugador1, parejas[3 - numeroJornadas].jugador2);
                    introducirResultados(&torneo.jornadas[numeroJornadas].partidos[1]);

                    numeroJornadas++;
                } else {
                    printf("Ya se han introducido los resultados de todas las jornadas.\n");
                }
                break;
            case 2:
                mostrarTodosLosResultados(&torneo, numeroJornadas, parejas);
                break;
            case 3:
                if (numeroJornadas == MAX_JORNADAS) {
                    obtenerGanador(&torneo, parejas, &ganadores);
                    printf("La pareja ganadora es: %s - %s\n", ganadores.jugador1, ganadores.jugador2);
                } else {
                    printf("No se puede determinar la pareja ganadora hasta que se completen las jornadas.\n");
                }
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intentalo de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}
