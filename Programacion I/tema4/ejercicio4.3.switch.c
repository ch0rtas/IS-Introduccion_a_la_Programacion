#include <stdio.h>

int main() {
    char caracter;
    
    printf("Ingresa un caracter (b, r, n, v): ");
    scanf(" %c", &caracter);

    switch (caracter) {
        case 'b':
        case 'B':
            printf("Blanco\n");
            break;
        case 'r':
        case 'R':
            printf("Rojo\n");
            break;
        case 'n':
        case 'N':
            printf("Negro\n");
            break;
        case 'v':
        case 'V':
            printf("Verde\n");
            break;
        default:
            printf("No hay ningun color asiganado a la letra '%c'.\n", caracter);
            break;
    }

    return 0;
}
