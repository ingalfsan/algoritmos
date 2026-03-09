/*
 * ALGORITMO: Condicionales Anidadas y Multiples
 * DESCRIPCION: Clasifica la nota de un estudiante en categorias.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

int main() {
    float nota;
    char clasificacion[20];

    printf("=== Clasificacion de Notas ===\n");
    printf("Ingrese la nota (0-20): ");
    scanf("%f", &nota);

    /* Condicionales anidadas con else if */
    if (nota >= 18) {
        sprintf(clasificacion, "Excelente");
    } else if (nota >= 15) {
        sprintf(clasificacion, "Bueno");
    } else if (nota >= 10) {
        sprintf(clasificacion, "Aprobado");
    } else if (nota >= 5) {
        sprintf(clasificacion, "Insuficiente");
    } else {
        sprintf(clasificacion, "Deficiente");
    }

    printf("Nota: %.1f\n", nota);
    printf("Clasificacion: %s\n", clasificacion);

    return 0;
}
