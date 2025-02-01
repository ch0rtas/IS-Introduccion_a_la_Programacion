#include <stdio.h>

#define MAX_SIZE 100

void copiarArray(int *origen, int *destino, int size) {
    // Utilizamos un bucle para copiar cada elemento del array
    for (int i = 0; i < size; i++) {
        *(destino + i) = *(origen + i);
    }
}

int main() {
    int arrayOriginal[MAX_SIZE];
    int arrayDestino[MAX_SIZE];

    int size;

    // Solicitar al usuario el tamaño del array
    printf("Ingrese el tamaño del array (no debe exceder %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Verificar que el tamaño sea válido
    if (size <= 0 || size > MAX_SIZE) {
        printf("Tamaño no válido. Debe ser mayor que 0 y no exceder %d.\n", MAX_SIZE);
        return 1;  // Salir con código de error
    }

    // Solicitar al usuario los elementos del array original
    printf("Ingrese los elementos del array original:\n");
    for (int i = 0; i < size; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arrayOriginal[i]);
    }

    // Llamar a la función para copiar el array
    copiarArray(arrayOriginal, arrayDestino, size);

    // Imprimir el array destino (copia)
    printf("\nArray copiado:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arrayDestino[i]);
    }

    return 0;  // Salir con éxito
}
