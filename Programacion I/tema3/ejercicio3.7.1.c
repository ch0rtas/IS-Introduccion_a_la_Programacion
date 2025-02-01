#include <stdio.h>
#include <stdlib.h>

#define BIT_3_A_1 0b00000100

int main() {
    int num=0;
    unsigned char num8bit=0;

    // Solicitar al usuario que ingrese un número de 8 bits
    printf("Por favor, ingresa un numero de 8 bits (0-255): ");
    scanf("%i", &num);

    // Verificar número entre 0 y 255
    if (num >= 0 && num <= 255) {
        // Copiar número a variable de 8 bits
        num8bit=num;
        if(num8bit & BIT_3_A_1){
            printf("El tercer bit es 1\n");
        }else{
            printf("El tercer bit es 0\n");
        }
    } else {
        printf("El numero no esta entre 0 y 255.\n");
    }

    return 0;
}
