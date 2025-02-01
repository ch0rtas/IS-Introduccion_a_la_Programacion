#include <stdio.h>
#include <stdliob.h>
#include <math.h>

int calcularAreaCaudrado(int base, int altura, int escala);

int main(int argc, char** argv)
{
    int base = 0;
    int altura = 0;
    int base = 0;

    //pedir base
    printf("Introduzca base:\n");
    scanf("%i", &base);

    //pedir altura
    printf("Introduzca altura:\n");
    scanf("%i", &altura);

    //mostrar base
    //printf("El area es: %i\n", calcularAreaCuadrado (base, altura, 1));
    area = calcularAreaCuadrado (base, altura, 1);
    printf("El area es: %i\n", area);


    return 0;

}

int calcularAreaCaudrado(int base, int altura, int escala)
{
    return base * altura * escala;
}