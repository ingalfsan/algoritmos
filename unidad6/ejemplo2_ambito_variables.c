/*
 * ALGORITMO: Ambito de Variables y Pase de Parametros
 * DESCRIPCION: Variables locales, globales, pase por valor
 *              y por referencia (punteros en C).
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

/* Variable GLOBAL: accesible desde cualquier parte */
int contadorGlobal = 0;

/* Procedimiento que usa variable global */
void incrementarContador() {
    contadorGlobal = contadorGlobal + 1;
    printf("Contador global: %d\n", contadorGlobal);
}

/* Funcion con variable LOCAL */
int sumar(int a, int b) {
    /* 'resultado' es LOCAL: solo existe dentro de esta funcion */
    int resultado;
    resultado = a + b;
    return resultado;
}

/* Pase por VALOR: no modifica el original */
void duplicarPorValor(int numero) {
    numero = numero * 2;
    printf("Dentro de la funcion (por valor): %d\n", numero);
}

/* Pase por REFERENCIA: en C se usa punteros */
void duplicarPorReferencia(int *numero) {
    *numero = *numero * 2;
    printf("Dentro de la funcion (por referencia): %d\n", *numero);
}

int main() {
    int x, y, suma;

    /* Uso de variable global */
    printf("=== Variables Globales ===\n");
    incrementarContador();
    incrementarContador();
    incrementarContador();

    /* Uso de variables locales */
    printf("\n=== Variables Locales ===\n");
    x = 10;
    y = 20;
    suma = sumar(x, y);
    printf("%d + %d = %d\n", x, y, suma);

    /* Pase por valor */
    printf("\n=== Pase por Valor ===\n");
    x = 5;
    printf("Antes de la funcion: x = %d\n", x);
    duplicarPorValor(x);
    printf("Despues de la funcion: x = %d\n", x); /* x NO cambia */

    /* Pase por referencia (punteros) */
    printf("\n=== Pase por Referencia ===\n");
    x = 5;
    printf("Antes de la funcion: x = %d\n", x);
    duplicarPorReferencia(&x);
    printf("Despues de la funcion: x = %d\n", x); /* x SI cambia */

    return 0;
}
