/*
 * ALGORITMO: Traza de un Algoritmo (Corrida en Frio)
 * DESCRIPCION: Convierte grados Celsius a Fahrenheit.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Ingrese la temperatura en Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

    printf("La temperatura en Fahrenheit es: %.2f\n", fahrenheit);

    return 0;
}
