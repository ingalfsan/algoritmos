/*
 * UNIDAD 3: DATOS Y ENTIDADES PRIMITIVAS
 * Ejemplo 7: Juego de Matematicas para Primer Grado
 *
 * OBJETIVO:
 * Practicar sumas y restas sencillas mediante un juego interactivo
 * por tandas, contando aciertos y determinando si el jugador gano.
 *
 * CONCEPTOS CLAVE:
 * - Variables de tipo int
 * - Numeros aleatorios (rand(), srand())
 * - Operadores aritmeticos (+, -)
 * - Operadores relacionales (==, >=)
 * - Entrada y salida (scanf, printf)
 * - Estructuras de control (if-else, for, while)
 * - Constantes (#define)
 *
 * Compilacion: gcc ejemplo7_juego_matematicas.c -o juego_matematicas.exe
 * Ejecucion:   ./juego_matematicas.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ===== CONSTANTES DEL JUEGO ===== */
#define PREGUNTAS_POR_TANDA  5
#define PUNTAJE_PARA_GANAR   4      /* aciertos minimos para ganar una tanda */
#define MAX_NUMERO          10      /* los operandos van de 1 a MAX_NUMERO   */

/* ===== CODIGOS ANSI DE COLOR ===== */
#define COLOR_RESET   "\033[0m"
#define COLOR_ROJO    "\033[31m"
#define COLOR_VERDE   "\033[32m"
#define COLOR_AMARILLO "\033[33m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_BLANCO  "\033[97m"
#define NEGRITA       "\033[1m"

/* ===== FUNCION: imprimir barra de estrellas ===== */
void barra(char simbolo, int cantidad, const char *color) {
    printf("%s", color);
    for (int i = 0; i < cantidad; i++) printf("%c", simbolo);
    printf("%s\n", COLOR_RESET);
}

