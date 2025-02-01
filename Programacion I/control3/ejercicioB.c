#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Lo primero que hice fue definir algunas variables que utilizaría a lo largo de todo el código.
Recalcar que he hecho el juego de manera que todas las naves comienzan a la izquierda y gana
la primera en llegar al final, la derecha. Lo digo porque no entendí muy bien la mecánica del
juego y se me hizo bastante confunsas la captura del ejemplo aportada.
En primer lugar declaramos todas las funciones que utilizaremos para realizar el juego.
En el main unicamente llamamos a distintas funciones para ejercutar las diferentes partes del
juego además de recoger el input del usuario.
La función "inicializarPista" la utilizo para imprimir por pantalla las 50 posiciones con -
"imprimirPista" la utilizo para imprimir pista pero modificando las posiciones de las naves
Las funciones "moverNaveUsuario" y "moverNaveAutomatica" analizan los movimientos de las
diferentes naves, la primera toma en consideración el input del usuario.
Estas dos funciones comprueban que la nueva posición esté libre de naves. Ambas funciones
utilizan la última función que es "generarNumeroAleatorio" la cual simplemente genera numeros
aleatorios para así tener la probabilidad que indica el enunciado.
*/

#define PISTA_LONGITUD 50
#define PROBABILIDAD_OBSTACULO 20
#define PROBABILIDAD_FRENO_AUTOMATICO 30
#define PROBABILIDAD_AVANCE_AUTOMATICO 70

// Funciones
void inicializarPista(char pista[], int longitud);
void imprimirPista(char pista[], int longitud);
void moverNaveUsuario(char pista[], int *posicionUsuario);
void moverNaveAutomatica(char pista[], int *posicionAutomatica, char naveID);
int generarNumeroAleatorio(int min, int max);

int main() {
    char pista[PISTA_LONGITUD];
    int posicionUsuario = 0;
    int posicionAutomatica1 = 0;
    int posicionAutomatica2 = 0;

    // Inicializar la semilla para la generación de números aleatorios
    srand(getpid());

    // Ciclo de la carrera
    while (1) {
        // Inicializar la pista
        inicializarPista(pista, PISTA_LONGITUD);

        // Mover nave del usuario
        moverNaveUsuario(pista, &posicionUsuario);

        // Mover naves automáticas
        moverNaveAutomatica(pista, &posicionAutomatica1, 'O');
        moverNaveAutomatica(pista, &posicionAutomatica2, 'O');

        // Imprimir la pista después del movimiento de todas las naves
        imprimirPista(pista, PISTA_LONGITUD);

        // Verificar si la carrera ha terminado
        if (posicionUsuario >= PISTA_LONGITUD - 1 || posicionAutomatica1 >= PISTA_LONGITUD - 1 || posicionAutomatica2 >= PISTA_LONGITUD - 1) {
            break;
        }

        // Esperar un momento antes de la siguiente iteración para mejor visualización
        sleep(1);
    }

    // Determinar el resultado de la carrera
    if (posicionUsuario >= PISTA_LONGITUD - 1) {
        printf("Felicidades! Has ganado la carrera.\n");
    } else {
        printf("Lo siento! Los oponentes han ganado la carrera.\n");
    }

    return 0;
}

void inicializarPista(char pista[], int longitud) {
    for (int i = 0; i < longitud; i++) {
        pista[i] = '-';
    }
}

void imprimirPista(char pista[], int longitud) {
    for (int i = 0; i < longitud; i++) {
        printf("%c", pista[i]);
    }
    printf("\n");
}

void moverNaveUsuario(char pista[], int *posicionUsuario) {
    char movimiento;

    printf("Jugador: Indique si desea frenar (f) o acelerar (a): ");
    scanf(" %c", &movimiento);

    if (movimiento == 'a') {
        int avance = generarNumeroAleatorio(1, 10);
        printf("Jugador avanzo %d posiciones.\n", avance);
        (*posicionUsuario) += avance;
        // Verificar si hay un obstáculo
        if (generarNumeroAleatorio(1, 100) <= PROBABILIDAD_OBSTACULO) {
            printf("Obstaculo! Jugador retrocedio 3 posiciones.\n");
            (*posicionUsuario) -= 3;
        }
    } else if (movimiento == 'f') {
        printf("Jugador freno 1 posicion.\n");
        (*posicionUsuario) -= 1;
    }

    // Verificar si la posición es válida
    if (*posicionUsuario < 0) {
        *posicionUsuario = 0;
    } else if (*posicionUsuario >= PISTA_LONGITUD) {
        *posicionUsuario = PISTA_LONGITUD - 1;
    }

    // Actualizar la pista con la nueva posición del usuario
    pista[*posicionUsuario] = 'J';
}

void moverNaveAutomatica(char pista[], int *posicionAutomatica, char naveID) {
    int probabilidad = generarNumeroAleatorio(1, 100);

    if (probabilidad <= PROBABILIDAD_FRENO_AUTOMATICO) {
        printf("%c freno 1 posicion.\n", naveID);
        (*posicionAutomatica) += 1;  // Se mueve hacia la derecha al frenar
    } else {
        int avance = generarNumeroAleatorio(1, 10);
        printf("%c avanzo %d posiciones.\n", naveID, avance);
        (*posicionAutomatica) += avance;
        // Verificar si hay un obstáculo
        if (generarNumeroAleatorio(1, 100) <= PROBABILIDAD_OBSTACULO) {
            printf("Obstaculo! %c retrocedio 3 posiciones.\n", naveID);
            (*posicionAutomatica) -= 3;
        }
    }

    // Verificar si la posición es válida
    if (*posicionAutomatica < 0) {
        *posicionAutomatica = 0;
    } else if (*posicionAutomatica >= PISTA_LONGITUD) {
        *posicionAutomatica = PISTA_LONGITUD - 1;
    }

    // Actualizar la pista con la nueva posición de la nave automática
    pista[*posicionAutomatica] = naveID;
}

int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}
