#include <stdio.h>

int main() {
    char tipo_cliente;
    double monto_compra, importe_total, importe_descuento, importe_iva, importe_definitivo, donacion;

    // Solicitar el tipo de cliente (VIP o Normal) y el monto de la compra
    printf("Tipo de cliente [VIP (V/v) o Normal (N/n)]: ");
    scanf(" %c", &tipo_cliente);
    
    // Verificar si el tipo de cliente es válido
    if (tipo_cliente != 'V' && tipo_cliente != 'v' && tipo_cliente != 'N' && tipo_cliente != 'n') {
        printf("Tipo de cliente no valido.\n");
        return 1;
    }

    printf("Monto de la compra: ");
    scanf("%lf", &monto_compra);

    // Calcular el importe total sin descuento
    importe_total = monto_compra;

    // Calcular el descuento y aplicar el IVA
    if ((tipo_cliente == 'V' || tipo_cliente == 'v') && monto_compra >= 100.0) { // Cliente VIP con compra >= 100€
        importe_descuento = monto_compra * 0.20;
    } else if ((tipo_cliente == 'V' || tipo_cliente == 'v') && monto_compra < 100.0) { // Cliente VIP con compra < 100€
        importe_descuento = monto_compra * 0.10;
    } else if ((tipo_cliente == 'N' || tipo_cliente == 'n') && monto_compra >= 50.0) { // Cliente Normal con compra >= 50€
        importe_descuento = monto_compra * 0.05;
    } else { // Sin descuento
        importe_descuento = 0.0;
    }

    importe_iva = (importe_total - importe_descuento) * 0.21;

    // Calcular el importe definitivo y la donación
    importe_definitivo = importe_total - importe_descuento + importe_iva;
    donacion = importe_definitivo - (int)importe_definitivo;

    // Mostrar el ticket de compra
    printf("\n------- Ticket de Compra -------\n");
    printf("Importe total: %.2f euros\n", importe_total);
    printf("Tipo de cliente: %c\n", tipo_cliente);
    printf("Descuento aplicado: %.2f euros\n", importe_descuento);
    printf("IVA (21%%) aplicado: %.2f euros\n", importe_iva);
    printf("Importe definitivo: %.2f euros\n", importe_definitivo);
    printf("Donacion a causas beneficas: %.2f euros\n", donacion);
    printf("-------------------------------\n");

    return 0;
}
