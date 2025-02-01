#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char words[10][11]; // Matriz para almacenar hasta 10 palabras de hasta 10 letras + 1 para el carácter nulo

    int wordCount = 0;

    while (1) {
        printf("Introduce entre 2 y 10 palabras separadas por coma, sin espacios:\n");
        fgets(input, sizeof(input), stdin);

        // Eliminar el carácter de nueva línea al final
        input[strcspn(input, "\n")] = '\0';

        // Contar las palabras y validar la longitud
        int i = 0;
        char *token = strtok(input, ",");
        while (token != NULL) {
            if (strlen(token) > 10) {
                printf("Error: Una palabra excede los 10 caracteres. Intentalo de nuevo.\n");
                break;
            }
            strcpy(words[i], token);
            i++;
            token = strtok(NULL, ",");
        }

        if (i < 2 || i > 10) {
            printf("Error: Deben introducirse entre 2 y 10 palabras. Intentalo de nuevo.\n");
        } else if (i >= 2 && i <= 10) {
            wordCount = i;
            break;
        }
    }

    printf("\nPalabras en orden inverso:\n");

    for (int i = wordCount - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) {
            printf(",");
        }
    }

    return 0;
}
