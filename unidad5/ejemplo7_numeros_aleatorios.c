/*
================================================================================
  UNIDAD 5: PROGRAMACIÓN ESTRUCTURADA
  Ejemplo 7: Números Aleatorios con rand()
  Profesor: José Alfredo Sánchez
================================================================================

OBJETIVO:
  Demostrar el uso de la función rand() para generar números aleatorios.
  Aplicaciones: saludos aleatorios, simulación de dados, juegos, etc.

PROBLEMA:
  Crear un programa que:
  1. Muestre un saludo aleatorio al usuario
  2. Simule el lanzamiento de un dado (valores 1-6)
  3. Genere respuestas aleatorias a preguntas

CONCEPTOS DEMOSTRADOS:
  - Función rand() para generar números aleatorios
  - Función srand() para inicializar la semilla
  - Uso de time() para semilla basada en tiempo
  - Operador módulo (%) para limitar rangos
  - Estructura switch para selección múltiple
  - Aplicaciones prácticas de números aleatorios

================================================================================
*/

#include <stdio.h>
#include <stdlib.h>  /* Para rand() y srand() */
#include <time.h>    /* Para time() */

int main() {
    int opcion;
    int numero_aleatorio;
    int dado;
    char continuar;
    
    /* Inicializar generador de números aleatorios con semilla basada en tiempo */
    srand(time(NULL));
    
    /* Generar saludo aleatorio */
    numero_aleatorio = rand() % 5;  /* Genera número entre 0 y 4 */
    
    printf("================================================================================\n");
    printf("  GENERADOR DE NUMEROS ALEATORIOS\n");
    printf("================================================================================\n\n");
    
    /* Saludo aleatorio usando switch */
    switch(numero_aleatorio) {
        case 0:
            printf("¡Hola! Bienvenido al programa.\n");
            break;
        case 1:
            printf("¡Saludos! Es un placer tenerte aqui.\n");
            break;
        case 2:
            printf("¡Buenos dias! Que tengas un excelente dia.\n");
            break;
        case 3:
            printf("¡Hola amigo! Listo para comenzar.\n");
            break;
        case 4:
            printf("¡Bienvenido! Espero que disfrutes este programa.\n");
            break;
    }
    
    printf("\n");
    
    /* Menú principal */
    do {
        printf("================================================================================\n");
        printf("  MENU PRINCIPAL\n");
        printf("================================================================================\n");
        printf("1. Lanzar un dado (1-6)\n");
        printf("2. Obtener respuesta aleatoria (Si/No/Tal vez)\n");
        printf("3. Generar numero de loteria (1-100)\n");
        printf("4. Salir\n");
        printf("\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        printf("\n");
        
        switch(opcion) {
            case 1:
                /* Simular lanzamiento de dado */
                printf("--- LANZAMIENTO DE DADO ---\n");
                printf("Lanzando el dado");
                
                /* Efecto visual de lanzamiento */
                printf(".");
                fflush(stdout);
                
                printf(".");
                fflush(stdout);
                
                printf(".\n");
                
                /* Generar número entre 1 y 6 */
                dado = (rand() % 6) + 1;
                
                printf("\n");
                printf("  ___________\n");
                printf(" |           |\n");
                printf(" |     %d     |\n", dado);
                printf(" |___________|\n");
                printf("\n");
                printf("¡El dado muestra: %d!\n", dado);
                
                /* Mensaje según el resultado */
                if (dado == 6) {
                    printf("¡Excelente! Sacaste el numero mas alto.\n");
                } else if (dado == 1) {
                    printf("Mala suerte, sacaste el numero mas bajo.\n");
                } else {
                    printf("Resultado moderado.\n");
                }
                break;
                
            case 2:
                /* Respuesta aleatoria tipo oráculo */
                printf("--- ORACULO DE RESPUESTAS ---\n");
                printf("Haz una pregunta de Si/No en tu mente...\n");
                printf("Presiona Enter para obtener la respuesta...");
                getchar();  /* Limpiar buffer */
                getchar();  /* Esperar Enter */
                
                numero_aleatorio = rand() % 10;  /* 0-9 */
                
                printf("\n");
                printf("Consultando el oraculo");
                printf(".");
                fflush(stdout);
                printf(".");
                fflush(stdout);
                printf(".\n\n");
                
                /* Diferentes respuestas con probabilidades */
                if (numero_aleatorio < 4) {
                    /* 40% probabilidad */
                    printf("Respuesta: SI\n");
                } else if (numero_aleatorio < 7) {
                    /* 30% probabilidad */
                    printf("Respuesta: NO\n");
                } else if (numero_aleatorio < 9) {
                    /* 20% probabilidad */
                    printf("Respuesta: TAL VEZ\n");
                } else {
                    /* 10% probabilidad */
                    printf("Respuesta: PREGUNTA DE NUEVO MAS TARDE\n");
                }
                break;
                
            case 3:
                /* Número de lotería */
                printf("--- GENERADOR DE NUMERO DE LOTERIA ---\n");
                printf("Generando tu numero de la suerte");
                printf(".");
                fflush(stdout);
                printf(".");
                fflush(stdout);
                printf(".\n\n");
                
                /* Generar número entre 1 y 100 */
                numero_aleatorio = (rand() % 100) + 1;
                
                printf("  **********************\n");
                printf("  *                    *\n");
                printf("  *   Tu numero es:    *\n");
                printf("  *                    *\n");
                printf("  *        %3d         *\n", numero_aleatorio);
                printf("  *                    *\n");
                printf("  **********************\n");
                printf("\n");
                printf("¡Buena suerte!\n");
                break;
                
            case 4:
                /* Despedida aleatoria */
                numero_aleatorio = rand() % 4;
                printf("--- DESPEDIDA ---\n");
                switch(numero_aleatorio) {
                    case 0:
                        printf("¡Hasta luego! Vuelve pronto.\n");
                        break;
                    case 1:
                        printf("¡Adios! Que tengas un excelente dia.\n");
                        break;
                    case 2:
                        printf("¡Nos vemos! Gracias por usar el programa.\n");
                        break;
                    case 3:
                        printf("¡Hasta la proxima! Cuidate.\n");
                        break;
                }
                break;
                
            default:
                printf("Opcion invalida. Por favor seleccione 1-4.\n");
        }
        
        printf("\n");
        
        if (opcion != 4) {
            printf("¿Desea continuar? (s/n): ");
            scanf(" %c", &continuar);
            printf("\n");
        }
        
    } while (opcion != 4 && (continuar == 's' || continuar == 'S'));
    
    printf("================================================================================\n");
    printf("  PROGRAMA FINALIZADO\n");
    printf("================================================================================\n");
    
    return 0;
}

/*
================================================================================
NOTAS TÉCNICAS SOBRE rand()
================================================================================

1. FUNCIÓN rand():
   - Genera números pseudoaleatorios entre 0 y RAND_MAX
   - RAND_MAX es típicamente 32767
   - Sintaxis: int numero = rand();

2. FUNCIÓN srand():
   - Inicializa la semilla del generador
   - Sin srand(), rand() genera la misma secuencia cada vez
   - Sintaxis: srand(semilla);

3. USO DE time(NULL):
   - time(NULL) devuelve segundos desde 1/1/1970
   - Cambia cada segundo, generando diferentes secuencias
   - Sintaxis: srand(time(NULL));

4. LIMITAR RANGO CON MÓDULO:
   - Para 0 a N-1: rand() % N
   - Para 1 a N: (rand() % N) + 1
   - Para MIN a MAX: (rand() % (MAX - MIN + 1)) + MIN

EJEMPLOS:
  - Dado (1-6): (rand() % 6) + 1
  - Moneda (0-1): rand() % 2
  - Lotería (1-100): (rand() % 100) + 1

================================================================================
COMPILACIÓN Y EJECUCIÓN
================================================================================

Compilar con GCC:
  gcc ejemplo7_numeros_aleatorios.c -o ejemplo7
  ./ejemplo7

En Windows con MinGW:
  gcc ejemplo7_numeros_aleatorios.c -o ejemplo7.exe
  ejemplo7.exe

================================================================================
CASOS DE USO DE NÚMEROS ALEATORIOS
================================================================================

1. JUEGOS:
   - Dados, cartas, ruleta
   - Generación de enemigos
   - Eventos aleatorios

2. SIMULACIONES:
   - Modelado de eventos probabilísticos
   - Pruebas estadísticas
   - Análisis de Monte Carlo

3. SEGURIDAD:
   - Generación de contraseñas
   - Tokens de sesión
   - Captchas

4. ENTRETENIMIENTO:
   - Frases aleatorias
   - Selección aleatoria
   - Sorteos

================================================================================
EJERCICIOS PROPUESTOS
================================================================================

1. Modificar para simular lanzamiento de 2 dados y sumar resultados
2. Crear un juego de "adivina el número" (1-100)
3. Generar una contraseña aleatoria de 8 caracteres
4. Simular 1000 lanzamientos de moneda y contar caras/cruces
5. Crear un generador de nombres aleatorios

================================================================================
*/
