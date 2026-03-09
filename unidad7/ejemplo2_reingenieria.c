/*
 * ALGORITMO: Reingenieria de Programas
 * DESCRIPCION: Version mejorada de un programa de facturacion.
 *              Aplica principios de reingenieria:
 *              - Nombres descriptivos
 *              - Constantes en vez de valores magicos
 *              - Modularizacion con funciones
 *              - Documentacion clara
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 *
 * NOTA: Vea el archivo .txt para comparar la version
 *       ANTES y DESPUES de la reingenieria.
 */

#include <stdio.h>

#define TASA_IVA 0.16

/* Calcula el subtotal de la compra */
float calcularSubtotal(float precioUnitario, int cantidad) {
    return precioUnitario * cantidad;
}

/* Calcula el IVA sobre un monto */
float calcularIVA(float subtotal) {
    return subtotal * TASA_IVA;
}

/* Muestra una linea separadora */
void mostrarSeparador() {
    printf("----------------------------------\n");
}

int main() {
    float precioUnitario, subtotal, iva, total;
    int cantidad;

    printf("=== Factura de Venta ===\n");
    mostrarSeparador();

    printf("Precio unitario del producto: ");
    scanf("%f", &precioUnitario);

    printf("Cantidad de productos: ");
    scanf("%d", &cantidad);

    /* Calculos usando funciones */
    subtotal = calcularSubtotal(precioUnitario, cantidad);
    iva = calcularIVA(subtotal);
    total = subtotal + iva;

    /* Presentacion de resultados */
    printf("\n");
    mostrarSeparador();
    printf("  Detalle de Factura\n");
    mostrarSeparador();
    printf("  Subtotal:       %.2f\n", subtotal);
    printf("  IVA (16%%):      %.2f\n", iva);
    mostrarSeparador();
    printf("  TOTAL A PAGAR:  %.2f\n", total);
    mostrarSeparador();

    return 0;
}
