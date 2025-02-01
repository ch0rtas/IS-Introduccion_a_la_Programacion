#include <stdio.h>

// Prototipos de funciones
int calcularTamanioCadena(char cadena[]);
int compararCadenas(char cadena1[], char cadena2[]);
void leerCadena(char cadena[], int maxSize);

/*
Declaramos las variables/bloques que vamos a utilizar al principio de todo para poder llamarlas
desde el main estando estas por debajo del main.
En el main recogemos los datos del usuario y vamos mostyrando por pantalla los calculos conforme
se van ejecutando (en instantáneo).
Con "calcularTamanioCadena" simplemente vamos recorriendo la cadena de caracteres hasta encontrar
el final "\0". Realizamos un contador para así determinar los caracteres totáles.
En "compararCadenas" se va haciendo un seguimiento el cual gracias a un bucle se comprueba que
los caracteres que se encuentran en la misma posicion si son iguales o no.
Por último "leerCadena" lo utilizamos para recorrer los datos introducidos por el usuario y comporbar
que el nombre introducido es como mucho de 14 caracteres y agregamos al final el cartacter nulo.
*/

int main() {
    char nombre1[15]; // 14 caracteres + 1 para el carácter nulo '\0'
    char nombre2[15];

    // Leer nombres de los alumnos
    printf("Ingrese el nombre del primer alumno (max 14 caracteres): ");
    leerCadena(nombre1, 14);

    printf("Ingrese el nombre del segundo alumno (max 14 caracteres): ");
    leerCadena(nombre2, 14);

    // Comparar los nombres
    if (compararCadenas(nombre1, nombre2) == 1) {
        printf("Los nombres son iguales.\n");
    } else {
        printf("Los nombres son diferentes.\n");
    }

    // Calcular y mostrar el tamaño de cada nombre
    printf("Tamanio del primer nombre: %d\n", calcularTamanioCadena(nombre1));
    printf("Tamanio del segundo nombre: %d\n", calcularTamanioCadena(nombre2));

    return 0;
}

// Implementación de funciones

int calcularTamanioCadena(char cadena[]) {
    int tamano = 0;
    while (cadena[tamano] != '\0') {
        tamano++;
    }
    return tamano;
}

int compararCadenas(char cadena1[], char cadena2[]) {
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return 0; // Las cadenas son diferentes
        }
        i++;
    }
    // Ambas cadenas son iguales si se llega hasta aquí
    return 1;
}

void leerCadena(char cadena[], int maxSize) {
    char c;
    int i = 0;

    // Leer caracteres hasta que se alcance el tamaño máximo o se presione Enter
    while ((c = getchar()) != '\n' && i < maxSize) {
        cadena[i++] = c;
    }

    // Agregar el carácter nulo al final de la cadena
    cadena[i] = '\0';
}
