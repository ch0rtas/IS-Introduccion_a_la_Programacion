/*
Autor: Manuel Martinez Ramón
Fecha: 2024.05.06
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar los datos de un alumno
typedef struct {
    char *nombre;
    char *apellido;
    int edad;
    char estado[20]; // Estado: guardado o sin guardar
} Alumno;

// Estructura para almacenar la lista de alumnos
typedef struct {
    Alumno *alumnos;
    int num_alumnos;
    int capacidad;
} ListaAlumnos;

// Prototipos de funciones
void listarAlumnos(ListaAlumnos *lista);
void agregarAlumno(ListaAlumnos *lista);
void guardarAlumnos(ListaAlumnos *lista);
void buscarAlumno(ListaAlumnos *lista, char *busqueda);

int main() {
    ListaAlumnos lista;
    lista.alumnos = NULL;
    lista.num_alumnos = 0;
    lista.capacidad = 0;

    FILE *archivo = fopen("alumnos.txt", "a+");
    if (archivo == NULL) {
        fprintf(stderr, "Error al abrir el archivo.\n");
        return 1;
    }

    char linea[100];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        char *nombre = strtok(linea, ",");
        char *apellido = strtok(NULL, ",");
        char *edad_str = strtok(NULL, ",");
        int edad = atoi(edad_str + 6); // Saltar "Edad: " y convertir a entero

        Alumno alumno = { strdup(nombre + 8), strdup(apellido + 11), edad, "guardado" };
        
        lista.num_alumnos++;
        lista.alumnos = realloc(lista.alumnos, lista.num_alumnos * sizeof(Alumno));
        lista.alumnos[lista.num_alumnos - 1] = alumno;
    }

    fclose(archivo);

    int opcion;
    char busqueda[100];
    do {
        printf("\nMenu:\n");
        printf("1. Listar alumnos\n");
        printf("2. Agregar alumno\n");
        printf("3. Guardar alumnos\n");
        printf("4. Buscar alumno\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer del teclado

        switch (opcion) {
            case 1:
                listarAlumnos(&lista);
                break;
            case 2:
                agregarAlumno(&lista);
                break;
            case 3:
                guardarAlumnos(&lista);
                break;
            case 4:
                printf("Ingrese el nombre o apellido del alumno a buscar: ");
                fgets(busqueda, sizeof(busqueda), stdin);
                busqueda[strcspn(busqueda, "\n")] = '\0'; // Eliminar el salto de línea
                buscarAlumno(&lista, busqueda);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intentelo de nuevo.\n");
        }
    } while (opcion != 5);

    // Liberar memoria
    for (int i = 0; i < lista.num_alumnos; i++) {
        free(lista.alumnos[i].nombre);
        free(lista.alumnos[i].apellido);
    }
    free(lista.alumnos);

    return 0;
}

void listarAlumnos(ListaAlumnos *lista) {
    printf("\nLista de Alumnos:\n");
    for (int i = 0; i < lista->num_alumnos; i++) {
        printf("Nombre: %s, Apellido: %s, Edad: %d, Estado: %s\n", lista->alumnos[i].nombre,
               lista->alumnos[i].apellido, lista->alumnos[i].edad, lista->alumnos[i].estado);
    }
}

void agregarAlumno(ListaAlumnos *lista) {
    printf("\nAgregar un nuevo alumno:\n");
    Alumno alumno;
    alumno.nombre = malloc(100);
    alumno.apellido = malloc(100);

    printf("Ingrese el nombre del alumno: ");
    fgets(alumno.nombre, 100, stdin);
    alumno.nombre[strcspn(alumno.nombre, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Ingrese el apellido del alumno: ");
    fgets(alumno.apellido, 100, stdin);
    alumno.apellido[strcspn(alumno.apellido, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Ingrese la edad del alumno: ");
    scanf("%d", &alumno.edad);
    getchar(); // Limpiar el buffer del teclado

    strcpy(alumno.estado, "sin guardar");

    lista->num_alumnos++;
    lista->alumnos = realloc(lista->alumnos, lista->num_alumnos * sizeof(Alumno));
    lista->alumnos[lista->num_alumnos - 1] = alumno;
}

void guardarAlumnos(ListaAlumnos *lista) {
    FILE *archivo = fopen("alumnos.txt", "w");
    if (archivo == NULL) {
        fprintf(stderr, "Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < lista->num_alumnos; i++) {
        fprintf(archivo, "Nombre: %s, Apellido: %s, Edad: %d\n", lista->alumnos[i].nombre,
                lista->alumnos[i].apellido, lista->alumnos[i].edad);
        strcpy(lista->alumnos[i].estado, "guardado");
    }

    fclose(archivo);
    printf("Los alumnos han sido guardados en el archivo.\n");
}

void buscarAlumno(ListaAlumnos *lista, char *busqueda) {
    printf("\nResultados de la busqueda para '%s':\n", busqueda);
    for (int i = 0; i < lista->num_alumnos; i++) {
        if (strstr(lista->alumnos[i].nombre, busqueda) != NULL || strstr(lista->alumnos[i].apellido, busqueda) != NULL) {
            printf("Nombre: %s, Apellido: %s, Edad: %d, Estado: %s\n", lista->alumnos[i].nombre,
                   lista->alumnos[i].apellido, lista->alumnos[i].edad, lista->alumnos[i].estado);
        }
    }
}
