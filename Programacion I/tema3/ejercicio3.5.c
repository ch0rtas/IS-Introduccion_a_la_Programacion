
#include <stdio.h>

int main() {
    float num1, num2, num3, num4;

    // Pedir al usuario que ingrese 4 números en coma flotante
    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    getchar();

    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);
    getchar();

    printf("Ingrese el tercer numero: ");
    scanf("%f", &num3);
    getchar();

    printf("Ingrese el cuarto numero: ");
    scanf("%f", &num4);
    getchar();

    // Verificar las condiciones y mostrar los resultados
    if (num1 > num2 && num1 > num3) {
        printf("El primer numero es mayor que el segundo y el tercero.\n");
    }

    if (num3 * num3 < num2 * num4 || num3 * 2 < num2) {
        printf("El cuadrado del tercero es menor que el segundo por el cuarto o el tercero por 2 es menor que el segundo.\n");
    }

    if ((int)num1 % (int)num4 > num3 && num1 > num4) {
        printf("El resto de la divisipn entre el primer numero y el cuarto es mayor que el tercero y el primer numero es mayor que el cuarto.\n");
    }

    if (num2 / num4 == num1) {
        printf("La division entre el segundo numero y el cuarto es igual al primer numero.\n");
    }

    return 0;
}
