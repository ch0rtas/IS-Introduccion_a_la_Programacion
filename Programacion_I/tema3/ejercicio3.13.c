#include <stdio.h>

int main() {
    long a;
    unsigned char b;
    int c;
    float d;
    float f;

    // Solicitar al usuario que ingrese los valores de las variables
    printf("Ingresa un valor para 'a' (long): ");
    scanf("%ld", &a);

    printf("Ingresa un valor para 'b' (unsigned char): ");
    scanf("%hhu", &b);

    printf("Ingresa un valor para 'c' (int): ");
    scanf("%d", &c);

    printf("Ingresa un valor para 'd' (float): ");
    scanf("%f", &d);

    // Realizar la operación
    f = a + b * c / d;

    // Determinar el tipo de la variable f
    if (f == (long)f) {
        printf("El tipo de dato de la variable f es: long\n");
    } else if (f == (unsigned char)f) {
        printf("El tipo de dato de la variable f es: unsigned char\n");
    } else if (f == (int)f) {
        printf("El tipo de dato de la variable f es: int\n");
    } else {
        printf("El tipo de dato de la variable f es: float\n");
    }

    // Imprimir el resultado
    printf("El resultado de la operacion a + b * c / d es: %f\n", f);

    return 0;
}
