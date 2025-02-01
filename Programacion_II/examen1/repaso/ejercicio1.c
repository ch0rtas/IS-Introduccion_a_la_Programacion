/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.29
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 40

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <caracter1> <caracter2> ... <caracterN>\n", argv[0]);
        return 1;
    }

    int num_caracteres = argc - 1; // Número de caracteres introducidos
    char caracteres[MAX_TEXT_LENGTH];
    int contador[MAX_TEXT_LENGTH] = {0};
    char texto[MAX_TEXT_LENGTH];
    int i, j, opcion;

    // Obtener caracteres de la línea de comandos
    for (i = 1; i < argc && i <= MAX_TEXT_LENGTH; i++) {
        caracteres[i-1] = argv[i][0];
    }

    do {
        printf("\nMenu:\n");
        printf("1. Introducir nuevo texto\n");
        printf("2. Mostrar resultado\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese el nuevo texto (maximo %d caracteres): ", MAX_TEXT_LENGTH);
                scanf(" %[^\n]", texto);

                // Contar los caracteres
                for (i = 0; i < strlen(texto); i++) {
                    for (j = 0; j < num_caracteres; j++) {
                        if (texto[i] == caracteres[j]) {
                            contador[j]++;
                            break;
                        }
                    }
                }
                break;
            case 2:
                printf("Resultado:\n");
                for (i = 0; i < num_caracteres; i++) {
                    printf("El caracter '%c' se repite %d veces.\n", caracteres[i], contador[i]);
                }
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 3);

    return 0;
}
