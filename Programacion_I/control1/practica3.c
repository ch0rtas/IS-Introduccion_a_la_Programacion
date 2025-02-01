#include <stdio.h>

int main() {
    int r1, g1, b1, r2, g2, b2;

    // Introducir las componentes del primer color y verificar el rango
    printf("Introduce el componente rojo del primer color (0...255): ");
    scanf("%d", &r1);
    if (r1 < 0 || r1 > 255) {
        printf("El valor de la componente roja del primer color esta fuera del rango.\n");
        return 1;
    }

    printf("Introduce el componente verde del primer color (0...255): ");
    scanf("%d", &g1);
    if (g1 < 0 || g1 > 255) {
        printf("El valor de la componente verde del primer color esta fuera del rango.\n");
        return 1;
    }

    printf("Introduce el componente azul del primer color (0...255): ");
    scanf("%d", &b1);
    if (b1 < 0 || b1 > 255) {
        printf("El valor de la componente azul del primer color esta fuera del rango.\n");
        return 1;
    }

    // Introducir las componentes del segundo color y verificar el rango
    printf("Introduce el componente rojo del segundo color (0...255): ");
    scanf("%d", &r2);
    if (r2 < 0 || r2 > 255) {
        printf("El valor de la componente roja del segundo color esta fuera del rango.\n");
        return 1;
    }

    printf("Introduce el componente verde del segundo color (0...255): ");
    scanf("%d", &g2);
    if (g2 < 0 || g2 > 255) {
        printf("El valor de la componente verde del segundo color esta fuera del rango.\n");
        return 1;
    }

    printf("Introduce el componente azul del segundo color (0...255): ");
    scanf("%d", &b2);
    if (b2 < 0 || b2 > 255) {
        printf("El valor de la componente azul del segundo color esta fuera del rango.\n");
        return 1;
    }

    // Convertir a código hexadecimal
    printf("El color %dR, %dG, %dB en hexadecimal es: #%02X%02X%02X\n", r1, g1, b1, r1, g1, b1);
    printf("El color %dR, %dG, %dB en hexadecimal es: #%02X%02X%02X\n", r2, g2, b2, r2, g2, b2);

    // Calcular la "brillantez" de los colores
    double brillantez1 = 0.2126 * r1 + 0.7152 * g1 + 0.0722 * b1;
    double brillantez2 = 0.2126 * r2 + 0.7152 * g2 + 0.0722 * b2;

    if (brillantez1 > brillantez2) {
        printf("El color mas brillante es el primero\n");
    } else if (brillantez2 > brillantez1) {
        printf("El color mas brillante es el segundo\n");
    } else {
        printf("Ambos colores tienen la misma brillantez\n");
    }

    return 0;
}
