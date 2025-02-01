
#include <stdio.h>

// crea un menú en el que al seleccionar Y o y se meustre "OK", en caso de presionar otra letra se mostrará "KO"

int main()
{
	char opcion;
	
	// Solicita al usuario que ingrese un valor
	printf("\nSelecciona una opcion:\nY o y ---------------- Mostrar: OK\nCualquier otra letra - Mostrar: KO\n");
	scanf("%c", &opcion);
	
	// Verifica el valor ingresado y muestra el resultado correspondiente
	if (opcion == 'y' || opcion == 'Y') {
		printf("\nOK\n");
	} else {
		printf("\nKO\n");
	}
		
}
