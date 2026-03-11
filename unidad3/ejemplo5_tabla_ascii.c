/*
 * UNIDAD 3: DATOS Y ENTIDADES PRIMITIVAS
 * Ejemplo 5: Tabla ASCII
 * 
 * OBJETIVO:
 * Mostrar la tabla ASCII extendida completa (caracteres del 0 al 255) para comprender
 * la relación entre valores numéricos y caracteres, así como el uso de 
 * variables de tipo char e int.
 *
 * CONCEPTOS CLAVE:
 * - Tipo de dato char
 * - Conversión entre int y char
 * - Códigos ASCII
 * - Caracteres imprimibles y no imprimibles
 * - Ciclo for (estructura iterativa)
 * 
 * Compilación: gcc ejemplo5_tabla_ascii.c -o tabla_ascii
 * Ejecución: ./tabla_ascii
 */

#include <stdio.h>

int main() {
    // DECLARACIÓN DE VARIABLES
    int codigo;
    char caracter;
    
    // MOSTRAR ENCABEZADO
    printf("=== TABLA ASCII COMPLETA ===\n");
    printf("Codigo | Caracter | Descripcion\n");
    printf("-------|----------|------------\n");
    
    // GENERAR TABLA ASCII EXTENDIDA (0-255)
    for (codigo = 0; codigo <= 255; codigo++) {
        caracter = (char)codigo;  // Conversión explícita int a char
        
        if (codigo >= 32 && codigo <= 126) {
            // Caracteres ASCII imprimibles
            printf("%6d | %8c | ASCII imprimible\n", codigo, caracter);
        } else if (codigo >= 128 && codigo <= 255) {
            // Caracteres ASCII extendido
            printf("%6d | %8c | ASCII extendido\n", codigo, caracter);
        } else {
            // Caracteres de control
            switch (codigo) {
                case 0:
                    printf("%6d | %8s | Caracter nulo\n", codigo, "NUL");
                    break;
                case 7:
                    printf("%6d | %8s | Campana (beep)\n", codigo, "BEL");
                    break;
                case 8:
                    printf("%6d | %8s | Retroceso\n", codigo, "BS");
                    break;
                case 9:
                    printf("%6d | %8s | Tabulacion\n", codigo, "TAB");
                    break;
                case 10:
                    printf("%6d | %8s | Nueva linea\n", codigo, "LF");
                    break;
                case 13:
                    printf("%6d | %8s | Retorno de carro\n", codigo, "CR");
                    break;
                case 27:
                    printf("%6d | %8s | Escape\n", codigo, "ESC");
                    break;
                case 127:
                    printf("%6d | %8s | Eliminar\n", codigo, "DEL");
                    break;
                default:
                    printf("%6d | %8s | Control\n", codigo, "---");
                    break;
            }
        }
    }
    
    // MOSTRAR INFORMACIÓN ADICIONAL
    printf("\n=== INFORMACION ADICIONAL ===\n");
    printf("• ASCII estandar: 0-127 (128 caracteres)\n");
    printf("• ASCII extendido: 128-255 (128 caracteres adicionales)\n");
    printf("• Total de caracteres: 0-255 (256 caracteres)\n");
    printf("• Caracteres imprimibles: 32-126 (95 caracteres)\n");
    printf("• Caracteres de control: 0-31 y 127 (33 caracteres)\n");
    printf("• Digitos: 48-57 ('0'-'9')\n");
    printf("• Letras mayusculas: 65-90 ('A'-'Z')\n");
    printf("• Letras minusculas: 97-122 ('a'-'z')\n");
    
   
    // EJEMPLOS PRÁCTICOS DE CONVERSIÓN
    printf("\n=== EJEMPLOS DE CONVERSION ===\n");
    printf("Caracter 'A' = codigo %d\n", 'A');
    printf("Caracter 'a' = codigo %d\n", 'a');
    printf("Caracter '0' = codigo %d\n", '0');
    printf("Caracter '9' = codigo %d\n", '9');
    printf("Codigo 65 = caracter '%c'\n", 65);
    printf("Codigo 97 = caracter '%c'\n", 97);
    printf("Codigo 48 = caracter '%c'\n", 48);
    
    // DEMOSTRACIÓN DE ARITMÉTICA CON CARACTERES
    printf("\n=== ARITMETICA CON CARACTERES ===\n");
    char letra = 'A';
    printf("Letra inicial: %c (codigo %d)\n", letra, letra);
    letra = letra + 1;  // Incrementar código ASCII
    printf("Siguiente letra: %c (codigo %d)\n", letra, letra);
    
    // Convertir mayúscula a minúscula
    char mayuscula = 'M';
    char minuscula = mayuscula + 32;  // Diferencia entre 'A' y 'a' es 32
    printf("Mayuscula '%c' -> Minuscula '%c' (sumar 32)\n", mayuscula, minuscula);

    // VISTA COMPACTA EN COLUMNAS
    printf("\n=== VISTA COMPACTA (CARACTERES IMPRIMIBLES) ===\n");
    
    // Mostrar en formato de 8 columnas
    for (int fila = 0; fila < 32; fila++) {
        for (int columna = 0; columna < 8; columna++) {
            codigo = 32 + fila + (columna * 32);
            if (codigo <= 255) {
                caracter = (char)codigo;
                if ((codigo >= 32 && codigo <= 126) || (codigo >= 128 && codigo <= 255)) {
                    printf("%3d %c | ", codigo, caracter);
                } else {
                    printf("--- - | ");
                }
            } 
        }
        printf("\n");
    }
       

    return 0;
}

/*
 * NOTAS TÉCNICAS:
 * 
 * 1. CONVERSIÓN DE TIPOS:
 *    - (char)codigo: Convierte entero a carácter
 *    - 'A': Literal de carácter (equivale al código 65)
 *    - printf("%c", numero): Imprime número como carácter
 *    - printf("%d", caracter): Imprime carácter como número
 * 
 * 2. RANGOS ASCII IMPORTANTES:
 *    - 0-31: Caracteres de control (no imprimibles)
 *    - 32: Espacio
 *    - 33-47: Símbolos (!@#$%^&*()...)
 *    - 48-57: Dígitos (0-9)
 *    - 58-64: Más símbolos (:;<=>?@)
 *    - 65-90: Letras mayúsculas (A-Z)
 *    - 91-96: Más símbolos ([\]^_`)
 *    - 97-122: Letras minúsculas (a-z)
 *    - 123-126: Símbolos finales ({|}~)
 *    - 127: DEL (eliminar)
 *    - 128-255: ASCII extendido (caracteres especiales, acentos, símbolos)
 * 
 * 3. APLICACIONES PRÁCTICAS:
 *    - Validación de entrada de datos
 *    - Conversión entre mayúsculas y minúsculas
 *    - Cifrado simple (César, ROT13)
 *    - Análisis de texto
 *    - Generación de contraseñas
 */