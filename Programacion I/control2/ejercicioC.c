#include <stdio.h>

/*
Primero declaramos las variables que vamos a utilizar, en este caso 4

Para detectar ' :q' en un principio lo realicé con array, pero creo que no los podemos utilizar
hasta los ejercicios del tema siguiente.
Por lo que me fuí a los ejercicios que realizamos en clase con la profesora sustituta ya que
eran muy parecidos y adapté el codigo que nos proporcionó
El código simplemnete verifica que si existe un caracter verifique el siguiente y si se trata
de la secuencia mágica, rompe el bucle
*/

int main() {
    char caracter;
    int contadorPalabras = 0;
    int leyendoPalabra = 0;  // Variable para indicar si estamos leyendo una palabra actualmente
    int estadoSecuencia = 0;  // Variable para controlar la secuencia de terminación ":q"

    printf("Introduce texto. Para finalizar, escribe ':q' seguido de un salto de linea.\n");

    while (1) {
        caracter = getchar();

        // Verificar si el caracter es parte de la secuencia de terminación ":q"
        if (estadoSecuencia == 0 && caracter == ':') {
            estadoSecuencia = 1;
        } else if (estadoSecuencia == 1 && caracter == 'q') {
            // Se ha detectado la secuencia completa ":q", salir del bucle
            break;
        } else {
            // Si no forma parte de la secuencia, reiniciar el estado
            estadoSecuencia = 0;
        }

        // Verificar si el caracter es un espacio o salto de línea para contar palabras
        if (caracter == ' ' || caracter == '\n' || caracter == '\t') {
            if (leyendoPalabra == 0) {
                // Si no estamos leyendo una palabra, incrementar el contador de palabras
                contadorPalabras++;
            }
            leyendoPalabra = 1;
        } else {
            leyendoPalabra = 0;
        }
    }

    // Imprimir el resultado
    printf("Numero de palabras introducidas: %d\n", contadorPalabras);

    return 0;
}
