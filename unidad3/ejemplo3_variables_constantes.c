/*
 * ALGORITMO: Variables y Constantes
 * DESCRIPCION: Demuestra variables de trabajo, contador,
 *              acumulador, y uso de constantes.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

#define PI 3.14159
#define MAX_ESTUDIANTES 5

int main() {
    /* Variables de trabajo */
    float radio, area;

    /* Variable contador */
    int contador;

    /* Variable acumulador */
    float sumaNotas, nota;

    /* Ejemplo 1: Uso de constante y variable de trabajo */
    printf("=== Calculo de Area de Circulo ===\n");
    printf("Ingrese el radio: ");
    scanf("%f", &radio);

    area = PI * radio * radio;
    printf("El area es: %.2f\n", area);

    /* Ejemplo 2: Uso de contador y acumulador */
    printf("\n=== Suma de Notas de %d Estudiantes ===\n", MAX_ESTUDIANTES);
    sumaNotas = 0;
    contador = 1;

    while (contador <= MAX_ESTUDIANTES) {
        printf("Ingrese nota del estudiante %d: ", contador);
        scanf("%f", &nota);
        sumaNotas = sumaNotas + nota;   /* acumulador */
        contador = contador + 1;         /* contador */
    }

    printf("\nLa suma total de notas es: %.2f\n", sumaNotas);
    printf("El promedio es: %.2f\n", sumaNotas / MAX_ESTUDIANTES);

    return 0;
}
