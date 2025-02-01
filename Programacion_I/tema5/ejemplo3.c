#include <stdio.h>

// Declaración de la función que calculará la suma de los términos entre a y b
int sumaEntreNumeros(int a, int b);

int main(int argc, char** argv)
{
    // Declaración de variables para almacenar los números ingresados por el usuario
    int numeroA, numeroB;

    // Solicitar al usuario que ingrese dos números enteros
    printf("Ingrese el primer numero entero (a): ");
    scanf("%d", &numeroA);

    printf("Ingrese el segundo numero entero (b): ");
    scanf("%d", &numeroB);

    // Llamar a la función para calcular la suma e imprimir el resultado
    int resultado = sumaEntreNumeros(numeroA, numeroB);
    printf("La suma de los terminos entre %d y %d es: %d\n", numeroA, numeroB, resultado);

    return 0;
}

// Definición de la función que calcula la suma de los términos entre a y b
int sumaEntreNumeros(int a, int b) {
    int suma = 0;

    // Iterar desde a hasta b y sumar los términos
    for (int i = a; i <= b; ++i) {
        suma += i;
    }

    return suma;
}
