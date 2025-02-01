#include <stdio.h>

/*
Lo primero que debemos de realizar en crear las funciones que se nos piden/dan

La primera, void pideMedidas(int *ancho, int *alto, int *grosor), simplemente nos sirve para
pedir al usuario las medidas de la caja, necesitamos que sea una función para pedir las medidas
tantas veces como productos vaya a clasificar

La segunda función nos sirve únicamente para clasificar las medidas de las cajas (datos
proporcionados) y devolver un valor (pre-establecido) para cada tipo de caja

Por último, en la funcion main, la principal, declaramos las variables que vamso a utilizar
Preguntamos al usuario el número de productos a clasificar
Realizamos un contador en el que llame a la función 'pideMedidas' y con un switch y gracias
a la función 'calcularTipoCaja' sumar el número de cajas necesarias y los productos no válidos
Al final, imprimir por pantalla los datos obtenidos
*/

void pideMedidas(int *ancho, int *alto, int *grosor) {
    printf("Introduce las medidas (ancho alto grosor): ");
    scanf("%d %d %d", ancho, alto, grosor);
}

int calculaTipoCaja(int ancho, int alto, int grosor) {
    if (ancho <= 10 && alto <= 10 && grosor <= 15) {
        return 1;  // Caja pequeña
    } else if (ancho <= 20 && alto <= 15 && grosor <= 15) {
        return 2;  // Caja mediana
    } else if (ancho <= 30 && alto <= 25 && grosor <= 20) {
        return 3;  // Caja grande
    } else {
        return 0;  // Producto no válido
    }
}

int main() {
    int numProductos, ancho, alto, grosor;
    int cajasPequenas = 0, cajasMedianas = 0, cajasGrandes = 0, productosNoValidos = 0;

    printf("Numero de productos a clasificar: ");
    scanf("%d", &numProductos);

    for (int i = 0; i < numProductos; ++i) {
        pideMedidas(&ancho, &alto, &grosor);

        int tipoCaja = calculaTipoCaja(ancho, alto, grosor);

        switch (tipoCaja) {
            case 1:
                cajasPequenas++;
                break;
            case 2:
                cajasMedianas++;
                break;
            case 3:
                cajasGrandes++;
                break;
            default:
                productosNoValidos++;
        }
    }

    printf("\nNumero total de cajas usadas: %d\n", cajasPequenas + cajasMedianas + cajasGrandes);
    printf("Numero de cajas pequenias: %d\n", cajasPequenas);
    printf("Numero de cajas medianas: %d\n", cajasMedianas);
    printf("Numero de cajas grandes: %d\n", cajasGrandes);
    printf("Numero de productos no validos: %d\n", productosNoValidos);

    return 0;
}
