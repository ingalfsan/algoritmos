# Unidad 7: Técnicas de Mantenimiento de Programas

**Asignatura:** Algoritmos y Programación  
**Profesor:** José Alfredo Sánchez

---

## 1. Introducción al Mantenimiento de Programas

El mantenimiento de software comprende todas las actividades realizadas DESPUÉS de que un programa ha sido entregado, con el fin de:

- Corregir errores encontrados en el uso.
- Adaptarlo a nuevos requisitos o entornos.
- Mejorar su rendimiento o calidad.

### Tipos de mantenimiento:

**a) Correctivo:** Corregir errores (bugs) encontrados.  
Ejemplo: El programa calcula mal el IVA en ciertos casos.

**b) Adaptativo:** Adaptar a cambios en el entorno.  
Ejemplo: Actualizar las tasas de impuestos.

**c) Perfectivo:** Mejorar funcionalidad o rendimiento.  
Ejemplo: Agregar una nueva opción al menú.

**d) Preventivo:** Mejorar la estructura para facilitar cambios futuros.  
Ejemplo: Reorganizar el código para que sea más legible.

---

## 2. Técnica de Prueba de Caja Negra

### 2.1 Concepto

La prueba de caja negra (Black Box Testing) es una técnica de pruebas donde se verifica el comportamiento de un programa basándose SOLAMENTE en sus entradas y salidas, SIN examinar el código fuente interno.

Se le llama "caja negra" porque el interior del programa se considera opaco: no importa CÓMO funciona por dentro, solo importa QUÉ produce como resultado para cada entrada.

```
┌───────────────────┐                    ┌───────────────────┐
│                   │                    │                   │
│ Datos de Entrada  │ ──> [ PROGRAMA ] ──>│ Salida Obtenida   │
│                   │     (caja negra)   │                   │
└───────────────────┘                    └───────────────────┘
```

Se compara la "Salida Obtenida" con la "Salida Esperada".  
Si coinciden: la prueba PASA.  
Si no coinciden: se encontró un DEFECTO.

### 2.2 Tipos de casos de prueba

**a) Casos normales (valores típicos):**  
Datos de entrada comunes y esperados.  
Ejemplo: Para un programa de promedio de notas:  
Entrada: 15, 18, 12 → Salida esperada: 15.0

**b) Valores límite (boundary):**  
Probar en los extremos del rango válido.  
Ejemplo: Notas válidas de 0 a 20:
- Límite inferior: 0 (debe aceptarse)
- Límite superior: 20 (debe aceptarse)
- Justo fuera: -1 y 21 (deben rechazarse)

**c) Datos inválidos:**  
Valores que el programa no debería aceptar.  
Ejemplo: nota = -5, nota = 25, texto en vez de número.

**d) Casos especiales:**  
Situaciones poco comunes pero posibles.  
Ejemplo: Todas las notas iguales, una sola nota, etc.

### 2.3 Diseño de la tabla de pruebas

Formato estándar:

| Caso | Descripción | Datos Entrada  | Salida Esperada | Salida Real | Estado |
|------|-------------|----------------|-----------------|-------------|--------|
| 1    | Normal      | 15, 18, 12     | Prom: 15.0      | 15.0        | OK     |
| 2    | Límite inf  | 0, 0, 0        | Prom: 0.0       | 0.0         | OK     |
| 3    | Límite sup  | 20, 20, 20     | Prom: 20.0      | 20.0        | OK     |
| 4    | Inválido    | -5, 18, 12     | Error/Rechazo   | ???         | ???    |

### Proceso:

1. Identificar los rangos válidos de cada entrada.
2. Diseñar los casos ANTES de ejecutar el programa.
3. Ejecutar cada caso y registrar la salida real.
4. Comparar con la salida esperada.
5. Marcar como OK o FALLO.
6. Si hay fallos, reportar para corrección.

### 2.4 Ventajas y limitaciones

**Ventajas:**
- No requiere conocer el código fuente.
- Puede realizarla una persona que no sea el programador.
- Verifica el comportamiento desde la perspectiva del usuario.
- Detecta errores en la funcionalidad.

**Limitaciones:**
- No detecta código muerto (que nunca se ejecuta).
- No garantiza que se prueben todos los caminos internos.
- Puede pasar por alto errores en lógica interna.

---

## 3. Reingeniería de Programas

### 3.1 Concepto

La reingeniería es el proceso de examinar, analizar y reestructurar un programa existente para mejorarlo, SIN CAMBIAR su funcionalidad.

