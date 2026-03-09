/*
 * ALGORITMO: Conversion de Moneda
 * DESCRIPCION: Convierte bolivares a dolares y euros.
 *
 * ANALISIS:
 *   Entrada: montoBolivares, tasaDolar, tasaEuro
 *   Proceso: montoDolares = montoBolivares / tasaDolar
 *            montoEuros = montoBolivares / tasaEuro
 *   Salida:  montoDolares, montoEuros
 *
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

int main() {
    float montoBolivares, tasaDolar, tasaEuro;
    float montoDolares, montoEuros;

    printf("=== Conversor de Moneda ===\n");

    printf("Monto en Bolivares: ");
    scanf("%f", &montoBolivares);

    printf("Tasa de cambio Bs/USD: ");
    scanf("%f", &tasaDolar);

    printf("Tasa de cambio Bs/EUR: ");
    scanf("%f", &tasaEuro);

    montoDolares = montoBolivares / tasaDolar;
    montoEuros = montoBolivares / tasaEuro;

    printf("\n--- Resultado ---\n");
    printf("%.2f Bs equivalen a:\n", montoBolivares);
    printf("%.2f USD (dolares)\n", montoDolares);
    printf("%.2f EUR (euros)\n", montoEuros);

    return 0;
}
