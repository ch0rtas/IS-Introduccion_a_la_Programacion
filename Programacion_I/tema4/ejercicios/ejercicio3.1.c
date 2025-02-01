#include <stdio.h>

int main(int argc, char** argv)
{
    int n = 0;
    float mayor = -9999999;
    //int mayor = -FLOAT_MAX;
    //int mayor = FLOAT_MIN;
    float nuevoNumero = 0;
    float menor = 9999999;
    float sumaNumeros = 0;
    float media = 0;

    printf("Introduzca el numero de numeros a computar: ");
    scanf("%i", &n);
    while(getchar()!='\n'){;}


    for(int i=0; i<n; i++)
    {
        // Pedir nuevo número
        printf("Introduzca el numero en posicion %i: ", i+1);
        scanf("%f", &nuevoNumero);
        while(getchar()!='\n'){;}

        // Calcular si es el mayor
        if(nuevoNumero > mayor)
        {
            mayor = nuevoNumero;
        }

        // Calcular si es el menor
        if(nuevoNumero < menor)
        {
            menor = nuevoNumero;
        }

        sumaNumeros += nuevoNumero;
    }

media = sumaNumeros/n;

printf("\nMayor: %f\nMenor: %f\nMedia: %f\n", mayor, menor, media);

}
