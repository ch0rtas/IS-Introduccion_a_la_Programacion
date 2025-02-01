#include <stdio.h>

int main() {
    int numero;
    int tercerCifra;

    // Pedir al usuario que ingrese un número (enetro) de tres cifras
    printf("Ingrese un numero entero de tres cifras: ");
    scanf(" %d", &numero);
    getchar();

    // Verificar si el número es par o impar usando el operador módulo (%)
    if (numero > -999 && numero < 999){
        int terceraCifra = numero / 100; // Sacar la tercera cifra (centenas)
        if (terceraCifra == 1 || terceraCifra == 2 || terceraCifra == 3 || terceraCifra == 5){
            printf("La tercera cifra es %d", terceraCifra);
        } else {
            printf("La tercera cifra no es ni 1 ni 2 ni 3 ni 5");
        }
    } else {
        printf("%d no es un numero de tres cifras.\n", numero);
    }

    return 0;
}
