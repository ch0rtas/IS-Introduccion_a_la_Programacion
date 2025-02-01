#include <stdio.h>

int main() {
    char letra;
    int contador = 0;

    printf("Ingresa una palabra: ");
    letra = getchar();

    // Utilizamos getchar para leer cada carácter uno por uno.
    while (letra !='\n' && letra !=' ' && letra !='\t' && letra !='.')
    {
        //Volver a leer
        letra = getchar();
        
        //Sumar 1 a contador
        contador += 1;
    }

    printf("La palabra tiene %d caracteres.\n", contador);

    return 0;
}
