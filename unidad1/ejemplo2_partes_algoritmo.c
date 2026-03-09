/*
 * ALGORITMO: Partes de un Algoritmo
 * DESCRIPCION: Demuestra las tres partes fundamentales de un algoritmo:
 *              Entrada, Proceso y Salida.
 *              Calcula el area de un rectangulo.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

int main() {
    /* ENTRADA: Declaracion y lectura de datos */
    float base, altura, area;

    printf("Ingrese la base del rectangulo: ");
    scanf("%f", &base);

    printf("Ingrese la altura del rectangulo: ");
    scanf("%f", &altura);

    /* PROCESO: Calculo */
    area = base * altura;

    /* SALIDA: Resultado */
    printf("El area del rectangulo es: %.2f\n", area);

    return 0;
}
