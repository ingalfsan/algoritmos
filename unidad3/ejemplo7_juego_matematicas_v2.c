/*
 * UNIDAD 3: DATOS Y ENTIDADES PRIMITIVAS
 * Ejemplo 7 v2: Juego de Matematicas para Primer Grado - VERSION MEJORADA
 *
 * OBJETIVO:
 * Practicar sumas y/o restas sencillas mediante un juego interactivo
 * por tandas, con numeros grandes en ASCII art para facilitar la lectura.
 *
 * MEJORAS RESPECTO A v1:
 * - Menu inicial para elegir modo: solo sumas, solo restas o combinado
 * - Numeros de cada pregunta mostrados en ASCII art grande estilo infantil
 *
 * CONCEPTOS CLAVE:
 * - Variables de tipo int y const char *
 * - Numeros aleatorios (rand(), srand())
 * - Operadores aritmeticos (+, -)
 * - Estructuras de control (if-else, for, while, do-while)
 * - Arrays de strings (tabla de figuras ASCII)
 * - Funciones auxiliares estaticas
 *
 * Compilacion: gcc ejemplo7_juego_matematicas_v2.c -o juego_v2.exe
 * Ejecucion:   ./juego_v2.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ===== CONSTANTES DEL JUEGO ===== */
#define PREGUNTAS_POR_TANDA  5
#define PUNTAJE_PARA_GANAR   4      /* aciertos minimos para ganar una tanda */
#define MAX_NUMERO          10      /* los operandos van de 1 a MAX_NUMERO   */

/* ===== CODIGOS ANSI DE COLOR ===== */
#define COLOR_RESET    "\033[0m"
#define COLOR_ROJO     "\033[31m"
#define COLOR_VERDE    "\033[32m"
#define COLOR_AMARILLO "\033[33m"
#define COLOR_CYAN     "\033[36m"
#define COLOR_MAGENTA  "\033[35m"
#define COLOR_BLANCO   "\033[97m"
#define NEGRITA        "\033[1m"

/* ===== MODOS DE JUEGO ===== */
#define MODO_SUMA      1
#define MODO_RESTA     2
#define MODO_COMBINADO 3

/*
 * ===== TABLA DE ASCII ART =====
 * Indices: 0-9 = digitos, 10 = '+', 11 = '-', 12 = '=', 13 = '?'
 * Cada figura ocupa 5 filas de 5 caracteres.
 */
static const char *FIGURAS[14][5] = {
    /* 0 */ { " ### ", "#   #", "#   #", "#   #", " ### " },
    /* 1 */ { "  #  ", " ##  ", "  #  ", "  #  ", " ### " },
    /* 2 */ { " ### ", "    #", " ### ", "#    ", " ### " },
    /* 3 */ { " ### ", "    #", "  ## ", "    #", " ### " },
    /* 4 */ { "#   #", "#   #", "#####", "    #", "    #" },
    /* 5 */ { "#### ", "#    ", "#### ", "    #", "#### " },
    /* 6 */ { " ### ", "#    ", "#### ", "#   #", " ### " },
    /* 7 */ { "#####", "    #", "   # ", "  #  ", "  #  " },
    /* 8 */ { " ### ", "#   #", " ### ", "#   #", " ### " },
    /* 9 */ { " ### ", "#   #", " ####", "    #", " ### " },
    /* + */ { "     ", "  #  ", "#####", "  #  ", "     " },
    /* - */ { "     ", "     ", "#####", "     ", "     " },
    /* = */ { "     ", "#####", "     ", "#####", "     " },
    /* ? */ { " ### ", "    #", "  ## ", "     ", "  #  " },
};

/* ===== FUNCION: imprime una fila de un numero en ASCII art (acepta 0..99) ===== */
static void fila_numero(int n, int fila, const char *color) {
    if (n >= 10) {
        printf("%s%s%s ", color, FIGURAS[n / 10][fila], COLOR_RESET);
        printf("%s%s%s",  color, FIGURAS[n % 10][fila], COLOR_RESET);
    } else {
        printf("%s%s%s", color, FIGURAS[n][fila], COLOR_RESET);
    }
}

/*
 * ===== FUNCION: imprime la expresion  "a  OP  b  =  ?"  en ASCII art grande =====
 * col_a  = color para el primer operando
 * col_op = color para el operador y el signo =
 * col_b  = color para el segundo operando
 */
