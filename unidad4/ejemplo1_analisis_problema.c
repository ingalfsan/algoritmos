/*
 * ALGORITMO: Metodologia de Analisis - Calculo de Nomina
 * DESCRIPCION: Calcula el salario neto de un empleado aplicando
 *              la metodologia de analisis de problemas.
 *
 * ANALISIS:
 *   Entrada: nombre, horasTrabajadas, tarifaHora
 *   Proceso: salarioBruto = horas * tarifa
 *            deduccion = bruto * 0.10
 *            neto = bruto - deduccion
 *   Salida:  salarioBruto, deduccion, salarioNeto
 *
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

int main() {
    char nombre[50];
    int horasTrabajadas;
    float tarifaHora, salarioBruto, deduccion, salarioNeto;

    printf("=== Calculo de Nomina ===\n");

    printf("Nombre del empleado: ");
    scanf("%49s", nombre);

    printf("Horas trabajadas: ");
    scanf("%d", &horasTrabajadas);

    printf("Tarifa por hora: ");
    scanf("%f", &tarifaHora);

    salarioBruto = horasTrabajadas * tarifaHora;
    deduccion = salarioBruto * 0.10;
    salarioNeto = salarioBruto - deduccion;

    printf("\n--- Recibo de Pago ---\n");
    printf("Empleado: %s\n", nombre);
    printf("Salario bruto: %.2f\n", salarioBruto);
    printf("Deduccion (10%%): %.2f\n", deduccion);
    printf("Salario neto: %.2f\n", salarioNeto);

    return 0;
}
