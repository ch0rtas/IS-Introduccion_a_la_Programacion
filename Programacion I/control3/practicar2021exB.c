#include <stdio.h>

// Prototipos de funciones
void leerCadena(char cadena[], int maxSize);
void cuentaLetras(char* fraseIn, int* numLetras);
void delReves(char* fraseIn, char* fraseOut, int numLetras);

int main() {
    //while (getchar() != '\n');
    char cadena[16];
    int numLetras = 0;

    printf("Escribe una frase:\n");
    leerCadena(cadena, 15);

    cuentaLetras(cadena, &numLetras);
    printf("El numero de letras es: %i\n", numLetras);

    char cadenaOut[16];
    delReves(cadena, cadenaOut, numLetras);
    printf("La frase al reves es: %s\n", cadenaOut);
    return 0;
}

void leerCadena(char cadena[], int maxSize) {
    char c;
    int i = 0;

    while((c = getchar()) != '\n' && i < maxSize){
        cadena[i++] = c;
    }
    cadena[i] = '\0';
}

void cuentaLetras(char* fraseIn, int* numLetras) {
    *numLetras = 0;

    for (int i = 0; fraseIn[i] != '\0'; i++) {
        if ((fraseIn[i] >= 'a' && fraseIn[i] <= 'z') || (fraseIn[i] == ' ')) {
            (*numLetras)++;
        }
    }
}

void delReves(char* fraseIn, char* fraseOut, int numLetras) {
    for (int i = 0; i < numLetras; i++){
        fraseOut[i] = fraseIn[numLetras - i - 1];
    }
    fraseOut[numLetras] = '\0';
}
