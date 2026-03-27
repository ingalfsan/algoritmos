/*
 * ============================================================================
 * PROGRAMA: Casa de Cambio - Venta de Divisas
 * DESCRIPCION: Calcula la cantidad de dolares que recibe un cliente
 *              al cambiar bolivares, descontando una comision por servicio.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * MATERIA: Algoritmos y Programacion - Unidad 1
 * ============================================================================
 */

#include <stdio.h>

int main() {
    /* Declaracion de variables */
    float precioDolar;          /* Precio del dolar segun BCV */
    float bolivaresCliente;     /* Cantidad de bolivares del cliente */
    float porcentajeComision;   /* Porcentaje de comision (ej: 5 para 5%) */
    float montoComision;        /* Monto cobrado por comision en Bs */
    float montoNeto;            /* Bolivares despues de descontar comision */
    float dolaresFinales;       /* Dolares que recibe el cliente */

    /* ===== ENTRADA DE DATOS ===== */
    printf("=== CASA DE CAMBIO - VENTA DE DOLARES ===\n");
    printf("\n");

    printf("Ingrese el precio del dolar (BCV): ");
    scanf("%f", &precioDolar);

    printf("Ingrese la cantidad de Bolivares: ");
    scanf("%f", &bolivaresCliente);

    printf("Ingrese el porcentaje de comision (%%): ");
    scanf("%f", &porcentajeComision);

    /* ===== PROCESO: CALCULOS ===== */
    /* Calcular el monto de la comision en bolivares */
    montoComision = (bolivaresCliente * porcentajeComision) / 100;

    /* Calcular el monto neto (bolivares - comision) */
    montoNeto = bolivaresCliente - montoComision;

    /* Calcular la cantidad de dolares finales */
    dolaresFinales = montoNeto / precioDolar;

    /* ===== SALIDA DE RESULTADOS ===== */
    printf("\n");
    printf("--- RESUMEN DE LA OPERACION ---\n");
    printf("Bolivares entregados: %.2f Bs\n", bolivaresCliente);
    printf("Comision cobrada (%.1f%%): %.2f Bs\n", porcentajeComision, montoComision);
    printf("Monto neto: %.2f Bs\n", montoNeto);
    printf("Dolares a recibir: $%.2f\n", dolaresFinales);

    return 0;
}

/*
 * ============================================================================
 * EJEMPLO DE EJECUCION:
 * ============================================================================
 *
 * === CASA DE CAMBIO - VENTA DE DOLARES ===
 *
 * Ingrese el precio del dolar (BCV): 36.50
 * Ingrese la cantidad de Bolivares: 1000
 * Ingrese el porcentaje de comision (%): 5
 *
 * --- RESUMEN DE LA OPERACION ---
 * Bolivares entregados: 1000.00 Bs
 * Comision cobrada (5.0%): 50.00 Bs
 * Monto neto: 950.00 Bs
 * Dolares a recibir: $26.03
 *
 * ============================================================================
 *
 * EXPLICACION DEL CODIGO:
 * ============================================================================
 *
 * 1. DECLARACION DE VARIABLES:
 *    Se declaran 6 variables tipo float para manejar numeros decimales:
 *    - 3 para entrada (precioDolar, bolivaresCliente, porcentajeComision)
 *    - 3 para calculos (montoComision, montoNeto, dolaresFinales)
 *
 * 2. ENTRADA DE DATOS:
 *    Se usa printf() para mostrar mensajes y scanf() para leer datos.
 *    El formato %f se usa para leer numeros reales (float).
 *
 * 3. PROCESO (CALCULOS):
 *    a) montoComision = (bolivaresCliente * porcentajeComision) / 100
 *       Formula para calcular el porcentaje de un monto.
 *       Ejemplo: 5% de 1000 = (1000 * 5) / 100 = 50
 *
 *    b) montoNeto = bolivaresCliente - montoComision
 *       Se resta la comision del total de bolivares.
 *
 *    c) dolaresFinales = montoNeto / precioDolar
 *       Se divide el monto neto entre el precio del dolar.
 *
 * 4. SALIDA DE RESULTADOS:
 *    Se usa printf() con formato %.2f para mostrar 2 decimales.
 *    El simbolo %% se usa para imprimir el caracter % literal.
 *
 * ============================================================================
 *
 * CONCEPTOS APLICADOS (UNIDAD 1):
 * ============================================================================
 *
 * - Partes de un algoritmo: ENTRADA, PROCESO, SALIDA
 * - Variables de trabajo: para almacenar resultados intermedios
 * - Operadores aritmeticos: *, /, -
 * - Expresiones aritmeticas: combinacion de operadores y variables
 * - Tipos de datos: float (numeros reales con decimales)
 *
 * ============================================================================
 *
 * PRUEBAS ADICIONALES:
 * ============================================================================
 *
 * Caso 2:
 * Entrada: precioDolar=40.00, bolivaresCliente=2000.00, comision=3.0%
 * Salida esperada: Comision=60.00 Bs, Dolares=$48.50
 *
 * Caso 3:
 * Entrada: precioDolar=35.00, bolivaresCliente=500.00, comision=2.5%
 * Salida esperada: Comision=12.50 Bs, Dolares=$13.93
 *
 * ============================================================================
 */
