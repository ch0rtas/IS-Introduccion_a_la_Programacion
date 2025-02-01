#include <stdio.h>

/*
Para realizar el siguiente ejercicio he consultado varios foros y youtube ya que no entendía
las reglas del juego

Lo primero que hice fue declarar las funciones que se nos recomendaron y con la búsqueda de
la información ir programando más o menso lo que tenía que realizar cada una

COnforme iba investigando me tocaba practicamente rehacer funciones anteriores ya que necesitaba
modificar parametros o nombrar de diferente forma para que otras funciones pudieran consultar
los datos obtenidos

Por último, en el main simplemente pido al usuario las dos cosas que se pueden hacer, y desde
ese punto, se van llamando a las funciones correspondientes

Después de todo no tengo claro si el juego funciona realmente así, ya que nunca he jugado, por
lo que no se si los datos que proporciona el programa (los %) son correctos
*/

void probMateria();
void probMayor2Pueblos();
double probNumero(int numero);
int casosNumero(int tirada);
void compruebaNumerosRepetidos(int num1, int *num2, int *num3);

int main() {
    int opcion;

    printf("Seleccione una opcion:\n");
    printf("1. Probabilidad de una materia prima\n");
    printf("2. Probabilidad de dos pueblos\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            probMateria();
            break;
        case 2:
            probMayor2Pueblos();
            break;
        default:
            printf("Opcion no valida\n");
            break;
    }

    return 0;
}

void probMateria() {
    int numero;
    printf("Introduce el numero de la materia prima: ");
    scanf("%d", &numero);

    if (numero < 2 || numero > 12) {
        printf("Numero no valido.\n");
        return;
    }

    double probabilidad = probNumero(numero);

    printf("La probabilidad de obtener la materia prima %d es: %.2lf%%\n", numero, probabilidad);
}

void probMayor2Pueblos() {
    int num1, num2, num3;

    printf("Introduce los numeros del los pueblo (0 si no tiene): ");
    scanf("%d %d %d", &num1, &num2, &num3);

    compruebaNumerosRepetidos(num1, &num2, &num3);

    double prob1 = 0.0, prob2 = 0.0, prob3 = 0.0;

    if (num1 != 0) {
        prob1 = probNumero(num1);
        printf("Probabilidad para el primer numero: %.2lf%%\n", prob1 * 100);
    }

    if (num2 != 0) {
        prob2 = probNumero(num2);
        printf("Probabilidad para el segundo numero: %.2lf%%\n", prob2 * 100);
    }

    if (num3 != 0) {
        prob3 = probNumero(num3);
        printf("Probabilidad para el tercer numero: %.2lf%%\n", prob3 * 100);
    }

    double probTotal = 1.0 - ((1.0 - prob1) * (1.0 - prob2) * (1.0 - prob3));

    printf("Probabilidad total de obtener al menos una carta: %.2lf%%\n", probTotal * 100);
}

double probNumero(int numero) {
    int casosPosibles = casosNumero(numero);
    return (double)casosPosibles / 36.0;
}

int casosNumero(int tirada) {
    switch (tirada) {
        case 2:
        case 12:
            return 1;
        case 3:
        case 11:
            return 2;
        case 4:
        case 10:
            return 3;
        case 5:
        case 9:
            return 4;
        case 6:
        case 8:
            return 5;
        case 7:
            return 6;
        default:
            return 0;
    }
}

void compruebaNumerosRepetidos(int num1, int *num2, int *num3) {
    if (*num2 == num1) {
        *num2 = 0;
    }
    if (*num3 == num1) {
        *num3 = 0;
    }
    if (*num3 == *num2) {
        *num3 = 0;
    }
}
