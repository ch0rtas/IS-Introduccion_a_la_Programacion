//seccion preprocesador
#include <stdio.h>
#include <stdlib.h>

#define EDAD 4
#define TRUE 1
#define FALSE 0

//seccion cabeceras y variables globales

//variable nano usada por printf
char nano = '5';

/*
funcion main

Punto de entrada del programa.

Declara las variables enteras edad y valorf1.
Imprime por pantalla el valor de la variable entera EDAD.
Imprime por pantalla el valor de la variable entera edad.
Imprime por pantalla el valor de la variable tipo care¡acter nano
Llama a la función f1, le pasa por parámetros la variable entera edad y
almacena en la variable valorf1 el valor devuelto.
Comprueba si el valor de valorf1 es 33.
    Si es igual a 33 imprime por pantalla "f1 vale 33".
    Si no es igual a 33 imprime por pantalla "f1 NO vale 33"
Retorna 0
*/

/*
funcion f1

Imprime en pantalla el caracter definido en la variable nano definida en
sección de variable globales.
Recibe por paramaetros una variable de tipo entero que se llama edad y la
imprime en pantalla.
Devuelve el valor 33 de tipo entero.
*/

int f1(int edad);
int main();


int main()
{

    int edad = 6;
    int valorf1 = 0;

    printf("La edad(EDAD) es %i\n",EDAD);
    printf("La edad es %i\n",edad);
    printf("La variable nano es %c\n",nano);

    valorf1 = f1(edad);
    if(valorf1 == 33)
    {
        printf("f1 vale 33\n");
    } else {
        printf("f1 NO vale 33\n");
    }


    return 0;

}


int f1(int edad)
{

    printf("f1: La variable nano es %c\n",nano);
    printf("f1: La edad es %i\n",edad);

    return 33;

}