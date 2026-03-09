/*
 * ALGORITMO: Operadores Aritmeticos, Relacionales y Logicos
 * DESCRIPCION: Demuestra el uso de los diferentes tipos de operadores.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

int main() {
    int a, b;

    a = 15;
    b = 4;

    /* OPERADORES ARITMETICOS */
    printf("=== Operadores Aritmeticos ===\n");
    printf("a = %d  b = %d\n", a, b);
    printf("Suma (a + b) = %d\n", a + b);
    printf("Resta (a - b) = %d\n", a - b);
    printf("Multiplicacion (a * b) = %d\n", a * b);
    printf("Division (a / b) = %d\n", a / b);
    printf("Modulo (a %% b) = %d\n", a % b);

    /* OPERADORES RELACIONALES */
    printf("\n=== Operadores Relacionales ===\n");
    printf("a > b  : %d\n", a > b);
    printf("a < b  : %d\n", a < b);
    printf("a >= b : %d\n", a >= b);
    printf("a <= b : %d\n", a <= b);
    printf("a == b : %d\n", a == b);
    printf("a != b : %d\n", a != b);

    /* OPERADORES LOGICOS */
    printf("\n=== Operadores Logicos ===\n");
    printf("(a > 10) && (b < 10) : %d\n", (a > 10) && (b < 10));
    printf("(a > 20) || (b < 10) : %d\n", (a > 20) || (b < 10));
    printf("!(a > 10) : %d\n", !(a > 10));

    return 0;
}
