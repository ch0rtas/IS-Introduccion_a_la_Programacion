#include <stdio.h>

int main() {
    int numero = 0;
    int res = -1;
    char letra = ' ';

    printf("Ingresa un numero entero: ");
    res = scanf("%i", &numero);

    while(res != 1) //Mientras el usuario no introduce nada
    {
        //Limpiar linea/buffer
        while(getchar() != '\n'){;}

        /*
        letra = ' ';
        while(letra != '\n')
        {
            letra = getchar();
        }
        */

        //Volver a pedirlo
        res = -1;
        printf("Ingresa un numero entero correctamente: ");
        res = scanf("%i", &numero);
        while(getchar() != '\n'){;}
    }

    return 0;
}
