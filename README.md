# Algoritmos y Programación

**Profesor:** José Alfredo Sánchez

Repositorio de ejemplos prácticos para la asignatura **Algoritmos y Programación**. Cada unidad contiene pseudocódigo en formato `.txt` y su equivalente en **lenguaje C estándar (ANSI C)**.

---

## Contenido Programático

### [Unidad 1: Algoritmos y Programas](unidad1/)

Conceptos fundamentales de algoritmos, partes de un algoritmo (entrada, proceso, salida), formas de representación y traza (corrida en frío).

| Archivo | Descripción |
|---------|-------------|
| [ejemplo1_hola_mundo](unidad1/ejemplo1_hola_mundo.c) | Primer programa: mostrar mensajes en pantalla |
| [ejemplo2_partes_algoritmo](unidad1/ejemplo2_partes_algoritmo.c) | Entrada, proceso y salida — Área de un rectángulo |
| [ejemplo3_traza_algoritmo](unidad1/ejemplo3_traza_algoritmo.c) | Corrida en frío — Conversión Celsius a Fahrenheit |

---

### [Unidad 2: Estándares de Calidad en el Diseño de Algoritmos](unidad2/)

Estándares de calidad, trazabilidad, documentación de algoritmos y programas, manuales de sistema/usuario.

| Archivo | Descripción |
|---------|-------------|
| [ejemplo1_documentacion](unidad2/ejemplo1_documentacion.c) | Buenas prácticas de documentación — Promedio de notas |
| [ejemplo2_trazabilidad](unidad2/ejemplo2_trazabilidad.c) | Tabla de trazabilidad — Cálculo de descuento |

---

### [Unidad 3: Datos y Entidades Primitivas](unidad3/)

Tipos de datos, operadores (aritméticos, relacionales, lógicos), expresiones, identificadores, variables (de trabajo, contador, acumulador) y constantes.

| Archivo | Descripción |
|---------|-------------|
| [ejemplo1_tipos_datos](unidad3/ejemplo1_tipos_datos.c) | Tipos de datos: entero, real, carácter, cadena |
| [ejemplo2_operadores](unidad3/ejemplo2_operadores.c) | Operadores aritméticos, relacionales y lógicos |
| [ejemplo3_variables_constantes](unidad3/ejemplo3_variables_constantes.c) | Variables de trabajo, contador, acumulador y constantes |
| [ejemplo4_desbordamiento_enteros](unidad3/ejemplo4_desbordamiento_enteros.c) | Desbordamiento de enteros (overflow) — Cálculo de salario semanal |

---

### [Unidad 4: Metodología para el Análisis y Planteamiento de Problemas](unidad4/)

Identificación del problema, datos de entrada/salida, operaciones y descripción de procesos.

| Archivo | Descripción |
|---------|-------------|
| [ejemplo1_analisis_problema](unidad4/ejemplo1_analisis_problema.c) | Análisis completo — Cálculo de nómina |
| [ejemplo2_conversion_moneda](unidad4/ejemplo2_conversion_moneda.c) | Planteamiento de problema — Conversión de moneda |

---

### [Unidad 5: Programación Estructurada](unidad5/)

Estructuras de decisión (simple, doble, múltiple, anidada, selectiva) y estructuras iterativas (mientras, repetir, para, ciclos anidados).

| Archivo | Descripción |
|---------|-------------|
| [ejemplo1_condicional_simple](unidad5/ejemplo1_condicional_simple.c) | Condicional simple y doble (`if`, `if-else`) |
| [ejemplo2_condicional_anidada](unidad5/ejemplo2_condicional_anidada.c) | Condicionales anidadas (`else if`) — Clasificación de notas |
| [ejemplo3_selectiva](unidad5/ejemplo3_selectiva.c) | Estructura selectiva (`switch`) — Calculadora |
| [ejemplo4_ciclo_mientras](unidad5/ejemplo4_ciclo_mientras.c) | Ciclo mientras (`while`) — Tabla de multiplicar y centinela |
| [ejemplo5_ciclo_repetir](unidad5/ejemplo5_ciclo_repetir.c) | Ciclo repetir (`do-while`) — Menú interactivo |
| [ejemplo6_ciclo_para](unidad5/ejemplo6_ciclo_para.c) | Ciclo para (`for`) y ciclos anidados — Factorial y tabla pitagórica |

---

### [Unidad 6: Programación Modular](unidad6/)

Funciones y procedimientos, ámbito de variables (locales y globales), pase de parámetros por valor y por referencia.

| Archivo | Descripción |
|---------|-------------|
| [ejemplo1_funciones](unidad6/ejemplo1_funciones.c) | Funciones y procedimientos — Área de círculo e IMC |
| [ejemplo2_ambito_variables](unidad6/ejemplo2_ambito_variables.c) | Variables locales/globales y pase de parámetros |

---

### [Unidad 7: Técnicas de Mantenimiento de Programas](unidad7/)

Prueba de caja negra y reingeniería de programas.

| Archivo | Descripción |
|---------|-------------|
| [ejemplo1_caja_negra](unidad7/ejemplo1_caja_negra.c) | Pruebas de caja negra — Clasificador de triángulos |
| [ejemplo2_reingenieria](unidad7/ejemplo2_reingenieria.c) | Reingeniería — Facturación antes y después |

---

## Estructura del Repositorio

```
algoritmos/
├── README.md
├── Contenido.txt
├── unidad1/          # Algoritmos y Programas
├── unidad2/          # Estándares de Calidad
├── unidad3/          # Datos y Entidades Primitivas
├── unidad4/          # Metodología para Análisis
├── unidad5/          # Programación Estructurada
├── unidad6/          # Programación Modular
└── unidad7/          # Técnicas de Mantenimiento
```

## Cómo Compilar y Ejecutar

Cada ejemplo puede compilarse con cualquier compilador de C estándar. Por ejemplo con **GCC**:

```bash
gcc ejemplo1_hola_mundo.c -o ejemplo1
./ejemplo1
```

En **Windows** con MinGW:

```cmd
gcc ejemplo1_hola_mundo.c -o ejemplo1.exe
ejemplo1.exe
```

## Formato de los Ejemplos

Cada ejemplo incluye dos archivos:

- **`.txt`** — Pseudocódigo con análisis, traza y notas teóricas
- **`.c`** — Implementación equivalente en lenguaje C estándar

---

*Asignatura: Algoritmos y Programación — Prof. José Alfredo Sánchez*
