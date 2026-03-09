/*
 * ALGORITMO: Prueba de Caja Negra
 * DESCRIPCION: Clasifica triangulos segun sus lados.
 *              Incluye funcion de pruebas automaticas.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>
#include <string.h>

/* Funcion que clasifica el triangulo */
void clasificarTriangulo(float a, float b, float c, char *resultado) {
    /* Verificar si es un triangulo valido */
    if (a <= 0 || b <= 0 || c <= 0) {
        strcpy(resultado, "No es un triangulo valido");
        return;
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        strcpy(resultado, "No es un triangulo valido");
        return;
    }

    if (a == b && b == c) {
        strcpy(resultado, "Equilatero");
    } else if (a == b || a == c || b == c) {
        strcpy(resultado, "Isosceles");
    } else {
        strcpy(resultado, "Escaleno");
    }
}

/* Funcion de pruebas de caja negra */
void ejecutarPruebas() {
    char resultado[50];
    int pruebas_pasadas = 0;
    int total_pruebas = 7;

    printf("=== Ejecutando Pruebas de Caja Negra ===\n\n");

    /* Caso 1: Equilatero */
    clasificarTriangulo(5, 5, 5, resultado);
    printf("Caso 1: (5,5,5) -> %s", resultado);
    if (strcmp(resultado, "Equilatero") == 0) { printf(" [OK]\n"); pruebas_pasadas++; }
    else { printf(" [FALLO]\n"); }

    /* Caso 2: Isosceles */
    clasificarTriangulo(5, 5, 3, resultado);
    printf("Caso 2: (5,5,3) -> %s", resultado);
    if (strcmp(resultado, "Isosceles") == 0) { printf(" [OK]\n"); pruebas_pasadas++; }
    else { printf(" [FALLO]\n"); }

    /* Caso 3: Escaleno */
    clasificarTriangulo(3, 4, 5, resultado);
    printf("Caso 3: (3,4,5) -> %s", resultado);
    if (strcmp(resultado, "Escaleno") == 0) { printf(" [OK]\n"); pruebas_pasadas++; }
    else { printf(" [FALLO]\n"); }

    /* Caso 4: No valido (suma de dos lados <= tercero) */
    clasificarTriangulo(1, 1, 3, resultado);
    printf("Caso 4: (1,1,3) -> %s", resultado);
    if (strcmp(resultado, "No es un triangulo valido") == 0) { printf(" [OK]\n"); pruebas_pasadas++; }
    else { printf(" [FALLO]\n"); }

    /* Caso 5: No valido (lado cero) */
    clasificarTriangulo(0, 5, 5, resultado);
    printf("Caso 5: (0,5,5) -> %s", resultado);
    if (strcmp(resultado, "No es un triangulo valido") == 0) { printf(" [OK]\n"); pruebas_pasadas++; }
    else { printf(" [FALLO]\n"); }

    /* Caso 6: No valido (lado negativo) */
    clasificarTriangulo(-1, 5, 5, resultado);
    printf("Caso 6: (-1,5,5) -> %s", resultado);
    if (strcmp(resultado, "No es un triangulo valido") == 0) { printf(" [OK]\n"); pruebas_pasadas++; }
    else { printf(" [FALLO]\n"); }

    /* Caso 7: Isosceles variante */
    clasificarTriangulo(7, 7, 3, resultado);
    printf("Caso 7: (7,7,3) -> %s", resultado);
    if (strcmp(resultado, "Isosceles") == 0) { printf(" [OK]\n"); pruebas_pasadas++; }
    else { printf(" [FALLO]\n"); }

    printf("\nResultado: %d/%d pruebas pasadas\n", pruebas_pasadas, total_pruebas);
}

int main() {
    int opcion;
    char resultado[50];
    float lado1, lado2, lado3;

    printf("=== Clasificador de Triangulos ===\n");
    printf("1. Ingresar datos manualmente\n");
    printf("2. Ejecutar pruebas de caja negra\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese el lado 1: ");
        scanf("%f", &lado1);
        printf("Ingrese el lado 2: ");
        scanf("%f", &lado2);
        printf("Ingrese el lado 3: ");
        scanf("%f", &lado3);

        clasificarTriangulo(lado1, lado2, lado3, resultado);
        printf("Resultado: %s\n", resultado);
    } else {
        ejecutarPruebas();
    }

    return 0;
}
