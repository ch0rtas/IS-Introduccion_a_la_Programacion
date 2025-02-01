#include <stdio.h>

int main() {
    char letra;
    int contador = 0;

    printf("Ingresa una palabra: ");

    // Utilizamos getchar para leer cada carácter uno por uno.
    do
    {
        //Leemos el caracter y lo metemos el la variable 'letra'
        letra = getchar();

        if(letra !='\n' && letra !=' ' && letra !='\t' && letra !='.')
        {
            //Sumar 1 a contador
            contador += 1;

            printf("%c\n", letra);
        }
    }
    while (letra !='\n' && letra !=' ' && letra !='\t' && letra !='.');


    printf("La palabra tiene %d caracteres.\n", contador);

    return 0;
}
