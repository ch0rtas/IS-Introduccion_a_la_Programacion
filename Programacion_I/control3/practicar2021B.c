#include <stdio.h>
#include <ctype.h>

// Prototipos de funciones
void leerFrase(char frase[], int maxCaracteres);
void calcularEstadisticas(const char frase[], int *numCaracteres, int *numVocales, int *numConsonantes, int *numPalabras);
int verificarCondiciones(const char frase[]);

int main() {
    char frase[201];
    int numCaracteres, numVocales, numConsonantes, numPalabras;

    // Leer la frase
    leerFrase(frase, 200);

    // Verificar las condiciones de la frase
    if (verificarCondiciones(frase) == 1) {
        printf("Error en la frase.\n");
        return 1;  // Salir del programa con código de error
    }

    // Calcular estadísticas
    calcularEstadisticas(frase, &numCaracteres, &numVocales, &numConsonantes, &numPalabras);

    // Mostrar estadísticas al usuario
    printf("\nEstadísticas de la frase:\n");
    printf("Número total de caracteres (incluyendo espacios): %d\n", numCaracteres);
    printf("Número de vocales: %d\n", numVocales);
    printf("Número de consonantes: %d\n", numConsonantes);
    printf("Número de palabras: %d\n", numPalabras);

    return 0;
}

// Función para leer la frase
void leerFrase(char frase[], int maxCaracteres) {
    printf("Ingrese una frase (máximo %d caracteres, solo minúsculas y espacios):\n", maxCaracteres);
    
    int i = 0;
    char c;

    while ((c = getchar()) != '\n' && i < maxCaracteres) {
        frase[i++] = c;
    }

    frase[i] = '\0';  // Agregar el carácter nulo al final de la cadena
}

// Función para verificar las condiciones de la frase
int verificarCondiciones(const char frase[]) {
    for (int i = 0; frase[i] != '\0'; i++) {
        if (!islower(frase[i]) && frase[i] != ' ') {
            printf("Error: La frase solo debe contener letras minúsculas y espacios.\n");
            return 1;  // Salir con código de error
        }
    }
    return 0;  // Éxito
}

// Función para calcular estadísticas
void calcularEstadisticas(const char frase[], int *numCaracteres, int *numVocales, int *numConsonantes, int *numPalabras) {
    *numCaracteres = *numVocales = *numConsonantes = *numPalabras = 0;

    for (int i = 0; frase[i] != '\0'; i++) {
        (*numCaracteres)++;

        if (frase[i] == ' ') {
            (*numPalabras)++;
        } else if (islower(frase[i])) {
            if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u') {
                (*numVocales)++;
            } else {
                (*numConsonantes)++;
            }
        }
    }

    // Añadir la última palabra
    (*numPalabras)++;
}
