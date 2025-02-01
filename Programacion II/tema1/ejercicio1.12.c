/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.20
Curso: INSO 1 - Introducción Programación II

Implementar en el ejercicio 1.9 un Menu
Tendrá 4 opciones:
    1) Incluir libro
    2) Buscar libro (nombre autor)
    3) Listar todos los libros de la biblioteca
    4) Salir
*/

#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 100 // Máximo de libros que se pueden almacenar
#define MAX_TITULO 100 // Longitud máxima del título del libro
#define MAX_AUTOR_NOMBRE 50 // Longitud máxima del nombre del autor
#define MAX_AUTOR_APELLIDO 50 // Longitud máxima del apellido del autor
#define MAX_AUTOR_NACIONALIDAD 50 // Longitud máxima de la nacionalidad del autor
#define MAX_EDITORIAL 50 // Longitud máxima del nombre de la editorial

struct Autor {
    char nombre[MAX_AUTOR_NOMBRE];
    char apellido[MAX_AUTOR_APELLIDO];
    char nacionalidad[MAX_AUTOR_NACIONALIDAD];
};

struct Libro {
    char titulo[MAX_TITULO];
    long long int ISBN;
    int numeroPaginas;
    char editorial[MAX_EDITORIAL];
    struct Autor autor;
};

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void incluirLibro(struct Libro biblioteca[], int *numLibros) {
    if (*numLibros < MAX_LIBROS) {
        struct Autor autor1;
        printf("Ingrese el nombre del autor: ");
        scanf("%s", autor1.nombre);
        limpiarBuffer();

        printf("Ingrese el apellido del autor: ");
        scanf("%s", autor1.apellido);
        limpiarBuffer();

        printf("Ingrese la nacionalidad del autor: ");
        scanf("%s", autor1.nacionalidad);
        limpiarBuffer();

        printf("Ingrese el titulo del libro: ");
        scanf("%s", biblioteca[*numLibros].titulo);
        limpiarBuffer();

        printf("Ingrese el ISBN del libro: ");
        scanf("%lld", &biblioteca[*numLibros].ISBN);
        limpiarBuffer();

        printf("Ingrese el numero de paginas del libro: ");
        scanf("%d", &biblioteca[*numLibros].numeroPaginas);
        limpiarBuffer();

        printf("Ingrese la editorial del libro: ");
        scanf("%s", biblioteca[*numLibros].editorial);
        limpiarBuffer();

        biblioteca[*numLibros].autor = autor1;

        (*numLibros)++;
        printf("Libro incluido correctamente.\n");
    } else {
        printf("No se pueden incluir más libros, la biblioteca está llena.\n");
    }
}

void buscarLibros(struct Libro biblioteca[], int numLibros) {
    if (numLibros > 0) {
        char nombreAutor[MAX_AUTOR_NOMBRE];
        printf("Ingrese el nombre del autor para buscar sus libros: ");
        scanf("%s", nombreAutor);
        limpiarBuffer();

        int encontrados = 0;
        printf("Libros del autor %s:\n", nombreAutor);
        for (int i = 0; i < numLibros; i++) {
            if (strcmp(biblioteca[i].autor.nombre, nombreAutor) == 0) {
                printf("- %s\n", biblioteca[i].titulo);
                encontrados++;
            }
        }
        if (encontrados == 0) {
            printf("No se encontraron libros del autor %s.\n", nombreAutor);
        }
    } else {
        printf("No hay libros guardados en la biblioteca.\n");
    }
}

void listarLibros(struct Libro biblioteca[], int numLibros) {
    if (numLibros > 0) {
        printf("Lista de libros en la biblioteca:\n");
        for (int i = 0; i < numLibros; i++) {
            printf("%d. %s\n", i+1, biblioteca[i].titulo);
        }
    } else {
        printf("No hay libros guardados en la biblioteca.\n");
    }
}

int main() {
    struct Libro biblioteca[MAX_LIBROS]; // Arreglo para almacenar libros
    int numLibros = 0; // Contador de libros almacenados
    int opcion; // Variable para almacenar la opción del usuario

    do {
        printf("\nMenu:\n");
        printf("1. Incluir libro\n");
        printf("2. Buscar libros por autor\n");
        printf("3. Listar todos los libros de la biblioteca\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                incluirLibro(biblioteca, &numLibros);
                break;
            case 2:
                buscarLibros(biblioteca, numLibros);
                break;
            case 3:
                listarLibros(biblioteca, numLibros);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 4);

    return 0;
}










