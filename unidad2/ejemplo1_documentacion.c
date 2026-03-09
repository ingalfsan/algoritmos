/*
 * ============================================================
 * PROGRAMA: Calculo de Promedio de Notas
 * DESCRIPCION: Lee tres notas y calcula el promedio.
 *              Demuestra buenas practicas de documentacion.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 * VERSION: 1.0
 * ============================================================
 */

#include <stdio.h>

int main() {
    /* Declaracion de variables */
    float nota1, nota2, nota3;
    float sumaNotas, promedio;

    /* Entrada de datos */
    printf("=== Calculo de Promedio de Notas ===\n");

    printf("Ingrese la primera nota: ");
    scanf("%f", &nota1);

    printf("Ingrese la segunda nota: ");
    scanf("%f", &nota2);

    printf("Ingrese la tercera nota: ");
    scanf("%f", &nota3);

    /* Proceso: calculo del promedio */
    sumaNotas = nota1 + nota2 + nota3;
    promedio = sumaNotas / 3.0;

    /* Salida de resultados */
    printf("\n--- Resultados ---\n");
    printf("La suma de las notas es: %.2f\n", sumaNotas);
    printf("El promedio es: %.2f\n", promedio);

    return 0;
}
