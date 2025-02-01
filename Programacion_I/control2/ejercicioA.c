#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/*
El programa primero va a dividir todos los problemas en diferentes funciones para llamarlas

La primera es generar numeros aleatorios entre el 1 y el 9 'int generarNumero()'

A continuación, deberemos de generar la operación de manera aleatoria, en un principio lo hice
con 4 numeros y dependiendo del valor numérico, asignaba una operación, después lo cambie por un
array por simplitud a la hora de leer código 'char generarOperacion()' y 'int generarResultado()'

Luego meter las tres restricciones excluytentes, para ello con simples if 'int comprobarOperacion()'

Por último, realizar en el main el bucle y llamar a las diferentes funciones
*/

// Genera un número aleatorio entre 1 y 9
int generarNumero() {
    return rand() % 9 + 1;
}

// Genera una operación: '+', '-', '*' o '/'
char generarOperacion() {
    char operaciones[] = {'+', '-', '*', '/'};
    return operaciones[rand() % 4];
}

// Genera el resultado de la operación
int generarResultado(int num1, int num2, char SimboloOperacion) {
    switch (SimboloOperacion) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0; // En caso de operación no válida
    }
}

// Comprueba si la operación es correcta
int comprobarOperacion(int num1, int num2, char SimboloOperacion, int ResOpera) {
    // Verifica que los operandos estén entre 1 y 9
    if (num1 < 1 || num1 > 9 || num2 < 1 || num2 > 9) {
        return 0;
    }

    // Si la operación es división, verifica que sea exacta
    if (SimboloOperacion == '/' && num1 % num2 != 0) {
        return 0;
    }

    // Verifica que el resultado no sea mayor que 200 ni menor que 0
    if (ResOpera >= 201 || ResOpera <= -1) {
        return 0;
    }

    // Verifica que la operación sea correcta
    return (generarResultado(num1, num2, SimboloOperacion) == ResOpera);
}

int main() {
    srand((unsigned int)getpid());

    int num1, num2, ResUsuario;
    char SimboloOperacion, RespuestaUsuario;

    do {
        num1 = generarNumero();
        num2 = generarNumero();
        SimboloOperacion = generarOperacion();

        printf("Calcula: %d %c %d = ?\n", num1, SimboloOperacion, num2);

        do {
            printf("Tu respuesta: ");
            scanf("%d", &ResUsuario);

            if (comprobarOperacion(num1, num2, SimboloOperacion, ResUsuario)) {
                printf("Correcto!\n");
            } else {
                printf("Respuesta incorrecta. Intenta de nuevo.\n");
            }

        } while (!comprobarOperacion(num1, num2, SimboloOperacion, ResUsuario));

        printf("Quieres continuar? (s/n): ");
        scanf(" %c", &RespuestaUsuario);
    } while (RespuestaUsuario == 's' || RespuestaUsuario == 'S');

    return 0;
}