int main() {
    /* DECLARACION DE VARIABLES */
    int a, b, respuesta_correcta, respuesta_alumno;
    int aciertos, total_tandas, total_aciertos, total_preguntas;
    int operacion;   /* 0 = suma, 1 = resta */
    char jugar_otra;

    /* INICIALIZAR GENERADOR DE NUMEROS ALEATORIOS */
    srand((unsigned int)time(NULL));

    /* ===== PANTALLA DE BIENVENIDA ===== */
    barra('*', 42, COLOR_CYAN);
    printf(NEGRITA COLOR_CYAN "  *** JUEGO DE MATEMATICAS - 1er GRADO ***\n" COLOR_RESET);
    barra('*', 42, COLOR_CYAN);
    printf("\n");
    printf(COLOR_AMARILLO "  Reglas del juego:\n" COLOR_RESET);
    printf("  >> Cada tanda tiene " NEGRITA "%d preguntas" COLOR_RESET ".\n", PREGUNTAS_POR_TANDA);
    printf("  >> Necesitas " NEGRITA COLOR_VERDE "%d o mas aciertos" COLOR_RESET " para GANAR.\n", PUNTAJE_PARA_GANAR);
    printf("  >> Hay sumas y restas con numeros del 1 al %d.\n", MAX_NUMERO);
    printf("  >> Los resultados nunca son negativos.\n\n");

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
        barra('-', 42, COLOR_MAGENTA);
        printf(NEGRITA COLOR_MAGENTA "        -=[ TANDA %d ]=-\n" COLOR_RESET, total_tandas);
        barra('-', 42, COLOR_MAGENTA);
        printf("\n");

        /* ===== BUCLE DE PREGUNTAS EN LA TANDA ===== */
        for (int i = 1; i <= PREGUNTAS_POR_TANDA; i++) {

            /* Generar operandos aleatorios entre 1 y MAX_NUMERO */
            a = 1 + rand() % MAX_NUMERO;
            b = 1 + rand() % MAX_NUMERO;

            /* Elegir operacion aleatoria: 0=suma, 1=resta */
            operacion = rand() % 2;

            /* Para la resta, garantizar resultado >= 0 */
            if (operacion == 1 && a < b) {
                int tmp = a;
                a = b;
                b = tmp;
            }

            /* Calcular respuesta correcta */
            if (operacion == 0) {
                respuesta_correcta = a + b;
            } else {
                respuesta_correcta = a - b;
            }

            /* --- Encabezado: numero de pregunta + barra de progreso --- */
            printf(COLOR_CYAN "[" COLOR_RESET);
            for (int k = 1; k <= PREGUNTAS_POR_TANDA; k++) {
                if (k < i)        printf(COLOR_VERDE "#" COLOR_RESET);
                else if (k == i)  printf(COLOR_AMARILLO ">" COLOR_RESET);
                else              printf(COLOR_BLANCO "." COLOR_RESET);
            }
            printf(COLOR_CYAN "]" COLOR_RESET);
            printf(NEGRITA COLOR_CYAN "  -- Pregunta %d de %d --\n" COLOR_RESET, i, PREGUNTAS_POR_TANDA);

            /* --- Representacion visual de los objetos (asteriscos de colores) --- */
            if (operacion == 0) {
                /* SUMA: grupo A en verde + grupo B en amarillo */
                printf("  ");
                for (int k = 0; k < a; k++) printf(COLOR_VERDE NEGRITA "* " COLOR_RESET);
                printf(COLOR_BLANCO NEGRITA "+" COLOR_RESET "  ");
                for (int k = 0; k < b; k++) printf(COLOR_AMARILLO NEGRITA "* " COLOR_RESET);
                printf("\n");
            } else {
                /* RESTA: grupo A en cyan, luego tachados en rojo los que se quitan */
                printf("  ");
                for (int k = 0; k < a; k++) {
                    if (k < a - b)
                        printf(COLOR_CYAN NEGRITA "* " COLOR_RESET);
                    else
                        printf(COLOR_ROJO "x " COLOR_RESET);  /* los que se restan */
                }
                printf("\n");
            }

            /* --- La operacion matematica en linea propia, grande y clara --- */
            if (operacion == 0) {
                printf(NEGRITA COLOR_VERDE "\n    %d  +  %d  =  ?" COLOR_RESET "\n", a, b);
            } else {
                printf(NEGRITA COLOR_AMARILLO "\n    %d  -  %d  =  ?" COLOR_RESET "\n", a, b);
            }
            printf("  Respuesta: ");

            /* Leer respuesta del alumno */
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
        barra('=', 42, COLOR_CYAN);
        printf(NEGRITA "  Resultado de la tanda %d:\n" COLOR_RESET, total_tandas);

        /* Barra visual de aciertos: estrella por acierto, guion por fallo */
        printf("  ");
        for (int k = 1; k <= PREGUNTAS_POR_TANDA; k++) {
            if (k <= aciertos) printf(COLOR_VERDE NEGRITA "(*)" COLOR_RESET);
            else               printf(COLOR_ROJO "[ ]" COLOR_RESET);
        }
        printf("\n\n");

        printf("  Aciertos: " NEGRITA COLOR_VERDE "%d" COLOR_RESET " de %d\n",
               aciertos, PREGUNTAS_POR_TANDA);

        if (aciertos >= PUNTAJE_PARA_GANAR) {
            barra('*', 42, COLOR_VERDE);
            printf(NEGRITA COLOR_VERDE "  *** FELICIDADES, GANASTE LA TANDA! ***\n" COLOR_RESET);
            barra('*', 42, COLOR_VERDE);
        } else {
            barra('!', 42, COLOR_ROJO);
            printf(NEGRITA COLOR_ROJO "  !!! No ganaste esta vez. Sigue intentando!\n" COLOR_RESET);
            barra('!', 42, COLOR_ROJO);
        }
        barra('=', 42, COLOR_CYAN);

        /* ===== PREGUNTAR SI QUIERE OTRA TANDA ===== */
        printf("\n" COLOR_AMARILLO "  Quieres jugar otra tanda? (s/n): " COLOR_RESET);
        scanf(" %c", &jugar_otra);
    }

    /* ===== RESUMEN FINAL ===== */
    printf("\n");
    barra('#', 42, COLOR_MAGENTA);
    printf(NEGRITA COLOR_MAGENTA "         ### RESUMEN FINAL ###\n" COLOR_RESET);
    barra('#', 42, COLOR_MAGENTA);
    printf("\n");
    printf("  Tandas jugadas  : " NEGRITA COLOR_CYAN "%d\n" COLOR_RESET, total_tandas);
    printf("  Total preguntas : " NEGRITA COLOR_CYAN "%d\n" COLOR_RESET, total_preguntas);
    printf("  Total aciertos  : " NEGRITA COLOR_VERDE "%d\n" COLOR_RESET, total_aciertos);
    printf("  Total fallos    : " NEGRITA COLOR_ROJO "%d\n" COLOR_RESET,
           total_preguntas - total_aciertos);

    /* Porcentaje de aciertos */
    int porcentaje = (total_preguntas > 0)
                     ? (total_aciertos * 100) / total_preguntas
                     : 0;
    printf("  Porcentaje      : " NEGRITA COLOR_AMARILLO "%d%%\n" COLOR_RESET, porcentaje);

    printf("\n");
    if (porcentaje >= 80) {
        barra('*', 42, COLOR_VERDE);
        printf(NEGRITA COLOR_VERDE "  *** EXCELENTE! Eres muy bueno/a en matematicas!\n" COLOR_RESET);
        barra('*', 42, COLOR_VERDE);
    } else if (porcentaje >= 60) {
        barra('+', 42, COLOR_AMARILLO);
        printf(NEGRITA COLOR_AMARILLO "  +++ BIEN! Sigue practicando y mejoraras!\n" COLOR_RESET);
        barra('+', 42, COLOR_AMARILLO);
    } else {
        barra('~', 42, COLOR_ROJO);
        printf(NEGRITA COLOR_ROJO "  ~~~ Necesitas practicar mas. No te rindas!\n" COLOR_RESET);
        barra('~', 42, COLOR_ROJO);
    }

    printf("\n" COLOR_CYAN "  Hasta la proxima! :)\n" COLOR_RESET);
    barra('#', 42, COLOR_MAGENTA);
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
 * 3. CODIGOS ANSI DE COLOR:
 *    - \033[31m = rojo,  \033[32m = verde, \033[33m = amarillo
 *    - \033[35m = magenta, \033[36m = cyan, \033[97m = blanco brillante
 *    - \033[1m  = negrita, \033[0m = reset
 *    - Funcionan en terminales Linux/macOS y Windows 10+ (cmd/PowerShell)
 *
 * 4. BARRA DE PROGRESO Y VISUALIZACION:
 *    - (#) verde = pregunta ya respondida
 *    - (>) amarillo = pregunta actual
 *    - (.) blanco = pregunta pendiente
 *    - El numero de pregunta aparece en su propia linea separada
 *    - SUMA: asteriscos verdes (grupo A) + asteriscos amarillos (grupo B)
 *    - RESTA: asteriscos cyan (los que quedan) + 'x' rojos (los que se quitan)
 *    - La operacion matematica se imprime sola en linea destacada debajo
 *
 * 5. LOGICA DE VICTORIA POR TANDA:
 *    - aciertos >= PUNTAJE_PARA_GANAR => gana la tanda
 *    - Ajusta PUNTAJE_PARA_GANAR segun dificultad deseada
 *
 * 6. RESUMEN FINAL:
 *    - Calcula porcentaje global entre todas las tandas
 *    - Mensaje motivacional segun rendimiento (>=80%, >=60%, <60%)
 */
