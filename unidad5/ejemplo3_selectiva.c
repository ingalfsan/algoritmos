/*
 * ALGORITMO: Estructura Selectiva (switch)
 * DESCRIPCION: Menu de operaciones aritmeticas usando switch.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

int main() {
    int opcion;
    float num1, num2, resultado;

    printf("=== Calculadora Basica ===\n");
    printf("Ingrese primer numero: ");
    scanf("%f", &num1);
    printf("Ingrese segundo numero: ");
    scanf("%f", &num2);

    printf("\nSeleccione la operacion:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            resultado = num1 + num2;
            printf("Resultado: %.2f + %.2f = %.2f\n", num1, num2, resultado);
            break;
        case 2:
            resultado = num1 - num2;
            printf("Resultado: %.2f - %.2f = %.2f\n", num1, num2, resultado);
            break;
        case 3:
            resultado = num1 * num2;
            printf("Resultado: %.2f * %.2f = %.2f\n", num1, num2, resultado);
            break;
        case 4:
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("Resultado: %.2f / %.2f = %.2f\n", num1, num2, resultado);
            } else {
                printf("Error: Division por cero\n");
            }
            break;
        default:
            printf("Opcion no valida\n");
            break;
    }

    return 0;
}
