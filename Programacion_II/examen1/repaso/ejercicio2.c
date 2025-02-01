/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.29
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 11

typedef struct {
    char nombre[MAX_NAME_LENGTH];
    int fuerza;
    int salud;
    char tipo_arma[10];
} Gladiador;

void atacar(Gladiador *atacante, Gladiador *defensor) {
    int danio;
    if (strcmp(atacante->tipo_arma, "espada") == 0) {
        danio = atacante->fuerza;
    } else if (strcmp(atacante->tipo_arma, "lanza") == 0) {
        danio = 2 * atacante->fuerza;
    }

    printf("%s ataca a %s con un danio de %d\n", atacante->nombre, defensor->nombre, danio);
    defensor->salud -= danio;
}

void defenderse(Gladiador *defensor) {
    printf("%s se defiende\n", defensor->nombre);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc != 3) {
        printf("Uso: %s <nombre1>,<fuerza1>,<tipo_arma1> <nombre2>,<fuerza2>,<tipo_arma2>\n", argv[0]);
        return 1;
    }

    Gladiador jugador, cpu;
    char *token;
    token = strtok(argv[1], ",");
    strcpy(jugador.nombre, token);
    token = strtok(NULL, ",");
    jugador.fuerza = atoi(token);
    jugador.salud = 100;
    token = strtok(NULL, ",");
    strcpy(jugador.tipo_arma, token);

    token = strtok(argv[2], ",");
    strcpy(cpu.nombre, token);
    token = strtok(NULL, ",");
    cpu.fuerza = atoi(token);
    cpu.salud = 100;
    token = strtok(NULL, ",");
    strcpy(cpu.tipo_arma, token);

    printf("Comienza la batalla entre %s y %s\n", jugador.nombre, cpu.nombre);

    while (jugador.salud > 0 && cpu.salud > 0) {
        // Turno del jugador
        printf("\nTurno de %s\n", jugador.nombre);
        printf("1. Atacar\n");
        printf("2. Defenderse\n");
        int opcion;
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            atacar(&jugador, &cpu);
        } else if (opcion == 2) {
            defenderse(&jugador);
        } else {
            printf("Opcion no valida. Se pierde el turno.\n");
        }

        // Turno de la CPU
        printf("\nTurno de %s\n", cpu.nombre);
        if (rand() % 2 == 0) {
            atacar(&cpu, &jugador);
        } else {
            defenderse(&cpu);
        }

        printf("\nSalud actual:\n%s: %d\n%s: %d\n", jugador.nombre, jugador.salud, cpu.nombre, cpu.salud);
    }

    if (jugador.salud <= 0) {
        printf("\n%s ha ganado la batalla!\n", cpu.nombre);
    } else {
        printf("\n%s ha ganado la batalla!\n", jugador.nombre);
    }

    return 0;
}
