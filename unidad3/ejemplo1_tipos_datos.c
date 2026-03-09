/*
 * ALGORITMO: Tipos de Datos y Variables
 * DESCRIPCION: Demuestra los diferentes tipos de datos:
 *              enteros, reales, caracteres y cadenas.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

int main() {
    /* Declaracion de variables por tipo de dato */
    int edad, cantidad;
    float estatura, peso;
    char inicial;
    char nombre[50];

    /* Asignacion de valores */
    edad = 20;
    cantidad = 5;
    estatura = 1.75;
    peso = 68.5;
    inicial = 'J';
    sprintf(nombre, "Juan Perez");

    /* Salida de cada tipo de dato */
    printf("=== Tipos de Datos ===\n");
    printf("Nombre (cadena): %s\n", nombre);
    printf("Inicial (caracter): %c\n", inicial);
    printf("Edad (entero): %d\n", edad);
    printf("Cantidad (entero): %d\n", cantidad);
    printf("Estatura (real): %.2f\n", estatura);
    printf("Peso (real): %.1f\n", peso);

    return 0;
}
