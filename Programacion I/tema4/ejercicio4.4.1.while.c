#include <stdio.h>

int main() {
    char caracter;
    int contador = 0;
    int seguir = 1; // Inicializamos ya que queremos que siempre se ejecute

    printf("Ingresa una palabra (presiona Enter al finalizar): ");

    // Utilizamos getchar para leer cada carácter uno por uno.
    while (seguir) {
        caracter = getchar();
        if (caracter == ' ' || caracter == '\n')
            seguir = 0;
        else
            contador++;
    }

    printf("La palabra tiene %d caracteres.\n", contador);

    return 0;
}
