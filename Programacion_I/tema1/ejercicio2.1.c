#include <stdio.h>

int main() {

    int valor;
    int valorEntero;

    // Solicita al usuario que ingrese un valor entre 0 y 10
    printf("Por favor, ingresa un valor entre 0 y 10: \n");
    valorEntero = scanf("%d", &valor);

    // Verifica si scanf pudo leer un valor entero
    if (valorEntero == 1) {
        // Verifica el valor ingresado y muestra el resultado correspondiente
        if (valor < 5) {
            printf("Suspenso\n");
        } else if (valor >= 5 && valor < 9) {
            printf("Aprobado\n");
        } else if (valor >= 9 && valor <= 10) {
            printf("Sobresaliente\n");
        } else {
            printf("El valor ingresado esta fuera del rango permitido (0-10).\n");
        }
    } else {
        printf("Error: No se ha ingresado un valor entero valido.\n");
    }

    return 0;
}
