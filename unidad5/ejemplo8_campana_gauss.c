/*
================================================================================
  UNIDAD 5: PROGRAMACIÓN ESTRUCTURADA
  Ejemplo 8: Campana de Gauss - Tabla de Galton (Quincunx)
  Profesor: José Alfredo Sánchez
================================================================================

OBJETIVO:
  Demostrar la distribución normal (campana de Gauss) simulando el experimento
  de la Tabla de Galton, donde "bolitas" caen a través de clavos y se 
  distribuyen formando una campana. La gráfica se construye en tiempo real.

PROBLEMA:
  Simular 200 bolitas cayendo a través de 10 niveles de clavos. En cada nivel,
  la bolita tiene 50% de probabilidad de ir a la izquierda o derecha.
  Al final, las bolitas se acumulan en columnas formando la campana de Gauss.

CONCEPTOS DEMOSTRADOS:
  - Simulación del experimento de Galton (tabla con clavos)
  - Distribución binomial que aproxima la normal
  - Construcción incremental de histograma
  - Visualización dinámica con asteriscos
  - Probabilidad y estadística básica

EXPERIMENTO DE GALTON:
  Cada bolita cae por 10 niveles de clavos. En cada clavo:
  - 50% probabilidad de ir a la IZQUIERDA (0)
  - 50% probabilidad de ir a la DERECHA (1)
  
  Posición final = suma de decisiones (0 a 10)
  Esto genera una distribución binomial que aproxima la normal.

================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constantes para la simulación */
#define NUM_BOLITAS 200      /* Cantidad de bolitas a simular */
#define NUM_NIVELES 10       /* Niveles de clavos (altura de la tabla) */
#define NUM_COLUMNAS 11      /* Columnas posibles (0 a NUM_NIVELES) */
#define PAUSA_MS 50          /* Milisegundos de pausa entre bolitas */

/* Función para hacer una pausa (multiplataforma simplificada) */
void pausa_corta() {
    int i, j;
    /* Bucle de espera simple (no preciso pero funcional) */
    for (i = 0; i < 1000000; i++) {
        j = i * 2;  /* Operación simple para evitar optimización */
    }
}

/* Función para limpiar pantalla (multiplataforma) */
void limpiar_pantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/* Función para dibujar la tabla de Galton y el histograma actual */
void dibujar_tabla_galton(int columnas[], int bolita_actual, int max_altura) {
    int i, j, nivel;
    
    limpiar_pantalla();
    
    printf("================================================================================\n");
    printf("  TABLA DE GALTON - SIMULACION DE CAMPANA DE GAUSS\n");
    printf("  Bolita: %d / %d\n", bolita_actual, NUM_BOLITAS);
    printf("================================================================================\n\n");
    
    /* Dibujar la tabla de clavos */
    printf("                    TABLA DE CLAVOS\n");
    printf("                    --------------\n\n");
    
    for (nivel = 0; nivel < NUM_NIVELES; nivel++) {
        /* Espacios iniciales para centrar */
        for (i = 0; i < (NUM_NIVELES - nivel); i++) {
            printf(" ");
        }
        
        /* Dibujar clavos del nivel */
        for (i = 0; i <= nivel; i++) {
            printf("o ");
        }
        printf("\n");
    }
    
    printf("\n");
    printf("  |");
    for (i = 0; i < NUM_COLUMNAS; i++) {
        printf("==");
    }
    printf("|\n");
    
    /* Dibujar histograma (columnas de bolitas acumuladas) */
    /* Encontrar altura máxima actual */
    int altura_max_actual = 0;
    for (i = 0; i < NUM_COLUMNAS; i++) {
        if (columnas[i] > altura_max_actual) {
            altura_max_actual = columnas[i];
        }
    }
    
    /* Dibujar de arriba hacia abajo */
    for (nivel = max_altura; nivel > 0; nivel--) {
        printf("  |");
        for (i = 0; i < NUM_COLUMNAS; i++) {
            if (columnas[i] >= nivel) {
                printf("**");
            } else {
                printf("  ");
            }
        }
        printf("|\n");
    }
    
    /* Base del histograma */
    printf("  |");
    for (i = 0; i < NUM_COLUMNAS; i++) {
        printf("==");
    }
    printf("|\n");
    
    /* Números de columna */
    printf("   ");
    for (i = 0; i < NUM_COLUMNAS; i++) {
        printf("%2d", i);
    }
    printf("\n\n");
    
    /* Mostrar conteo de cada columna */
    printf("Distribucion actual:\n");
    for (i = 0; i < NUM_COLUMNAS; i++) {
        printf("Col %2d: %3d bolitas\n", i, columnas[i]);
    }
}

