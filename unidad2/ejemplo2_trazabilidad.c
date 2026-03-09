/*
 * ============================================================
 * PROGRAMA: Trazabilidad de un Algoritmo
 * DESCRIPCION: Calcula el precio final aplicando descuento.
 *              Incluye ejemplo de trazabilidad en pseudocodigo.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 * ENTRADA: precio (float), porcentajeDescuento (float)
 * SALIDA: montoDescuento (float), precioFinal (float)
 * ============================================================
 */

#include <stdio.h>

int main() {
    float precio, porcentajeDescuento, montoDescuento, precioFinal;

    printf("=== Calculo de Descuento ===\n");

    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);

    printf("Ingrese el porcentaje de descuento: ");
    scanf("%f", &porcentajeDescuento);

    montoDescuento = precio * porcentajeDescuento / 100.0;
    precioFinal = precio - montoDescuento;

    printf("\n--- Resultados ---\n");
    printf("Monto del descuento: %.2f\n", montoDescuento);
    printf("Precio final: %.2f\n", precioFinal);

    return 0;
}
