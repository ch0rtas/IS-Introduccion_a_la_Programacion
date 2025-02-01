#include <stdio.h>

int main() {
    float x1, y1, x2, y2;
    
    // Solicitar las componentes del primer vector
    printf("Introduce las componentes del primer vector (x1 y1): ");
    scanf("%f %f", &x1, &y1);

    // Solicitar las componentes del segundo vector
    printf("Introduce las componentes del segundo vector (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    // Verificar si los vectores son similares
    float division_x = x1 / x2;
    float division_y = y1 / y2;

    if (x2 == 0 || y2 == 0) {
        printf("El segundo vector no puede tener componentes iguales a cero.\n");
    } else if (fabs(division_x - division_y) < 0.01) { // Sirve para sacar el valor absoluto
        printf("Los vectores son similares.\n");
    } else {
        printf("Los vectores no son similares.\n");
    }

    return 0;
}
