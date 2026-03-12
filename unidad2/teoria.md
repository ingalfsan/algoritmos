# Unidad 2: Estándares de Calidad en el Diseño de Algoritmos y Construcción de Programas

**Asignatura:** Algoritmos y Programación  
**Profesor:** José Alfredo Sánchez

---

## 1. Introducción a los Estándares de Calidad

Los estándares de calidad son reglas y convenciones que se aplican al diseñar algoritmos y escribir programas para garantizar que sean:

- **Correctos:** producen los resultados esperados.
- **Legibles:** cualquier persona puede entender el código.
- **Mantenibles:** se pueden modificar fácilmente en el futuro.
- **Eficientes:** usan los recursos de forma adecuada.

### Estándares básicos para escribir algoritmos y programas:

**a) Nombres descriptivos:**
```
MAL:   x = a * b
BIEN:  area = base * altura
```

**b) Indentación consistente (sangría):**
```
MAL:
Si (nota >= 10) Entonces
Escribir "Aprobado"
Fin Si

BIEN:
Si (nota >= 10) Entonces
    Escribir "Aprobado"
Fin Si
```

**c) Una instrucción por línea.**

**d) Uso de espacios para mejorar legibilidad:**
```
MAL:   resultado=a+b*c
BIEN:  resultado = a + b * c
```

**e) Agrupación lógica:** separar las secciones del programa (declaraciones, entrada, proceso, salida) con líneas en blanco.

---

## 2. Forma de Trazabilizar un Algoritmo

La trazabilidad es la capacidad de seguir el comportamiento de un algoritmo paso a paso para verificar su correctitud.

### Pasos para trazabilizar:

1. Identificar todas las variables del algoritmo.
2. Crear una tabla con:
   - Columna de número de paso
   - Una columna por cada variable
   - Columna de salida en pantalla
   - Columna de observaciones (opcional)
3. Ejecutar cada instrucción en orden secuencial.
4. Registrar cómo cambian los valores en cada paso.
5. Verificar que la salida final es la esperada.

### Ejemplo:

**Algoritmo:** Calcular el doble de un número

```
Inicio
    Entero numero, doble
    Escribir "Ingrese un número: "
    Leer numero
    doble = numero * 2
    Escribir "El doble es: ", doble
Fin
```

**Traza con entrada numero = 7:**

| Paso | numero | doble | Salida                    |
|------|--------|-------|---------------------------|
| 1    | ?      | ?     | "Ingrese un número: "     |
| 2    | 7      | ?     | (usuario ingresa 7)       |
| 3    | 7      | 14    | (cálculo: 7 * 2 = 14)     |
| 4    | 7      | 14    | "El doble es: 14"         |

---

## 3. Formas y Técnicas de Documentar Algoritmos y Programas

La documentación es texto explicativo que acompaña al algoritmo o programa para facilitar su comprensión y mantenimiento.

### 3.1 Documentación interna (dentro del código)

**a) Encabezado del programa:**

Todo programa debe comenzar con un bloque de comentarios que incluya:

```c
/*
 * PROGRAMA: [Nombre del programa]
 * DESCRIPCION: [Qué hace el programa]
 * AUTOR: [Nombre del programador]
 * FECHA: [Fecha de creación]
 * VERSION: [Número de versión]
 */
```

**b) Comentarios de sección:**

Marcar las secciones principales del programa:
```c
/* Declaración de variables */
/* Entrada de datos */
/* Proceso */
/* Salida de resultados */
```

**c) Comentarios de línea:**

Explicar operaciones no obvias:
```c
iva = subtotal * 0.16;  /* Cálculo del IVA al 16% */
```

### Reglas para buenos comentarios:

- Explicar el POR QUÉ, no el QUÉ (el código ya dice qué hace).
- No comentar lo obvio: `/* Sumar a + b */  a + b;`  ← innecesario
- Mantener los comentarios actualizados si el código cambia.

### 3.2 Documentación externa (fuera del código)

Son documentos separados que describen el sistema de forma más amplia. Ver sección 4: Manuales.

---

## 4. Introducción a la Elaboración de Manuales

### 4.1 Manual del Sistema

**Dirigido a:** Programadores y personal técnico.

**Contenido:**
- Descripción general del sistema
- Requisitos de hardware y software
- Estructura del programa (módulos, funciones)
- Diagramas de flujo o pseudocódigo
- Descripción de archivos y bases de datos
- Instrucciones de instalación y configuración

### 4.2 Manual del Usuario

**Dirigido a:** Usuarios finales (no técnicos).

**Contenido:**
- Descripción de lo que hace el programa
- Requisitos para ejecutarlo
- Instrucciones paso a paso de uso
- Capturas de pantalla (si aplica)
- Ejemplos de uso
- Preguntas frecuentes
- Mensajes de error y cómo resolverlos

### 4.3 Manual del Programa (Documentación Técnica)

**Dirigido a:** Programadores que darán mantenimiento.

**Contenido:**
- Listado de variables con su tipo y propósito
- Descripción de cada función/procedimiento
- Parámetros de entrada y salida
- Fórmulas utilizadas
- Restricciones y limitaciones
- Historial de cambios

---

## 5. Técnicas de Escritura y Pruebas de Algoritmos y Programas

### 5.1 Técnicas de escritura

**a) Desarrollo descendente (Top-Down):**

Partir del problema general y dividirlo en subproblemas más pequeños hasta llegar a pasos simples.

**Ejemplo:**
```
Problema: "Calcular la nómina de empleados"
├── Leer datos del empleado
├── Calcular salario bruto
│   ├── Horas normales * tarifa
│   └── Horas extras * tarifa * 1.5
├── Calcular deducciones
├── Calcular salario neto
└── Mostrar resultados
```

**b) Desarrollo ascendente (Bottom-Up):**

Construir primero las partes pequeñas y luego integrarlas.

**c) Refinamiento por pasos:**

Comenzar con una versión general y refinar progresivamente cada paso hasta tener el nivel de detalle necesario.

### 5.2 Técnicas de pruebas

**a) Corrida en frío (traza manual):**  
Ejecutar el algoritmo con papel y lápiz paso a paso.

**b) Prueba con datos conocidos:**  
Usar datos cuyo resultado se conoce de antemano.

**c) Prueba con datos extremos:**  
Probar con valores límite: cero, negativos, muy grandes.

**d) Prueba con datos inválidos:**  
Verificar que el programa maneje correctamente entradas erróneas.

### Ejemplo de conjunto de pruebas para un programa que divide dos números:

| Tipo          | Entrada  | Resultado | Descripción      |
|---------------|----------|-----------|------------------|
| Normal        | 10 / 2   | 5         | Caso típico      |
| Extremo       | 0 / 5    | 0         | Dividendo cero   |
| Inválido      | 10 / 0   | ERROR     | Divisor cero     |
| Negativo      | -10 / 2  | -5        | Números negativos|

---

*Fin de la Teoría - Unidad 2*
