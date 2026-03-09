/*
 * ALGORITMO: Ciclo Mientras (while)
 * DESCRIPCION: Tabla de multiplicar y suma con centinela.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

int main() {
    int numero, i, resultado;

    /* Ejemplo 1: Tabla de multiplicar */
    printf("=== Tabla de Multiplicar ===\n");
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    i = 1;
    while (i <= 10) {
        resultado = numero * i;
        printf("%d x %d = %d\n", numero, i, resultado);
        i = i + 1;
    }

    /* Ejemplo 2: Suma hasta ingresar 0 (centinela) */
    printf("\n=== Suma de Numeros ===\n");
    printf("Ingrese numeros (0 para terminar):\n");

    float valor, suma;
    int cantidadNumeros;

    suma = 0;
    cantidadNumeros = 0;

    printf("Numero: ");
    scanf("%f", &valor);

    while (valor != 0) {
        suma = suma + valor;
        cantidadNumeros = cantidadNumeros + 1;
        printf("Numero: ");
        scanf("%f", &valor);
    }

    printf("\nSe ingresaron %d numeros\n", cantidadNumeros);
    printf("La suma total es: %.2f\n", suma);

    return 0;
}