```
Programa Original → [Reingeniería] → Programa Mejorado
(mismo comportamiento, mejor estructura interna)
```


### 3.2 Cuándo se necesita reingeniería

- El código es difícil de entender o modificar.
- Los nombres de variables no son descriptivos.
- No tiene comentarios ni documentación.
- Hay código duplicado.
- La estructura es confusa (muchos GOTO, funciones muy largas).
- No sigue estándares de calidad.

### 3.3 Actividades de la reingeniería

**a) Reestructuración del código:**
- Mejorar la indentación y formato.
- Eliminar código muerto (que nunca se ejecuta).
- Simplificar condiciones complejas.

```c
// ANTES:
if(x==1){if(y==2){z=3;}}

// DESPUÉS:
if (x == 1 && y == 2) {
    z = 3;
}
```

**b) Renombrar identificadores:**
- Usar nombres descriptivos para variables, funciones, etc.

```c
// ANTES:
float a, b, c;
c = a * b;

// DESPUÉS:
float precio, cantidad, total;
total = precio * cantidad;
```

**c) Agregar documentación:**
- Encabezado del programa.
- Comentarios de sección.
- Documentación de funciones.

**d) Eliminar números mágicos:**
- Reemplazar valores literales por constantes con nombre.

```c
// ANTES:
imp = sub * 0.16;

// DESPUÉS:
#define TASA_IVA 0.16
imp = sub * TASA_IVA;
```

**e) Modularización:**
- Dividir funciones muy largas en funciones más pequeñas.
- Extraer código duplicado en una función reutilizable.

```c
// ANTES (todo en main):
int main() {
    // 200 líneas de código mezclado
}

// DESPUÉS (modularizado):
void leerDatos() { ... }
float calcularTotal() { ... }
void mostrarResultados() { ... }

int main() {
    leerDatos();
    float total = calcularTotal();
    mostrarResultados();
    return 0;
}
```

**f) Agregar validación de datos:**
- Verificar que las entradas sean válidas antes de procesarlas.

```c
// ANTES:
scanf("%d", &edad);
// usa edad directamente

// DESPUÉS:
do {
    printf("Edad (0-120): ");
    scanf("%d", &edad);
} while (edad < 0 || edad > 120);
```

### 3.4 Ejemplo completo de reingeniería

**ANTES (código de mala calidad):**

```c
#include <stdio.h>
int main(){
float a,b,c;
printf("n1:");scanf("%f",&a);
printf("n2:");scanf("%f",&b);
c=(a+b)/2;
if(c>=10)printf("A");
else printf("R");
return 0;}
```

**DESPUÉS (código con reingeniería):**

```c
/*
 * Programa: Evaluación de Promedio
 * Descripción: Calcula el promedio de dos notas
 *              y determina si el estudiante aprobó.
 */
#include <stdio.h>

#define NOTA_APROBATORIA 10.0

float calcularPromedio(float nota1, float nota2) {
    return (nota1 + nota2) / 2.0;
}

int main() {
    float nota1, nota2, promedio;

    /* Entrada de datos */
    printf("Ingrese la primera nota: ");
    scanf("%f", &nota1);

    printf("Ingrese la segunda nota: ");
    scanf("%f", &nota2);

    /* Proceso */
    promedio = calcularPromedio(nota1, nota2);

    /* Salida */
    printf("Promedio: %.2f\n", promedio);

    if (promedio >= NOTA_APROBATORIA) {
        printf("Resultado: APROBADO\n");
    } else {
        printf("Resultado: REPROBADO\n");
    }

    return 0;
}
```

### Mejoras aplicadas:

1. Nombres descriptivos (a,b,c → nota1, nota2, promedio)
2. Constante en vez de número mágico (10 → NOTA_APROBATORIA)
3. Función para calcular el promedio (modularización)
4. Encabezado con documentación
5. Comentarios de sección
6. Formato e indentación correctos
7. Mensajes claros al usuario
8. Funcionalidad: IDÉNTICA (misma entrada produce misma salida)

### 3.5 Principios fundamentales de la reingeniería

1. **NO cambiar la funcionalidad:** El programa debe hacer exactamente lo mismo antes y después.

2. **Mejorar la estructura interna:** Legibilidad, modularidad, documentación.

3. **Aplicar pruebas:** Verificar con los mismos datos que el resultado sea idéntico al programa original.

4. **Hacer cambios incrementales:** Modificar poco a poco y probar después de cada cambio, no todo de golpe.

---

*Fin de la Teoría - Unidad 7*
