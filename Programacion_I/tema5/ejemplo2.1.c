#include <stdio.h>
#include <stdlib.h>

#define SUMA 1
#define RESTA 2
#define MULTI 3
#define SALIR 4

void sumar(int real1, int imag1, int real2, int imag2, int *realRes, int *imagRes) {
    *realRes = real1 + real2;
    *imagRes = imag1 + imag2;
}

void restar(int real1, int imag1, int real2, int imag2, int *realRes, int *imagRes) {
    *realRes = real1 - real2;
    *imagRes = imag1 - imag2;
}

void multiplicar(int real1, int imag1, int real2, int imag2, int *realRes, int *imagRes) {
    *realRes = (real1 * real2) - (imag1 * imag2);
    *imagRes = (real1 * imag2) + (imag1 * real2);
}

void pedirNumeroComplejo(char *mensaje, int *entero, int *imaginario) {
    printf("%s\n", mensaje);
    printf("Parte real: ");
    scanf("%d", entero);
    printf("Parte imaginaria: ");
    scanf("%d", imaginario);
}

void mostrarNumeroImaginario(int real, int imag) {
    printf("Numero imaginario: %d + %di\n", real, imag);
}

int main() {
    int opcion = -1;
    int real1 = 0;
    int imag1 = 0;
    int real2 = 0;
    int imag2 = 0;
    int realRes = 0;
    int imagRes = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case SUMA:
			{
                pedirNumeroComplejo("Ingrese el primer numero complejo", &real1, &imag1);
                pedirNumeroComplejo("Ingrese el segundo numero complejo", &real2, &imag2);
                sumar(real1, imag1, real2, imag2, &realRes, &imagRes);
                mostrarNumeroImaginario(realRes, imagRes);
			}break;

            case RESTA:
			{
                pedirNumeroComplejo("Ingrese el primer numero complejo", &real1, &imag1);
                pedirNumeroComplejo("Ingrese el segundo numero complejo", &real2, &imag2);
                restar(real1, imag1, real2, imag2, &realRes, &imagRes);
                mostrarNumeroImaginario(realRes, imagRes);
			}break;

            case MULTI:
			{
                pedirNumeroComplejo("Ingrese el primer numero complejo", &real1, &imag1);
                pedirNumeroComplejo("Ingrese el segundo numero complejo", &real2, &imag2);
                multiplicar(real1, imag1, real2, imag2, &realRes, &imagRes);
                mostrarNumeroImaginario(realRes, imagRes);
			}break;

            case SALIR:
			{
                printf("Saliendo del programa\n");
			}break;

            default:
                printf("Opcion no valida\n");
                break;
        }

    } while (opcion != SALIR);

    return 0;
}