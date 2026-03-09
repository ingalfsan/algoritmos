/*
 * ALGORITMO: Funciones y Procedimientos
 * DESCRIPCION: Definicion y llamada de funciones y procedimientos.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

#define PI 3.14159

/* Procedimiento: no retorna valor (void) */
void mostrarLinea() {
    printf("================================\n");
}

/* Funcion: retorna un valor */
float calcularAreaCirculo(float radio) {
    return PI * radio * radio;
}

/* Funcion con multiples parametros */
float calcularIMC(float peso, float estatura) {
    return peso / (estatura * estatura);
}

/* Procedimiento con parametro */
void clasificarIMC(float imc) {
    if (imc < 18.5) {
        printf("Clasificacion: Bajo peso\n");
    } else if (imc < 25) {
        printf("Clasificacion: Peso normal\n");
    } else if (imc < 30) {
        printf("Clasificacion: Sobrepeso\n");
    } else {
        printf("Clasificacion: Obesidad\n");
    }
}

/* Programa principal */
int main() {
    float radio, area, peso, estatura, imc;

    mostrarLinea();
    printf(" PROGRAMA DE FUNCIONES\n");
    mostrarLinea();

    /* Uso de funcion calcularAreaCirculo */
    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);
    area = calcularAreaCirculo(radio);
    printf("El area del circulo es: %.2f\n", area);

    mostrarLinea();

    /* Uso de funciones calcularIMC y clasificarIMC */
    printf("Ingrese su peso (kg): ");
    scanf("%f", &peso);
    printf("Ingrese su estatura (m): ");
    scanf("%f", &estatura);

    imc = calcularIMC(peso, estatura);
    printf("Su IMC es: %.2f\n", imc);
    clasificarIMC(imc);

    mostrarLinea();

    return 0;
}
