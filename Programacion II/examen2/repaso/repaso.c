#include <stdio.h>

// Definición de la enumeración para los tipos de figura
enum TipoFigura {
    CIRCULO,
    CUADRADO
};

// Definición de la estructura para almacenar los datos de la figura
struct FiguraGeometrica {
    enum TipoFigura tipo;
    float medida; // Puede representar el radio o el lado, dependiendo del tipo de figura
};

// Prototipos de funciones
float calcularArea(struct FiguraGeometrica figura);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <circulo|cuadrado> <medida>\n", argv[0]);
        return 1;
    }

    // Convertir la medida de cadena a flotante
    float medida;
    sscanf(argv[2], "%f", &medida);

    // Determinar el tipo de figura
    enum TipoFigura tipoFigura;
    if (strcmp(argv[1], "circulo") == 0) {
        tipoFigura = CIRCULO;
    } else if (strcmp(argv[1], "cuadrado") == 0) {
        tipoFigura = CUADRADO;
    } else {
        printf("Figura no reconocida. Por favor, introduzca 'circulo' o 'cuadrado'.\n");
        return 1;
    }

    // Crear la estructura de la figura
    struct FiguraGeometrica figura = {tipoFigura, medida};

    // Calcular y mostrar el área de la figura
    float area = calcularArea(figura);
    printf("El área de la figura seleccionada es: %.2f\n", area);

    return 0;
}

// Función para calcular el área de la figura
float calcularArea(struct FiguraGeometrica figura) {
    switch (figura.tipo) {
        case CIRCULO:
            return 3.14159 * figura.medida * figura.medida;
        case CUADRADO:
            return figura.medida * figura.medida;
        default:
            return -1.0; // Valor negativo para indicar un error
    }
}