int main() {
    int columnas[NUM_COLUMNAS];
    int i, j, bolita;
    int posicion;
    int decision;
    int max_altura = 20;  /* Altura máxima del histograma visual */
    double suma_posiciones = 0.0;
    double promedio;
    
    /* Inicializar columnas */
    for (i = 0; i < NUM_COLUMNAS; i++) {
        columnas[i] = 0;
    }
    
    /* Inicializar generador de números aleatorios */
    srand(time(NULL));
    
    printf("================================================================================\n");
    printf("  EXPERIMENTO DE LA TABLA DE GALTON (QUINCUNX)\n");
    printf("================================================================================\n\n");
    printf("Este experimento demuestra como la suma de eventos aleatorios\n");
    printf("independientes genera una distribucion normal (campana de Gauss).\n\n");
    printf("Cada bolita cae por %d niveles de clavos.\n", NUM_NIVELES);
    printf("En cada clavo, tiene 50%% de probabilidad de ir a izquierda o derecha.\n\n");
    printf("Presione Enter para comenzar la simulacion...");
    getchar();
    
    /* Simular cada bolita */
    for (bolita = 1; bolita <= NUM_BOLITAS; bolita++) {
        /* Cada bolita comienza en posición 0 */
        posicion = 0;
        
        /* La bolita cae por NUM_NIVELES niveles */
        for (i = 0; i < NUM_NIVELES; i++) {
            /* Decisión aleatoria: 0 = izquierda, 1 = derecha */
            decision = rand() % 2;
            posicion += decision;
        }
        
        /* La bolita cae en la columna 'posicion' (0 a NUM_NIVELES) */
        columnas[posicion]++;
        suma_posiciones += posicion;
        
        /* Dibujar estado actual cada 5 bolitas o en la última */
        if (bolita % 5 == 0 || bolita == NUM_BOLITAS) {
            dibujar_tabla_galton(columnas, bolita, max_altura);
            
            /* Pausa para ver la animación */
            if (bolita < NUM_BOLITAS) {
                pausa_corta();
            }
        }
    }
    
    /* Calcular estadísticas finales */
    promedio = suma_posiciones / NUM_BOLITAS;
    
    /* Pantalla final con análisis */
    printf("\n");
    printf("================================================================================\n");
    printf("  ANALISIS FINAL\n");
    printf("================================================================================\n");
    printf("Total de bolitas:        %d\n", NUM_BOLITAS);
    printf("Niveles de clavos:       %d\n", NUM_NIVELES);
    printf("Posicion promedio:       %.2f\n", promedio);
    printf("Posicion teorica:        %.1f (centro)\n", NUM_NIVELES / 2.0);
    printf("\n");
    
    /* Encontrar la columna con más bolitas (moda) */
    int max_bolitas = 0;
    int columna_max = 0;
    for (i = 0; i < NUM_COLUMNAS; i++) {
        if (columnas[i] > max_bolitas) {
            max_bolitas = columnas[i];
            columna_max = i;
        }
    }
    
    printf("Columna con mas bolitas: %d (con %d bolitas)\n", columna_max, max_bolitas);
    printf("\n");
    
    /* Explicación del fenómeno */
    printf("================================================================================\n");
    printf("  ¿POR QUE SE FORMA LA CAMPANA DE GAUSS?\n");
    printf("================================================================================\n");
    printf("Cada bolita toma %d decisiones aleatorias (izquierda/derecha).\n", NUM_NIVELES);
    printf("\n");
    printf("Formas de llegar a cada columna:\n");
    printf("  - Columna 0:  Todas las decisiones a la izquierda (1 forma)\n");
    printf("  - Columna 5:  5 izquierdas y 5 derechas (252 formas)\n");
    printf("  - Columna 10: Todas las decisiones a la derecha (1 forma)\n");
    printf("\n");
    printf("Hay MUCHAS MAS formas de llegar al centro que a los extremos.\n");
    printf("Por eso, la mayoria de las bolitas caen en el centro.\n");
    printf("Esto es la DISTRIBUCION BINOMIAL, que aproxima la NORMAL.\n");
    printf("\n");
    
    printf("================================================================================\n");
    printf("  APLICACIONES EN LA VIDA REAL\n");
    printf("================================================================================\n");
    printf("Este mismo patron aparece en:\n");
    printf("  - Alturas de personas (suma de muchos genes)\n");
    printf("  - Calificaciones de examenes (suma de conocimientos)\n");
    printf("  - Errores de medicion (suma de pequenos errores)\n");
    printf("  - Tiempos de respuesta (suma de procesos)\n");
    printf("  - Variaciones en manufactura (suma de factores)\n");
    printf("\n");
    printf("Cuando un fenomeno es resultado de MUCHOS factores aleatorios\n");
    printf("independientes, tiende a seguir la distribucion normal.\n");
    printf("================================================================================\n");
    
    return 0;
}

