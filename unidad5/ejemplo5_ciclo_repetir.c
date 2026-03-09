/*
 * ALGORITMO: Ciclo Repetir-Hasta (do-while)
 * DESCRIPCION: Menu con validacion usando do-while.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

int main() {
    int opcion;
    float numero, resultado;

    do {
        printf("\n=== Menu Principal ===\n");
        printf("1. Calcular cuadrado de un numero\n");
        printf("2. Calcular cubo de un numero\n");
        printf("3. Verificar si es par o impar\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un numero: ");
                scanf("%f", &numero);
                resultado = numero * numero;
                printf("El cuadrado de %.2f es: %.2f\n", numero, resultado);
                break;
            case 2:
                printf("Ingrese un numero: ");
                scanf("%f", &numero);
                resultado = numero * numero * numero;
                printf("El cubo de %.2f es: %.2f\n", numero, resultado);
                break;
            case 3:
                printf("Ingrese un numero entero: ");
                scanf("%f", &numero);
                if ((int)numero % 2 == 0) {
                    printf("%.0f es PAR\n", numero);
                } else {
                    printf("%.0f es IMPAR\n", numero);
                }
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 4);

    printf("Programa finalizado.\n");

    return 0;
}
