#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#define PI 3.1416



int main(){

    char caracter;
    int contadorPalabras = 0;
    int comprobarSecuencia = 0;
    int leyendoPalabra = 0;

    while(1){
        caracter = getchar();

        if(caracter == ':' && comprobarSecuencia == 0){
            comprobarSecuencia = 1;
        } else if (comprobarSecuencia == 1 && caracter == 'q'){
            break;
        } else {
            comprobarSecuencia = 0;
        }

        if(caracter == ' ' || caracter == '\n' || caracter == '\t'){
            if(leyendoPalabra == 0){
                ++contadorPalabras;
            }
            leyendoPalabra = 1;
        } else {
            leyendoPalabra = 0;
        }
    }

    printf("Las palabras introducidas son %i.", contadorPalabras);
    return 0;
    
}