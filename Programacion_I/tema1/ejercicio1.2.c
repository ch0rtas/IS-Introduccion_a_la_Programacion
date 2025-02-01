
#include <stdio.h>


void main()
{

    char opcion=' ';

    // Solicita al usuario que ingrese un valor
    printf("Pulsa 'y' para imprimir 'OK', cualquier otra letra para imprimir 'KO'\n");
	scanf("%c",&opcion);

    // Verifica el valor ingresado y muestra el resultado correspondiente
    int comparacion=(opcion=='y');
	    if (comparacion == 0){
		    printf("KO\n");
	    } else {
		    printf("OK\n");
	    }

}
