/*
 * ALGORITMO: Ciclo Para (for) y Ciclos Anidados
 * DESCRIPCION: Factorial y tabla pitagorica con ciclos anidados.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

int main() {
    int n, i;
    long factorial;

    /* Ejemplo 1: Factorial */
    printf("=== Factorial de un Numero ===\n");
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    factorial = 1;
    for (i = 1; i <= n; i++) {
        factorial = factorial * i;
    }

    printf("El factorial de %d es: %ld\n", n, factorial);

    /* Ejemplo 2: Ciclos anidados - Tabla pitagorica */
    int fila, columna;

    printf("\n=== Tabla Pitagorica (1 al 5) ===\n");

    /* Encabezado */
    printf("     ");
    for (columna = 1; columna <= 5; columna++) {
        printf("%4d", columna);
    }
    printf("\n   +--------------------\n");

    /* Cuerpo de la tabla */
    for (fila = 1; fila <= 5; fila++) {
        printf("%2d |", fila);
        for (columna = 1; columna <= 5; columna++) {
            printf("%4d", fila * columna);
        }
        printf("\n");
    }

    return 0;
}
