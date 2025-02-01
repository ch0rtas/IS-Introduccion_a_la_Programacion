#include <stdio.h>

int main() {
    double precio, dinero_cliente;
    
    // Solicitar el precio del producto y el dinero introducido por el cliente
    printf("Precio del producto: ");
    scanf("%lf", &precio);
    
    printf("Dinero introducido por el cliente (maximo 50 euros): ");
    scanf("%lf", &dinero_cliente);
    
    // Verificar que la cantidad introducida no sea mayor de 50 euros
    if (dinero_cliente > 50.0) {
        printf("La cantidad introducida no puede ser mayor de 50 euros.\n");
        return 1;
    }
    
    // Calcular la vuelta
    double vuelta = dinero_cliente - precio;
    
    // Definir los valores de los billetes y monedas disponibles
    double billetes[] = {20, 10, 5};
    double monedas[] = {2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
    
    // Calcular la vuelta en billetes y monedas
    int num_billetes[3];
    int num_monedas[8];
    
    for (int i = 0; i < 3; i++) {
        num_billetes[i] = vuelta / billetes[i];
        vuelta -= num_billetes[i] * billetes[i];
    }
    
    for (int i = 0; i < 8; i++) {
        num_monedas[i] = vuelta / monedas[i];
        vuelta -= num_monedas[i] * monedas[i];
    }
    
    // Imprimir la cantidad de billetes y monedas a devolver
    printf("\nVuelta a devolver:\n");
    for (int i = 0; i < 3; i++) {
        if (num_billetes[i] > 0) {
            printf("%d billete(s) de %d euros\n", num_billetes[i], (int)billetes[i]);
        }
    }
    for (int i = 0; i < 8; i++) {
        if (num_monedas[i] > 0) {
            printf("%d moneda(s) de %.2f euros\n", num_monedas[i], monedas[i]);
        }
    }
    
    return 0;
}
