#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    printf("Introduce los coeficientes a, b y c del polinomio (a*x^2 + b*x + c = 0):\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Calcula el discriminante
    double discriminante = b * b - 4 * a * c;

    // Comprueba si el discriminante es positivo, negativo o igual a cero
    if (discriminante > 0) {
        // Dos raíces reales distintas
        double raiz1 = (-b + sqrt(discriminante)) / (2 * a);
        double raiz2 = (-b - sqrt(discriminante)) / (2 * a);
        printf("Las raices son: %.2lf y %.2lf\n", raiz1, raiz2);
    } else if (discriminante == 0) {
        // Una única raíz real
        double raiz = -b / (2 * a);
        printf("La raíz es: %.2lf\n", raiz);
    } else {
        // Raíces imaginarias
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-discriminante) / (2 * a);
        printf("Las raices son numeros complejos:\n");
        printf("Raiz 1: %.2lf + %.2lfi\n", realPart, imagPart);
        printf("Raiz 2: %.2lf - %.2lfi\n", realPart, imagPart);
    }

    return 0;
}
