#include <stdio.h>

int main() {
    char caracter;
    char resultado;

    // Solicitar al usuario un carácter
    printf("Por favor, ingresa un caracter: ");
    scanf("%c", &caracter);

    // Usar operador ternario para comprobar si es mayúscula o minúscula
    resultado = (caracter >= 'A' && caracter <= 'Z') ? 'M' : ((caracter >= 'a' && caracter <= 'z') ? 'm' : 'O');

    // Mostrar el resultado
    printf("El caracter ingresado es una letra %s.\n", (resultado == 'M') ? "mayuscula" : ((resultado == 'm') ? "minuscula" : "no valida"));

    return 0;
}
