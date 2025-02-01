#include <stdio.h>

/*
En la función de nombre que nos dan 'int CalcSuma(int input)' realizamos con if los diferentes
casos, en este momento eran dos. Menor a 10 o el resto de números

Por último, en el main, llamar a la función con el numero que se nos proporciona, 88199
En mi caso lo declaro en una variable ya que en un principio, lo hice preguntado al usuario
qué número calcular
*/

// Función recursiva para calcular la suma de las cifras de un número
int CalcSuma(int input) {
    if (input < 10) {
        return input;
    } else {
        return CalcSuma(input / 10) + (input % 10);
    }
}

int main() {
    // Número entero proporcionado (88199)
    int numero = 88199;

    // Calcular la suma de las cifras utilizando la función recursiva
    int suma = CalcSuma(numero);

    // Imprimir el resultado
    printf("La suma de las cifras de %d es: %d\n", numero, suma);

    return 0;
}
