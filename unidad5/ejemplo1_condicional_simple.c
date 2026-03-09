/*
 * ALGORITMO: Condicional Simple y Doble
 * DESCRIPCION: Determina si un estudiante esta aprobado o reprobado.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

int main() {
    float nota;

    printf("=== Sistema de Evaluacion ===\n");
    printf("Ingrese la nota del estudiante (0-20): ");
    scanf("%f", &nota);

    /* Condicional simple */
    if (nota >= 10) {
        printf("El estudiante esta APROBADO\n");
    }

    /* Condicional doble */
    if (nota >= 10) {
        printf("Felicidades, aprobaste con %.1f puntos\n", nota);
    } else {
        printf("Reprobado con %.1f puntos\n", nota);
        printf("Debe presentar reparacion\n");
    }

    return 0;
}