/*
================================================================================
NOTAS TÉCNICAS - EXPERIMENTO DE GALTON
================================================================================

1. TABLA DE GALTON (QUINCUNX):
   - Inventada por Sir Francis Galton en 1889
   - Demuestra visualmente la distribución normal
   - Bolitas caen a través de clavos dispuestos en triángulo
   - Cada clavo desvía la bolita izquierda o derecha (50%-50%)

2. DISTRIBUCIÓN BINOMIAL:
   - Cada bolita toma n decisiones binarias (izquierda/derecha)
   - Posición final = suma de decisiones (0 a n)
   - Probabilidad de llegar a posición k: C(n,k) / 2^n
   - Ejemplo con n=10: C(10,5) = 252 formas de llegar al centro
   - Solo 1 forma de llegar a los extremos (0 o 10)

3. APROXIMACIÓN A LA NORMAL:
   - Cuando n es grande, la binomial aproxima la normal
   - Media: μ = n/2
   - Desviación estándar: σ = √(n/4)
   - Para n=10: μ=5, σ≈1.58

4. VISUALIZACIÓN DINÁMICA:
   - Actualización cada 5 bolitas para ver la construcción
   - Histograma vertical con asteriscos (**)
   - Limpieza de pantalla para efecto de animación

================================================================================
COMPILACIÓN Y EJECUCIÓN
================================================================================

Compilar con GCC:
  gcc ejemplo8_campana_gauss.c -o ejemplo8
  ./ejemplo8

En Windows con MinGW:
  gcc ejemplo8_campana_gauss.c -o ejemplo8.exe
  ejemplo8.exe

NOTA: No requiere -lm porque no usa funciones matemáticas complejas

================================================================================
EJERCICIOS PROPUESTOS
================================================================================

1. Modificar NUM_NIVELES a 15 y observar cómo mejora la aproximación
2. Cambiar la probabilidad de 50%-50% a 60%-40% (sesgo)
3. Agregar contador de bolitas en cada columna en tiempo real
4. Calcular y mostrar la desviación estándar real de los datos
5. Permitir al usuario elegir la cantidad de bolitas y niveles
6. Agregar colores usando códigos ANSI (opcional)
7. Simular dos tablas de Galton simultáneas para comparar

================================================================================
*/
