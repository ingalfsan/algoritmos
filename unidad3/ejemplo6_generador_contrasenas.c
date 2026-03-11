/*
 * UNIDAD 3: DATOS Y ENTIDADES PRIMITIVAS
 * Ejemplo 6: Generador de Contraseñas Aleatorias
 * 
 * OBJETIVO:
 * Generar contraseñas aleatorias utilizando códigos ASCII,
 * demostrando el uso de números aleatorios, conversión de tipos y 
 * manipulación de caracteres.
 *
 * CONCEPTOS CLAVE:
 * - Números aleatorios (rand(), srand())
 * - Tipo de dato char
 * - Conversión entre int y char
 * - Códigos ASCII
 * - Arrays de caracteres (cadenas)
 * - Constantes (#define)
 * - Validación de rangos
 * 
 * Compilación: gcc ejemplo6_generador_contrasenas.c -o generador_contrasenas.exe
 * Ejecución: ./generador_contrasenas.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// CONSTANTES
#define LONGITUD_CONTRASENA 20
#define TAMANIO_BUFFER (LONGITUD_CONTRASENA + 1)

int main() {
    // DECLARACIÓN DE VARIABLES
    char contrasena[TAMANIO_BUFFER];
    int i, codigo_ascii, opcion, tipo;
    int min_ascii, max_ascii;
    char respuesta;
    
    // INICIALIZAR GENERADOR DE NÚMEROS ALEATORIOS
    srand(time(NULL));
    
    // MOSTRAR MENÚ DE OPCIONES
    printf("=== GENERADOR DE CONTRASENAS ALEATORIAS ===\n");
    printf("Seleccione el tipo de contrasena:\n");
    printf("1. Solo letras (A-Z, a-z)\n");
    printf("2. Letras y numeros (A-Z, a-z, 0-9)\n");
    printf("3. Completa (letras, numeros y simbolos)\n");
    printf("4. Solo numeros\n");
    printf("5. Personalizada (rango ASCII especifico)\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    
    // GENERAR CONTRASEÑA SEGÚN LA OPCIÓN
    switch (opcion) {
        case 1:
            // Solo letras (A-Z: 65-90, a-z: 97-122)
            for (i = 0; i < LONGITUD_CONTRASENA; i++) {
                if (rand() % 2 == 0) {
                    codigo_ascii = 65 + rand() % 26;   // Mayúsculas (A-Z)
                } else {
                    codigo_ascii = 97 + rand() % 26;   // Minúsculas (a-z)
                }
                contrasena[i] = (char)codigo_ascii;
            }
            break;
            
        case 2:
            // Letras y números (A-Z, a-z, 0-9)
            for (i = 0; i < LONGITUD_CONTRASENA; i++) {
                tipo = 1 + rand() % 3;  // 1, 2 o 3
                switch (tipo) {
                    case 1: codigo_ascii = 65 + rand() % 26; break;  // Mayúsculas
                    case 2: codigo_ascii = 97 + rand() % 26; break;  // Minúsculas
                    case 3: codigo_ascii = 48 + rand() % 10; break;  // Números
                }
                contrasena[i] = (char)codigo_ascii;
            }
            break;
            
        case 3:
            // Completa (caracteres imprimibles: 33-126)
            for (i = 0; i < LONGITUD_CONTRASENA; i++) {
                codigo_ascii = 33 + rand() % 94;  // 33 a 126 (94 caracteres)
                contrasena[i] = (char)codigo_ascii;
            }
            break;
            
        case 4:
            // Solo números (0-9: 48-57)
            for (i = 0; i < LONGITUD_CONTRASENA; i++) {
                codigo_ascii = 48 + rand() % 10;  // 48 a 57
                contrasena[i] = (char)codigo_ascii;
            }
            break;
            
        case 5:
            // Personalizada
            printf("Ingrese codigo ASCII minimo (33-126): ");
            scanf("%d", &min_ascii);
            printf("Ingrese codigo ASCII maximo (33-126): ");
            scanf("%d", &max_ascii);
            
            // Validar rangos
            if (min_ascii < 33) min_ascii = 33;
            if (max_ascii > 126) max_ascii = 126;
            if (min_ascii > max_ascii) {
                int temp = min_ascii;
                min_ascii = max_ascii;
                max_ascii = temp;
            }
            
            for (i = 0; i < LONGITUD_CONTRASENA; i++) {
                codigo_ascii = min_ascii + rand() % (max_ascii - min_ascii + 1);
                contrasena[i] = (char)codigo_ascii;
            }
            break;
            
        default:
            printf("Opcion invalida. Generando contrasena completa...\n");
            for (i = 0; i < LONGITUD_CONTRASENA; i++) {
                codigo_ascii = 33 + rand() % 94;
                contrasena[i] = (char)codigo_ascii;
            }
            break;
    }
    
    // AGREGAR TERMINADOR NULO
    contrasena[LONGITUD_CONTRASENA] = '\0';
    
    // MOSTRAR RESULTADO
    printf("\n=== CONTRASENA GENERADA ===\n");
    printf("Contrasena: %s\n", contrasena);
    printf("Longitud: %d caracteres\n", LONGITUD_CONTRASENA);
    
    return 0;
}

/*
 * NOTAS TÉCNICAS:
 * 
 * 1. CONSTANTES (#define):
 *    - LONGITUD_CONTRASENA: Define la longitud de la contraseña (10 caracteres)
 *    - TAMANIO_BUFFER: Tamaño del array (longitud + 1 para terminador nulo)
 *    - Facilita cambiar la longitud en un solo lugar
 * 
 * 2. GENERACIÓN DE NÚMEROS ALEATORIOS:
 *    - srand(time(NULL)): Inicializa con semilla basada en tiempo actual
 *    - rand() % n: Genera número entre 0 y n-1
 *    - min + rand() % (max-min+1): Genera número entre min y max
 * 
 * 3. RANGOS ASCII UTILIZADOS:
 *    - Números: 48-57 ('0'-'9')
 *    - Mayúsculas: 65-90 ('A'-'Z')
 *    - Minúsculas: 97-122 ('a'-'z')
 *    - Símbolos: 33-47, 58-64, 91-96, 123-126
 *    - Imprimibles: 33-126 (excluyendo espacio)
 * 
 * 4. EVALUACIÓN DE FORTALEZA:
 *    - Débil: Solo un tipo de carácter
 *    - Regular: Dos tipos de caracteres
 *    - Buena: Tres tipos de caracteres
 *    - Excelente: Todos los tipos (números, mayúsculas, minúsculas, símbolos)
 * 
 * 5. APLICACIONES PRÁCTICAS:
 *    - Sistemas de registro de usuarios
 *    - Generación automática de contraseñas temporales
 *    - Herramientas de seguridad
 *    - Validación de políticas de contraseñas
 * 
 * 6. MEJORAS POSIBLES:
 *    - Longitud variable de contraseña (parámetro del usuario)
 *    - Exclusión de caracteres ambiguos (0, O, l, 1)
 *    - Garantizar al menos un carácter de cada tipo
 *    - Guardado en archivo
 *    - Interfaz gráfica
 */
