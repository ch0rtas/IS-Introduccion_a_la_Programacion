#include <stdio.h>

int main() {
    float base, altura, area, area2;

    // Pedir al usuario la base del triángulo
    printf("Ingrese la longitud de la base del triangulo: ");
    scanf(" %f", &base);
    getchar(); // leer el intro y así no provoca errores más adelante ya que es un carácter

    // Pedir al usuario la altura del triángulo
    printf("Ingrese la altura del triangulo: ");
    scanf(" %f", &altura);
    getchar();

    // Calcular el área del triángulo (Área = 0.5 * base * altura)
    area = 0.5 * base * altura;
    area2 = (base * altura) / 2.0;

    // Mostrar el resultado
    printf("El area del triangulo es: %f\n", area);

    return 0;
}