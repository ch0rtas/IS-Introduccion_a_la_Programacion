#include <stdio.h>

/*
Gracias a "leeLinea" utilizamos dicha función para leer la linea que el usuario a introducido,
en este caso esperamos que sea una dirrección de email, que más adelante comprobaremos.
Seguidamente en un simple main lo utilizamos para recoger la linea de información y mostrar
si la dirección es válida o no con la función que nombramos al principio del programa
"ComprobarEmail".
En "ComprobarEmail" miramos que delante del primer @ haya un punto, como se especifica en el
ejercicio ya que los emails son así.
Una vez hecho esto, si del caso de que hasta este punto todo estuviera bien, se comprueba que
despues del @, caracter por caracter, coincide con "live.u-tad.com" y por último el final.
*/

// Prototipo de la función
int ComprobarEmail(char miemail[]);

// Función para leer una línea desde la consola
void leeLinea(char linea[], int tamMax) {
    int i = 0;
    char caracter;

    // Leer caracteres hasta llegar al tamaño máximo o encontrar un salto de línea
    while ((caracter = getchar()) != '\n' && i < tamMax - 1) {
        linea[i] = caracter;
        i++;
    }

    // Asegurar que la cadena termine con '\0'
    linea[i] = '\0';
}

int main() {
    // Declaración de variables
    char direccionCorreo[50];

    // Pedir al usuario que ingrese una dirección de correo
    printf("Ingrese una direccion de correo u-tad: ");
    leeLinea(direccionCorreo, 50);

    // Comprobar si la dirección de correo es válida
    if (ComprobarEmail(direccionCorreo)) {
        printf("La direccion de correo SI es valida.\n");
    } else {
        printf("La direccion de correo NO es valida.\n");
    }

    return 0;
}

// Implementación de la función ComprobarEmail
int ComprobarEmail(char miemail[]) {
    int i = 0;
    int puntoEncontrado = 0;
    int arrobaEncontrado = 0;

    // Buscar un carácter '.' antes del carácter '@' (más allá de la posición 2)
    while (miemail[i] != '\0') {
        if (miemail[i] == '.' && i > 2) {
            puntoEncontrado = 1;
        }
        if (miemail[i] == '@' && i > 5) {
            arrobaEncontrado = 1;
            break;  // No necesitamos seguir buscando después del primer arroba
        }
        i++;
    }

    // Verificar las condiciones
    if (puntoEncontrado && arrobaEncontrado && (miemail[i] == '@') && (miemail[i + 1] == 'l') &&
        (miemail[i + 2] == 'i') && (miemail[i + 3] == 'v') && (miemail[i + 4] == 'e') &&
        (miemail[i + 5] == '.') && (miemail[i + 6] == 'u') && (miemail[i + 7] == '-') &&
        (miemail[i + 8] == 't') && (miemail[i + 9] == 'a') && (miemail[i + 10] == 'd') &&
        (miemail[i + 11] == '.') && (miemail[i + 12] == 'c') && (miemail[i + 13] == 'o') &&
        (miemail[i + 14] == 'm') && (miemail[i + 15] == '\0')) {
        return 1;  // La dirección de correo es válida
    } else {
        return 0;  // La dirección de correo no es válida
    }
}
