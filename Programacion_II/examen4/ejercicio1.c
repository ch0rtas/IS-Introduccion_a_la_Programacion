/*
Autor: Manuel Martinez Ramón
Fecha: 2024.06.15
Curso: INSO 1 - Introducción Programación II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    STUDENT,
    NAME,
    AGE,
    GROUP,
    NONE
} TagType;

char* leeTextoAlumno(FILE* f) {
    char buffer[1024];
    char* texto = NULL;
    size_t len = 0;
    
    while (fgets(buffer, sizeof(buffer), f)) {
        char* endStudent = strstr(buffer, "</student>");
        size_t bufferLen = strlen(buffer);
        
        texto = realloc(texto, len + bufferLen + 1);
        strcpy(texto + len, buffer);
        len += bufferLen;

        if (endStudent) {
            break;
        }
    }

    return texto;
}

char* getValor(char* cadena, char* etiquetaApertura, char* etiquetaCierre) {
    char* inicio = strstr(cadena, etiquetaApertura);
    if (!inicio) return NULL;
    inicio += strlen(etiquetaApertura);

    char* fin = strstr(inicio, etiquetaCierre);
    if (!fin) return NULL;

    size_t len = fin - inicio;
    char* valor = malloc(len + 1);
    strncpy(valor, inicio, len);
    valor[len] = '\0';

    return valor;
}

TagType getTagType(const char* tag) {
    if (strcmp(tag, "student") == 0) return STUDENT;
    if (strcmp(tag, "name") == 0) return NAME;
    if (strcmp(tag, "age") == 0) return AGE;
    if (strcmp(tag, "group") == 0) return GROUP;
    return NONE;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <nombre_archivo_xml>\n", argv[0]);
        return 1;
    }

    FILE* archivo = fopen(argv[1], "r");
    if (!archivo) {
        perror("Error al abrir el archivo");
        return 1;
    }

    int totalEstudiantes = 0;
    int sumaEdades = 0;
    char* textoAlumno;

    while ((textoAlumno = leeTextoAlumno(archivo)) != NULL) {
        char* nombre = getValor(textoAlumno, "<name>", "</name>");
        char* edadStr = getValor(textoAlumno, "<age>", "</age>");
        char* grupo = getValor(textoAlumno, "<group>", "</group>");

        if (nombre && edadStr && grupo) {
            int edad = atoi(edadStr);
            sumaEdades += edad;
            totalEstudiantes++;
            printf("Estudiante %d:\n", totalEstudiantes);
            printf("  Nombre: %s\n", nombre);
            printf("  Edad: %d\n", edad);
            printf("  Grupo: %s\n", grupo);
        }

        free(textoAlumno);
        free(nombre);
        free(edadStr);
        free(grupo);
    }

    if (totalEstudiantes > 0) {
        printf("Edad media: %.2f\n", (float)sumaEdades / totalEstudiantes);
    } else {
        printf("No se encontraron estudiantes en el archivo.\n");
    }

    fclose(archivo);
    return 0;
}
