#include <stdio.h>

int main() {
    char char1, char2, char3;

    printf("Introduce tres caracteres alfabeticos: ");

    // Leer los caracteres
    scanf(" %c %c %c", &char1, &char2, &char3);

    // Comprobar que no están 'ñ' ni 'Ñ' y convertir a minúscula si es necesario
    if ((char1 != 'ñ' && char1 != 'Ñ') &&
        (char2 != 'ñ' && char2 != 'Ñ') &&
        (char3 != 'ñ' && char3 != 'Ñ')) {

        if (char1 >= 'A' && char1 <= 'Z') {
            char1 = char1 + 32; // Convertir a minúscula
        }
        if (char2 >= 'A' && char2 <= 'Z') {
            char2 = char2 + 32; // Convertir a minúscula
        }
        if (char3 >= 'A' && char3 <= 'Z') {
            char3 = char3 + 32; // Convertir a minúscula
        }

        // Ordenar los caracteres alfabéticamente
        if (char1 > char2) {
            char temp = char1;
            char1 = char2;
            char2 = temp;
        }
        if (char2 > char3) {
            char temp = char2;
            char2 = char3;
            char3 = temp;
        }
        if (char1 > char2) {
            char temp = char1;
            char1 = char2;
            char2 = temp;
        }

        // Imprimir los caracteres en orden
        printf("Los caracteres en orden alfabetico son: %c, %c, %c\n", char1, char2, char3);
    } else {
        printf("Alguno de los caracteres no es valido.\n");
    }

    return 0;
}