static void imprimir_expresion_grande(int a, int op, int b,
                                      const char *col_a,
                                      const char *col_op,
                                      const char *col_b) {
    int idx_op = (op == 0) ? 10 : 11;   /* 10 = '+', 11 = '-' */
    printf("\n");
    for (int fila = 0; fila < 5; fila++) {
        printf("  ");
        fila_numero(a, fila, col_a);
        printf("   %s%s%s   ", col_op, FIGURAS[idx_op][fila], COLOR_RESET);
        fila_numero(b, fila, col_b);
        printf("   %s%s%s   ", col_op, FIGURAS[12][fila], COLOR_RESET);
        printf("%s%s%s", NEGRITA COLOR_BLANCO, FIGURAS[13][fila], COLOR_RESET);
        printf("\n");
    }
    printf("\n");
}

/* ===== FUNCION: imprimir barra de simbolos ===== */
static void barra(char simbolo, int cantidad, const char *color) {
    printf("%s", color);
    for (int i = 0; i < cantidad; i++) printf("%c", simbolo);
    printf("%s\n", COLOR_RESET);
}

int main(void) {
    /* DECLARACION DE VARIABLES */
    int a, b, respuesta_correcta, respuesta_alumno;
    int aciertos, total_tandas, total_aciertos, total_preguntas;
    int operacion, modo_juego;
    char jugar_otra;

    /* INICIALIZAR GENERADOR DE NUMEROS ALEATORIOS */
    srand((unsigned int)time(NULL));

    /* ===== PANTALLA DE BIENVENIDA ===== */
    barra('*', 46, COLOR_CYAN);
    printf(NEGRITA COLOR_CYAN "  *** JUEGO DE MATEMATICAS - 1er GRADO ***\n" COLOR_RESET);
    barra('*', 46, COLOR_CYAN);
    printf("\n");
    printf(COLOR_AMARILLO "  Reglas del juego:\n" COLOR_RESET);
    printf("  >> Cada tanda tiene " NEGRITA "%d preguntas" COLOR_RESET ".\n", PREGUNTAS_POR_TANDA);
    printf("  >> Necesitas " NEGRITA COLOR_VERDE "%d o mas aciertos" COLOR_RESET " para GANAR.\n",
           PUNTAJE_PARA_GANAR);
    printf("  >> Numeros del 1 al %d.\n", MAX_NUMERO);
    printf("  >> Los resultados nunca son negativos.\n\n");

    /* ===== MENU: MODO DE JUEGO ===== */
    barra('-', 46, COLOR_MAGENTA);
    printf(NEGRITA COLOR_MAGENTA "      Elige el modo de practica:\n" COLOR_RESET);
    barra('-', 46, COLOR_MAGENTA);
    printf("\n");
    printf("    " NEGRITA COLOR_VERDE    "1" COLOR_RESET "  -->  Solo SUMAS    ( + )\n");
    printf("    " NEGRITA COLOR_AMARILLO "2" COLOR_RESET "  -->  Solo RESTAS   ( - )\n");
    printf("    " NEGRITA COLOR_CYAN     "3" COLOR_RESET "  -->  COMBINADO     ( + y - )\n");
    printf("\n  Tu eleccion (1/2/3): ");

    do {
        scanf("%d", &modo_juego);
        if (modo_juego < 1 || modo_juego > 3)
            printf("  Opcion invalida. Elige 1, 2 o 3: ");
    } while (modo_juego < 1 || modo_juego > 3);

    printf("\n");
    if (modo_juego == MODO_SUMA)
        printf(NEGRITA COLOR_VERDE    "  >> Modo elegido: Solo SUMAS!\n\n"  COLOR_RESET);
    else if (modo_juego == MODO_RESTA)
        printf(NEGRITA COLOR_AMARILLO "  >> Modo elegido: Solo RESTAS!\n\n" COLOR_RESET);
    else
        printf(NEGRITA COLOR_CYAN     "  >> Modo elegido: COMBINADO!\n\n"   COLOR_RESET);

    /* ===== CONTADORES GLOBALES ===== */
    total_tandas    = 0;
    total_aciertos  = 0;
    total_preguntas = 0;
    jugar_otra      = 's';

    /* ===== BUCLE PRINCIPAL DE TANDAS ===== */
    while (jugar_otra == 's' || jugar_otra == 'S') {

        total_tandas++;
        aciertos = 0;

        printf("\n");
        barra('-', 46, COLOR_MAGENTA);
        printf(NEGRITA COLOR_MAGENTA "        -=[ TANDA %d ]=-\n" COLOR_RESET, total_tandas);
        barra('-', 46, COLOR_MAGENTA);
        printf("\n");

        /* ===== BUCLE DE PREGUNTAS EN LA TANDA ===== */
        for (int i = 1; i <= PREGUNTAS_POR_TANDA; i++) {

            /* Generar operandos aleatorios entre 1 y MAX_NUMERO */
            a = 1 + rand() % MAX_NUMERO;
            b = 1 + rand() % MAX_NUMERO;

            /* Determinar operacion segun el modo elegido */
            if (modo_juego == MODO_SUMA)
                operacion = 0;
            else if (modo_juego == MODO_RESTA)
                operacion = 1;
            else
                operacion = rand() % 2;  /* combinado: aleatorio */

            /* Para la resta, garantizar resultado >= 0 */
            if (operacion == 1 && a < b) {
                int tmp = a; a = b; b = tmp;
            }

            /* Calcular respuesta correcta */
            respuesta_correcta = (operacion == 0) ? a + b : a - b;

            /* --- Encabezado: barra de progreso + numero de pregunta --- */
            printf(COLOR_CYAN "[" COLOR_RESET);
            for (int k = 1; k <= PREGUNTAS_POR_TANDA; k++) {
                if (k < i)        printf(COLOR_VERDE "#" COLOR_RESET);
                else if (k == i)  printf(COLOR_AMARILLO ">" COLOR_RESET);
                else              printf(COLOR_BLANCO "." COLOR_RESET);
            }
            printf(COLOR_CYAN "]" COLOR_RESET);
            printf(NEGRITA COLOR_CYAN "  -- Pregunta %d de %d --\n" COLOR_RESET,
                   i, PREGUNTAS_POR_TANDA);

            /* --- Representacion visual con asteriscos --- */
            if (operacion == 0) {
                /* SUMA: grupo A en verde + grupo B en amarillo */
                printf("  ");
                for (int k = 0; k < a; k++) printf(COLOR_VERDE NEGRITA "* " COLOR_RESET);
                printf(COLOR_BLANCO NEGRITA "+" COLOR_RESET "  ");
                for (int k = 0; k < b; k++) printf(COLOR_AMARILLO NEGRITA "* " COLOR_RESET);
                printf("\n");
            } else {
                /* RESTA: elementos que quedan en cyan, los que se quitan en rojo */
                printf("  ");
                for (int k = 0; k < a; k++) {
                    if (k < a - b) printf(COLOR_CYAN NEGRITA "* " COLOR_RESET);
                    else           printf(COLOR_ROJO "x " COLOR_RESET);
                }
                printf("\n");
            }

            /* --- Numeros grandes en ASCII art --- */
            const char *col_a, *col_op, *col_b;
            if (operacion == 0) {
                col_a  = NEGRITA COLOR_VERDE;
                col_op = NEGRITA COLOR_VERDE;
                col_b  = NEGRITA COLOR_AMARILLO;
            } else {
                col_a  = NEGRITA COLOR_CYAN;
                col_op = NEGRITA COLOR_AMARILLO;
                col_b  = NEGRITA COLOR_ROJO;
            }
            imprimir_expresion_grande(a, operacion, b, col_a, col_op, col_b);

            /* Leer respuesta del alumno */
            printf("  Tu respuesta: ");
            scanf("%d", &respuesta_alumno);

            /* Evaluar respuesta */
            if (respuesta_alumno == respuesta_correcta) {
                aciertos++;
                printf(COLOR_VERDE "  *** CORRECTO! *** Muy bien! :)\n" COLOR_RESET);
            } else {
                printf(COLOR_ROJO "  !!! Incorrecto. La respuesta era: " NEGRITA "%d\n" COLOR_RESET,
                       respuesta_correcta);
            }
            printf("\n");
            total_preguntas++;
        }

        total_aciertos += aciertos;

        /* ===== RESULTADO DE LA TANDA ===== */
        printf("\n");
        barra('=', 46, COLOR_CYAN);
        printf(NEGRITA "  Resultado de la tanda %d:\n" COLOR_RESET, total_tandas);

        /* Barra visual: estrella por acierto, guion por fallo */
        printf("  ");
        for (int k = 1; k <= PREGUNTAS_POR_TANDA; k++) {
            if (k <= aciertos) printf(COLOR_VERDE NEGRITA "(*)" COLOR_RESET);
            else               printf(COLOR_ROJO "[ ]" COLOR_RESET);
        }
        printf("\n\n");

        printf("  Aciertos: " NEGRITA COLOR_VERDE "%d" COLOR_RESET " de %d\n",
               aciertos, PREGUNTAS_POR_TANDA);

        if (aciertos >= PUNTAJE_PARA_GANAR) {
            barra('*', 46, COLOR_VERDE);
            printf(NEGRITA COLOR_VERDE "  *** FELICIDADES, GANASTE LA TANDA! ***\n" COLOR_RESET);
            barra('*', 46, COLOR_VERDE);
        } else {
            barra('!', 46, COLOR_ROJO);
            printf(NEGRITA COLOR_ROJO "  !!! No ganaste esta vez. Sigue intentando!\n" COLOR_RESET);
            barra('!', 46, COLOR_ROJO);
        }
        barra('=', 46, COLOR_CYAN);

        /* ===== PREGUNTAR SI QUIERE OTRA TANDA ===== */
        printf("\n" COLOR_AMARILLO "  Quieres jugar otra tanda? (s/n): " COLOR_RESET);
        scanf(" %c", &jugar_otra);
    }

    /* ===== RESUMEN FINAL ===== */
    printf("\n");
    barra('#', 46, COLOR_MAGENTA);
    printf(NEGRITA COLOR_MAGENTA "         ### RESUMEN FINAL ###\n" COLOR_RESET);
    barra('#', 46, COLOR_MAGENTA);
    printf("\n");
    printf("  Tandas jugadas  : " NEGRITA COLOR_CYAN    "%d\n" COLOR_RESET, total_tandas);
    printf("  Total preguntas : " NEGRITA COLOR_CYAN    "%d\n" COLOR_RESET, total_preguntas);
    printf("  Total aciertos  : " NEGRITA COLOR_VERDE   "%d\n" COLOR_RESET, total_aciertos);
    printf("  Total fallos    : " NEGRITA COLOR_ROJO    "%d\n" COLOR_RESET,
           total_preguntas - total_aciertos);

    /* Porcentaje global de aciertos */
    int porcentaje = (total_preguntas > 0)
                     ? (total_aciertos * 100) / total_preguntas
                     : 0;
    printf("  Porcentaje      : " NEGRITA COLOR_AMARILLO "%d%%\n" COLOR_RESET, porcentaje);
    printf("\n");

    if (porcentaje >= 80) {
        barra('*', 46, COLOR_VERDE);
        printf(NEGRITA COLOR_VERDE "  *** EXCELENTE! Eres muy bueno/a en matematicas!\n" COLOR_RESET);
        barra('*', 46, COLOR_VERDE);
    } else if (porcentaje >= 60) {
        barra('+', 46, COLOR_AMARILLO);
        printf(NEGRITA COLOR_AMARILLO "  +++ BIEN! Sigue practicando y mejoraras!\n" COLOR_RESET);
        barra('+', 46, COLOR_AMARILLO);
    } else {
        barra('~', 46, COLOR_ROJO);
        printf(NEGRITA COLOR_ROJO "  ~~~ Necesitas practicar mas. No te rindas!\n" COLOR_RESET);
        barra('~', 46, COLOR_ROJO);
    }

    printf("\n" COLOR_CYAN "  Hasta la proxima! :)\n" COLOR_RESET);
    barra('#', 46, COLOR_MAGENTA);
    printf("\n");

    return 0;
}

