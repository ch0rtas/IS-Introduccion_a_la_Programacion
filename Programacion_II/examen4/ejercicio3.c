/*
Autor: Manuel Martinez Ramón
Fecha: 2024.06.22
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *marca;
    char *modelo;
    int año;
    int kilometros;
    float precio;
} coche_t;

typedef struct {
    coche_t *coches;
    int tam;
} listaCoches_t;

typedef struct {
    char **lineas;
    int numLineas;
} lineas_t;

// Función para leer una línea de la entrada estándar
char *leelinea() {
    char *linea = NULL;
    char c;
    size_t len = 0;
    size_t capacity = 1;

    linea = malloc(sizeof(char) * capacity);

    if (!linea) {
        return NULL;
    }

    while ((c = getchar()) != '\n' && c != EOF) {
        if (len + 1 >= capacity) {
            capacity *= 2;
            linea = realloc(linea, sizeof(char) * capacity);
            if (!linea) {
                return NULL;
            }
        }
        linea[len++] = c;
    }

    linea[len] = '\0';
    return linea;
}

// Función para leer una línea de un fichero
char *leelineaDinamicaFichero(FILE *fd) {
    char *linea = NULL;
    char c;
    size_t len = 0;
    size_t capacity = 1;

    linea = malloc(sizeof(char) * capacity);

    if (!linea) {
        return NULL;
    }

    while ((c = fgetc(fd)) != '\n' && c != EOF) {
        if (len + 1 >= capacity) {
            capacity *= 2;
            linea = realloc(linea, sizeof(char) * capacity);
            if (!linea) {
                return NULL;
            }
        }
        linea[len++] = c;
    }

    if (len == 0 && c == EOF) {
        free(linea);
        return NULL;
    }

    linea[len] = '\0';
    return linea;
}

// Función para leer todas las líneas de un fichero
lineas_t leelineasFichero(FILE *fichDesc) {
    lineas_t lineas;
    lineas.numLineas = 0;
    lineas.lineas = NULL;
    char *linea;

    while ((linea = leelineaDinamicaFichero(fichDesc)) != NULL) {
        lineas.lineas = realloc(lineas.lineas, sizeof(char *) * (lineas.numLineas + 1));
        lineas.lineas[lineas.numLineas++] = linea;
    }

    return lineas;
}

// Función para pedir los datos de un coche al usuario
coche_t pedirCoche() {
    coche_t coche;
    coche.marca = (char *)malloc(50);
    coche.modelo = (char *)malloc(50);

    printf("Introduce la marca del coche: ");
    coche.marca = leelinea();

    printf("Introduce el modelo del coche: ");
    coche.modelo = leelinea();

    printf("Introduce el anio de matriculacion: ");
    scanf("%d", &coche.año);

    printf("Introduce los kilometros del coche: ");
    scanf("%d", &coche.kilometros);

    printf("Introduce el precio del coche: ");
    scanf("%f", &coche.precio);

    getchar(); // Limpiar el buffer del salto de línea

    // Generar un identificador único
    int maxID = 0;
    FILE *masterFile = fopen("master_vehiculos.txt", "r");
    FILE *soldFile = fopen("vehiculos_vendidos.txt", "r");
    lineas_t lineas;

    if (masterFile) {
        lineas = leelineasFichero(masterFile);
        for (int i = 0; i < lineas.numLineas; i++) {
            int id;
            sscanf(lineas.lineas[i], "%d;", &id);
            if (id > maxID) maxID = id;
            free(lineas.lineas[i]);
        }
        free(lineas.lineas);
        fclose(masterFile);
    }

    if (soldFile) {
        lineas = leelineasFichero(soldFile);
        for (int i = 0; i < lineas.numLineas; i++) {
            int id;
            sscanf(lineas.lineas[i], "%d;", &id);
            if (id > maxID) maxID = id;
            free(lineas.lineas[i]);
        }
        free(lineas.lineas);
        fclose(soldFile);
    }

    coche.id = maxID + 1;

    return coche;
}

// Función para guardar un coche en el fichero master
void guardarCocheEnMaster(coche_t coche) {
    FILE *masterFile = fopen("master_vehiculos.txt", "a");
    if (masterFile) {
        fprintf(masterFile, "%d;%s;%s;%d;%d;%.2f\n", coche.id, coche.marca, coche.modelo, coche.año, coche.kilometros, coche.precio);
        fclose(masterFile);
    }
}

// Función para mostrar los coches ordenados por precio
void mostrarVehiculos(listaCoches_t coches) {
    // Ordenar los coches por precio usando bubble sort
    for (int i = 0; i < coches.tam - 1; i++) {
        for (int j = 0; j < coches.tam - i - 1; j++) {
            if (coches.coches[j].precio > coches.coches[j + 1].precio) {
                coche_t temp = coches.coches[j];
                coches.coches[j] = coches.coches[j + 1];
                coches.coches[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < coches.tam; i++) {
        printf("ID: %d, Marca: %s, Modelo: %s, Año: %d, Kilómetros: %d, Precio: %.2f\n",
               coches.coches[i].id, coches.coches[i].marca, coches.coches[i].modelo, coches.coches[i].año, coches.coches[i].kilometros, coches.coches[i].precio);
    }
}

// Función para comprar un vehículo
void comprarVehiculos() {
    FILE *masterFile = fopen("master_vehiculos.txt", "r");
    FILE *soldFile = fopen("vehiculos_vendidos.txt", "a");
    if (!masterFile || !soldFile) {
        if (masterFile) fclose(masterFile);
        if (soldFile) fclose(soldFile);
        printf("Error al abrir los ficheros.\n");
        return;
    }

    lineas_t lineas = leelineasFichero(masterFile);
    listaCoches_t lista;
    lista.coches = malloc(lineas.numLineas * sizeof(coche_t));
    lista.tam = lineas.numLineas;

    for (int i = 0; i < lineas.numLineas; i++) {
        coche_t coche;
        coche.marca = malloc(50);
        coche.modelo = malloc(50);
        sscanf(lineas.lineas[i], "%d;%49[^;];%49[^;];%d;%d;%f", &coche.id, coche.marca, coche.modelo, &coche.año, &coche.kilometros, &coche.precio);
        lista.coches[i] = coche;
        free(lineas.lineas[i]);
    }
    free(lineas.lineas);
    fclose(masterFile);

    mostrarVehiculos(lista);

    printf("Introduce el ID del coche que deseas comprar: ");
    int idCompra;
    scanf("%d", &idCompra);

    masterFile = fopen("master_vehiculos.txt", "w");
    for (int i = 0; i < lista.tam; i++) {
        if (lista.coches[i].id == idCompra) {
            fprintf(soldFile, "%d;%s;%s;%d;%d;%.2f\n", lista.coches[i].id, lista.coches[i].marca, lista.coches[i].modelo, lista.coches[i].año, lista.coches[i].kilometros, lista.coches[i].precio);
        } else {
            fprintf(masterFile, "%d;%s;%s;%d;%d;%.2f\n", lista.coches[i].id, lista.coches[i].marca, lista.coches[i].modelo, lista.coches[i].año, lista.coches[i].kilometros, lista.coches[i].precio);
        }
        free(lista.coches[i].marca);
        free(lista.coches[i].modelo);
    }
    free(lista.coches);

    fclose(masterFile);
    fclose(soldFile);
}

int main() {
    int opcion;

    do {
        printf("\nMenu:\n");
        printf("1.- Introducir vehículo\n");
        printf("2.- Presentar vehiculos por precio ascendente\n");
        printf("3.- Comprar vehículo\n");
        printf("4.- Salir\n");
        printf("Introduce una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer del salto de línea

        switch (opcion) {
            case 1: {
                coche_t coche = pedirCoche();
                guardarCocheEnMaster(coche);
                free(coche.marca);
                free(coche.modelo);
                break;
            }
            case 2: {
                FILE *masterFile = fopen("master_vehiculos.txt", "r");
                if (!masterFile) {
                    printf("No se pudo abrir el fichero master_vehiculos.txt\n");
                    break;
                }

                lineas_t lineas = leelineasFichero(masterFile);
                fclose(masterFile);

                listaCoches_t lista;
                lista.coches = malloc(lineas.numLineas * sizeof(coche_t));
                lista.tam = lineas.numLineas;

                for (int i = 0; i < lineas.numLineas; i++) {
                    coche_t coche;
                    coche.marca = malloc(50);
                    coche.modelo = malloc(50);
                    sscanf(lineas.lineas[i], "%d;%49[^;];%49[^;];%d;%d;%f", &coche.id, coche.marca, coche.modelo, &coche.año, &coche.kilometros, &coche.precio);
                    lista.coches[i] = coche;
                    free(lineas.lineas[i]);
                }
                free(lineas.lineas);

                printf("Introduce la marca del coche que deseas buscar: ");
                char *marca = leelinea();
                printf("Introduce el modelo del coche que deseas buscar: ");
                char *modelo = leelinea();

                listaCoches_t filtro;
                filtro.coches = malloc(lista.tam * sizeof(coche_t));
                filtro.tam = 0;

                for (int i = 0; i < lista.tam; i++) {
                    if (strcmp(lista.coches[i].marca, marca) == 0 && strcmp(lista.coches[i].modelo, modelo) == 0) {
                        filtro.coches[filtro.tam++] = lista.coches[i];
                    } else {
                        free(lista.coches[i].marca);
                        free(lista.coches[i].modelo);
                    }
                }
                free(lista.coches);

                mostrarVehiculos(filtro);

                free(filtro.coches);
                free(marca);
                free(modelo);

                break;
            }
            case 3: {
                comprarVehiculos();
                break;
            }
            case 4: {
                printf("Saliendo del programa...\n");
                break;
            }
            default: {
                printf("Opcion no valida. Intentalo de nuevo.\n");
                break;
            }
        }
    } while (opcion != 4);

    return 0;
}

