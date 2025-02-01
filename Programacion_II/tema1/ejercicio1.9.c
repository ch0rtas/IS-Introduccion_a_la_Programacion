/*
Autor: Manuel Martinez Ramón
Fecha: 2024.02.13
Curso: INSO 1 - Introducción Programación II

Utiliza struct
Alamcenar datos de libros y relacionarlos con sus autores.
Autor: Nombre, Apellido, Nacionalidad
Libro: Titulo, ISBN, NumeroPag, Editorial, Autor
*/

#include <stdio.h>
#include <string.h>

struct Autor {
    char nombre[50];
    char apellido[50];
    char nacionalidad[50];
};

struct Libro {
    char titulo[100];
    long long int ISBN;
    int numeroPaginas;
    char editorial[50];
    struct Autor autor;
};

int main() {
    
    struct Autor autor1 = {"Gabriel", "Garcia Marquez", "Colombiano"};

    struct Libro libro1 = {"Cien anios de soledad", 9780307350355, 432, "Sudamericana", autor1};

    printf("Libro: %s\n", libro1.titulo);
    printf("ISBN: %i\n", libro1.ISBN);
    printf("Numero de paginas: %i\n", libro1.numeroPaginas);
    printf("Editorial: %s\n", libro1.editorial);
    printf("Autor: %s %s, %s\n", libro1.autor.nombre, libro1.autor.apellido, libro1.autor.nacionalidad);

    return 0;
}