/*
 * NOTAS TECNICAS:
 *
 * 1. NUMEROS ALEATORIOS:
 *    - srand(time(NULL)): semilla distinta en cada ejecucion
 *    - rand() % N: genera 0..N-1
 *    - 1 + rand() % MAX_NUMERO: genera 1..MAX_NUMERO
 *
 * 2. RESTA SIN NEGATIVOS:
 *    - Se intercambian a y b si a < b antes de restar
 *    - Garantiza resultados >= 0 adecuados para primer grado
 *
 * 3. MODO DE JUEGO:
 *    - MODO_SUMA (1)     : operacion siempre = 0 (solo sumas)
 *    - MODO_RESTA (2)    : operacion siempre = 1 (solo restas)
 *    - MODO_COMBINADO (3): operacion aleatoria, igual que la v1
 *
 * 4. ASCII ART (FIGURAS):
 *    - Tabla bidimensional FIGURAS[14][5]
 *    - Indices 0-9: digitos del 0 al 9 (5 chars de ancho cada fila)
 *    - Indice 10: simbolo '+', 11: '-', 12: '=', 13: '?'
 *    - fila_numero(n, fila, color): imprime la fila dada de n (1 o 2 digitos)
 *    - imprimir_expresion_grande(): recorre las 5 filas e imprime "a OP b = ?"
 *    - Colores diferenciados segun operacion para reforzar la comprension visual
 *
 * 5. CODIGOS ANSI DE COLOR:
 *    - \033[31m rojo, \033[32m verde, \033[33m amarillo
 *    - \033[35m magenta, \033[36m cyan, \033[97m blanco brillante
 *    - \033[1m negrita, \033[0m reset
 *    - Funcionan en terminales Linux/macOS y Windows 10+ (cmd/PowerShell)
 *
 * 6. LOGICA DE VICTORIA POR TANDA:
 *    - aciertos >= PUNTAJE_PARA_GANAR => gana la tanda
 *
 * 7. RESUMEN FINAL:
 *    - Calcula porcentaje global entre todas las tandas
 *    - Mensaje motivacional segun rendimiento (>=80%, >=60%, <60%)
 */
