/*
 * ALGORITMO: Funciones con Condicionales AND y OR
 * DESCRIPCION: Version extendida del ejemplo de funciones.
 *              Calcula el IMC y evalua una nota academica, luego
 *              combina ambos resultados con operadores AND (&&) y
 *              OR (||) para emitir mensajes personalizados.
 * AUTOR: Prof. Jose Alfredo Sanchez
 * FECHA: 2026
 */

#include <stdio.h>

#define PI 3.14159

/* ============================================================
 *  PROCEDIMIENTOS Y FUNCIONES
 * ============================================================ */

/* Procedimiento: imprime una linea separadora */
void mostrarLinea() {
    printf("================================\n");
}

/* Funcion: calcula el area de un circulo */
float calcularAreaCirculo(float radio) {
    return PI * radio * radio;
}

/* Funcion: calcula el Indice de Masa Corporal */
float calcularIMC(float peso, float estatura) {
    return peso / (estatura * estatura);
}

/* Funcion: retorna la categoria IMC como entero
 *   1 = Bajo peso   (<18.5)
 *   2 = Normal      (18.5 - 24.9)
 *   3 = Sobrepeso   (25 - 29.9)
 *   4 = Obesidad    (>=30)
 */
int categoriaIMC(float imc) {
    if (imc < 18.5)       return 1;
    else if (imc < 25.0)  return 2;
    else if (imc < 30.0)  return 3;
    else                  return 4;
}

/* Procedimiento: imprime la clasificacion IMC */
void clasificarIMC(float imc) {
    int cat = categoriaIMC(imc);
    if      (cat == 1) printf("Clasificacion IMC : Bajo peso\n");
    else if (cat == 2) printf("Clasificacion IMC : Peso normal\n");
    else if (cat == 3) printf("Clasificacion IMC : Sobrepeso\n");
    else               printf("Clasificacion IMC : Obesidad\n");
}

/* Funcion: retorna la letra de una nota (0-100)
 *   A = 90-100
 *   B = 80-89
 *   C = 70-79
 *   D = 60-69
 *   F = 0-59
 */
char letraNota(float nota) {
    if      (nota >= 90) return 'A';
    else if (nota >= 80) return 'B';
    else if (nota >= 70) return 'C';
    else if (nota >= 60) return 'D';
    else                 return 'F';
}

/* Procedimiento: imprime clasificacion de nota */
void clasificarNota(float nota) {
    char letra = letraNota(nota);
    if      (letra == 'A') printf("Clasificacion nota: Excelente (A)\n");
    else if (letra == 'B') printf("Clasificacion nota: Bien      (B)\n");
    else if (letra == 'C') printf("Clasificacion nota: Regular   (C)\n");
    else if (letra == 'D') printf("Clasificacion nota: Suficiente(D)\n");
    else                   printf("Clasificacion nota: Reprobado (F)\n");
}

/* ============================================================
 *  MENSAJES COMBINADOS  —  usan && (AND) y || (OR)
 * ============================================================ */

/* Procedimiento: mensaje de salud + rendimiento con AND / OR */
void mensajeCombinado(float imc, float nota) {
    int    cat   = categoriaIMC(imc);
    char   letra = letraNota(nota);

    mostrarLinea();
    printf("  ANALISIS COMBINADO (AND / OR)\n");
    mostrarLinea();

    /* --- AND: ambas condiciones deben cumplirse --- */

    /* Caso ideal: peso normal Y nota aprobada (>= D) */
    if (cat == 2 && letra != 'F') {
        printf("[&&] Salud Y academico OK: Vas muy bien en todo!\n");
    }

    /* Peso bajo Y nota alta: buen estudiante pero cuida tu alimentacion */
    if (cat == 1 && (letra == 'A' || letra == 'B')) {
        printf("[&&] Eres un buen estudiante pero necesitas comer mejor.\n");
    }

    /* Sobrepeso u obesidad Y nota reprobada: atencion total */
    if ((cat == 3 || cat == 4) && letra == 'F') {
        printf("[&&] Atencion: debes mejorar tanto tu salud como tus notas.\n");
    }

    /* Sobrepeso u obesidad Y buen rendimiento */
    if ((cat == 3 || cat == 4) && (letra == 'A' || letra == 'B')) {
        printf("[&&] Gran rendimiento academico! Ahora enfocate en tu salud.\n");
    }

    /* Peso normal Y nota reprobada */
    if (cat == 2 && letra == 'F') {
        printf("[&&] Salud en orden, pero necesitas dedicarle mas tiempo al estudio.\n");
    }

    /* --- OR: al menos una condicion debe cumplirse --- */

    /* Bajo peso O reprobado: se necesita apoyo */
    if (cat == 1 || letra == 'F') {
        printf("[||] Necesitas apoyo: bajo peso O nota reprobada detectados.\n");
    }

    /* Peso normal O nota A/B: algo positivo que destacar */
    if (cat == 2 || letra == 'A' || letra == 'B') {
        printf("[||] Tienes algo que celebrar: salud normal O buena nota.\n");
    }

    /* Obesidad O nota muy baja (<60) — mismo mensaje pero con OR */
    if (cat == 4 || letra == 'F') {
        printf("[||] Hay al menos un area critica que atender (salud u obesidad).\n");
    }

    mostrarLinea();
}

/* ============================================================
 *  PROGRAMA PRINCIPAL
 * ============================================================ */
int main() {
    float radio, area;
    float peso, estatura, imc;
    float nota;

    mostrarLinea();
    printf("  FUNCIONES + CONDICIONALES AND/OR\n");
    mostrarLinea();

    /* --- Circulo --- */
    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);
    area = calcularAreaCirculo(radio);
    printf("Area del circulo          : %.2f\n", area);

    mostrarLinea();

    /* --- IMC --- */
    printf("Ingrese su peso (kg)  : ");
    scanf("%f", &peso);
    printf("Ingrese su estatura (m): ");
    scanf("%f", &estatura);

    imc = calcularIMC(peso, estatura);
    printf("Su IMC                    : %.2f\n", imc);
    clasificarIMC(imc);

    mostrarLinea();

    /* --- Nota --- */
    printf("Ingrese su nota (0-100): ");
    scanf("%f", &nota);
    clasificarNota(nota);

    /* --- Mensajes combinados AND / OR --- */
    mensajeCombinado(imc, nota);

    return 0;
}
