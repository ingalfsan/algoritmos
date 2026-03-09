/*
================================================================================
  UNIDAD 3: DATOS Y ENTIDADES PRIMITIVAS
  Ejemplo 4: Desbordamiento de Enteros (Overflow)
  Profesor: José Alfredo Sánchez
================================================================================

OBJETIVO:
  Demostrar qué ocurre cuando el resultado de una operación excede la 
  capacidad de almacenamiento del tipo de dato utilizado.

PROBLEMA:
  Calcular el salario semanal: días trabajados × sueldo diario
  Ejemplo: 5 días × 7000 Bs = 35000 Bs (excede el límite de short int: 32767)

CONCEPTOS DEMOSTRADOS:
  - Desbordamiento de enteros (overflow)
  - Diferencias entre short int, int y long int
  - Importancia de elegir el tipo de dato correcto
  - Límites de representación numérica

================================================================================
*/

#include <stdio.h>
#include <limits.h>  /* Para mostrar límites de tipos de datos */

int main() {
    /* Declaración de variables */
    int dias_trabajados;
    int sueldo_diario;
    short int salario_incorrecto;  /* 16 bits: -32768 a 32767 */
    long int salario_correcto;     /* 32+ bits: rango mucho mayor */
    
    /* Mostrar información sobre límites de tipos de datos */
    printf("================================================================================\n");
    printf("  CALCULO DE SALARIO SEMANAL - Demostracion de Overflow\n");
    printf("================================================================================\n\n");
    
    printf("Limites de tipos de datos en este sistema:\n");
    printf("  short int: %d a %d\n", SHRT_MIN, SHRT_MAX);
    printf("  int:       %d a %d\n", INT_MIN, INT_MAX);
    printf("  long int:  %ld a %ld\n", LONG_MIN, LONG_MAX);
    printf("\n");
    
    /* Entrada de datos */
    printf("=== INGRESO DE DATOS ===\n");
    printf("Ingrese cantidad de dias trabajados: ");
    scanf("%d", &dias_trabajados);
    
    printf("Ingrese sueldo diario (Bs): ");
    scanf("%d", &sueldo_diario);
    
    /* Proceso: Cálculo con tipo de dato INSUFICIENTE (short int) */
    salario_incorrecto = dias_trabajados * sueldo_diario;
    
    /* Proceso: Cálculo con tipo de dato ADECUADO (long int) */
    salario_correcto = (long int)dias_trabajados * sueldo_diario;
    
    /* Salida de resultados */
    printf("\n");
    printf("================================================================================\n");
    printf("  RESULTADOS\n");
    printf("================================================================================\n");
    printf("Dias trabajados: %d\n", dias_trabajados);
    printf("Sueldo diario:   Bs %d\n", sueldo_diario);
    printf("\n");
    
    printf("--- Comparacion de tipos de datos ---\n");
    printf("Usando short int: Bs %d  ", salario_incorrecto);
    if (salario_incorrecto < 0 && dias_trabajados > 0 && sueldo_diario > 0) {
        printf("<-- ¡INCORRECTO! (Overflow)\n");
    } else {
        printf("\n");
    }
    
    printf("Usando long int:  Bs %ld  <-- CORRECTO\n", salario_correcto);
    
    /* Explicación del problema si hay overflow */
    if (salario_incorrecto < 0 && dias_trabajados > 0 && sueldo_diario > 0) {
        printf("\n");
        printf("================================================================================\n");
        printf("  ¡ADVERTENCIA! DESBORDAMIENTO DETECTADO\n");
        printf("================================================================================\n");
        printf("El resultado (%ld) excede la capacidad de short int (maximo: %d).\n", 
               salario_correcto, SHRT_MAX);
        printf("\n");
        printf("Explicacion:\n");
        printf("  - short int usa 16 bits con signo\n");
        printf("  - Rango: -32768 a 32767\n");
        printf("  - Cuando el resultado excede 32767, ocurre un 'overflow'\n");
        printf("  - Los bits se desbordan y el numero se interpreta incorrectamente\n");
        printf("\n");
        printf("Solucion:\n");
        printf("  - Use 'int' o 'long int' para valores grandes\n");
        printf("  - Siempre considere el rango de valores esperado\n");
        printf("  - Para calculos monetarios, prefiera tipos de datos grandes\n");
    }
    
    printf("\n");
    printf("================================================================================\n");
    printf("  LECCION APRENDIDA\n");
    printf("================================================================================\n");
    printf("Siempre elija el tipo de dato apropiado segun el rango de valores esperado.\n");
    printf("Para calculos de nomina o valores grandes, use 'int' o 'long int'.\n");
    printf("================================================================================\n");
    
    return 0;
}

/*
================================================================================
NOTAS DE COMPILACION Y EJECUCION
================================================================================

Compilar con GCC:
  gcc ejemplo4_desbordamiento_enteros.c -o ejemplo4
  ./ejemplo4

En Windows con MinGW:
  gcc ejemplo4_desbordamiento_enteros.c -o ejemplo4.exe
  ejemplo4.exe

================================================================================
CASOS DE PRUEBA SUGERIDOS
================================================================================

Caso 1 (Sin overflow):
  Dias: 3
  Sueldo: 5000
  Resultado: 15000 (dentro del rango de short int)

Caso 2 (Con overflow - DEMOSTRACIÓN PRINCIPAL):
  Dias: 5
  Sueldo: 7000
  Resultado: 35000 (excede short int, muestra overflow)

Caso 3 (Overflow extremo):
  Dias: 7
  Sueldo: 10000
  Resultado: 70000 (excede aún más el límite)

================================================================================
SALIDA ESPERADA (Caso 2: 5 días × 7000 Bs)
================================================================================

Limites de tipos de datos en este sistema:
  short int: -32768 a 32767
  int:       -2147483648 a 2147483647
  long int:  -2147483648 a 2147483647

=== INGRESO DE DATOS ===
Ingrese cantidad de dias trabajados: 5
Ingrese sueldo diario (Bs): 7000

================================================================================
  RESULTADOS
================================================================================
Dias trabajados: 5
Sueldo diario:   Bs 7000

--- Comparacion de tipos de datos ---
Usando short int: Bs -30536  <-- ¡INCORRECTO! (Overflow)
Usando long int:  Bs 35000  <-- CORRECTO

================================================================================
  ¡ADVERTENCIA! DESBORDAMIENTO DETECTADO
================================================================================
El resultado (35000) excede la capacidad de short int (maximo: 32767).

Explicacion:
  - short int usa 16 bits con signo
  - Rango: -32768 a 32767
  - Cuando el resultado excede 32767, ocurre un 'overflow'
  - Los bits se desbordan y el numero se interpreta incorrectamente

Solucion:
  - Use 'int' o 'long int' para valores grandes
  - Siempre considere el rango de valores esperado
  - Para calculos monetarios, prefiera tipos de datos grandes

================================================================================
*/
