
#include <stdio.h>


void main()
{
	char opcion=' ';
	
	printf("\nMi primer printf en C :)\n");
	printf("Salto de linea con \\n \n\n");

	printf("Quieres seguir:\nY - si\nN - no\n");
	scanf("%c",&opcion);
	printf("Ha seleccionado %c\n",opcion);
	
}


// gcc documento.c - para compilar
// ./a.exe - para ejecutar

// not igual
// !n
