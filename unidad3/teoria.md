# Unidad 3: Datos y Entidades Primitivas

**Asignatura:** Algoritmos y Programación  
**Profesor:** José Alfredo Sánchez

---

## 1. Dato e Información

**DATO:** Representación simbólica de un hecho, sin contexto ni significado por sí solo.  
Ejemplo: 25, "Ana", 3.14

**INFORMACIÓN:** Dato procesado, organizado y con significado.  
Ejemplo: "La edad del estudiante es 25 años."  
"El nombre de la alumna es Ana."

**Relación:**
```
Datos → [Procesamiento] → Información
```

---

## 2. Tipos de Datos

Los tipos de datos definen qué clase de valores puede almacenar una variable y qué operaciones se pueden realizar con ella.

### 2.1 Tipos de datos simples (primitivos):

| Tipo           | Descripción               | Ejemplo           |
|----------------|---------------------------|-------------------|
| Entero (int)   | Números sin decimales     | 5, -3, 0, 100     |
| Real (float)   | Números con decimales     | 3.14, -0.5, 2.0   |
| Carácter (char)| Un solo símbolo           | 'A', '7', '#'     |
| Lógico (bool)  | Verdadero o Falso         | verdadero, falso  |

### 2.2 Tipos de datos compuestos:

- **Cadena (string):** secuencia de caracteres. Ejemplo: "Hola Mundo"
- **Arreglo (array):** colección de datos del mismo tipo.

### En lenguaje C:

```c
int edad = 25;            // Entero
float precio = 9.99;      // Real
char letra = 'A';         // Carácter
char nombre[20] = "Ana";  // Cadena de caracteres
// C no tiene tipo booleano nativo (se usa int: 0=falso, 1=verdadero)
```

---

## 3. Los Operadores

Un operador es un símbolo que indica una operación a realizar sobre uno o más valores (operandos).

### 3.1 Operadores Aritméticos

Realizan operaciones matemáticas.

| Operador | Operación        | Ejemplo | Resultado |
|----------|------------------|---------|-----------|
| +        | Suma             | 7 + 3   | 10        |
| -        | Resta            | 7 - 3   | 4         |
| *        | Multiplicación   | 7 * 3   | 21        |
| /        | División         | 7 / 3   | 2 (*)     |
| %        | Módulo (residuo) | 7 % 3   | 1         |

(*) División entera en C cuando ambos operandos son int.  
7.0 / 3.0 = 2.333... (división real con float).

### 3.2 Operadores Relacionales (de comparación)

Comparan dos valores y devuelven verdadero (1) o falso (0).

| Operador | Significado      | Ejemplo | Resultado  |
|----------|------------------|---------|------------|
| ==       | Igual a          | 5 == 5  | verdadero  |
| !=       | Diferente de     | 5 != 3  | verdadero  |
| >        | Mayor que        | 5 > 3   | verdadero  |
| <        | Menor que        | 5 < 3   | falso      |
| >=       | Mayor o igual    | 5 >= 5  | verdadero  |
| <=       | Menor o igual    | 3 <= 5  | verdadero  |

### 3.3 Operadores Lógicos

Combinan expresiones lógicas (verdadero/falso).

| Operador | Nombre    | Ejemplo         | Resultado  |
|----------|-----------|-----------------|------------|
| &&       | Y (AND)   | (5>3) && (2<4)  | verdadero  |
| \|\|     | O (OR)    | (5>3) \|\| (2>4)| verdadero  |
| !        | NO (NOT)  | !(5>3)          | falso      |

**Tabla de verdad AND (&&):**
```
V && V = V
V && F = F
F && V = F
F && F = F
```

**Tabla de verdad OR (||):**
```
V || V = V
V || F = V
F || V = V
F || F = F
```

**NOT (!):**
```
!V = F
!F = V
```

### 3.4 Operadores de Asignación

```c
=    // Asignación simple:      x = 5
+=   // Suma y asigna:          x += 3   equivale a   x = x + 3
-=   // Resta y asigna:         x -= 3   equivale a   x = x - 3
*=   // Multiplica y asigna:    x *= 3   equivale a   x = x * 3
/=   // Divide y asigna:        x /= 3   equivale a   x = x / 3
```

### 3.5 Operadores de Incremento/Decremento (en C)

```c
++   // Incrementa en 1:   i++  equivale a  i = i + 1
--   // Decrementa en 1:   i--  equivale a  i = i - 1
```

---

## 4. Las Expresiones

Una expresión es una combinación de valores, variables y operadores que produce un resultado.

### 4.1 Tipos de expresiones:

**a) Expresiones aritméticas:** producen un valor numérico.  
Ejemplo: `(base * altura) / 2`

**b) Expresiones relacionales:** producen verdadero o falso.  
Ejemplo: `edad >= 18`

**c) Expresiones lógicas:** combinan expresiones relacionales.  
Ejemplo: `(edad >= 18) && (edad <= 65)`

### 4.2 Evaluación de expresiones (jerarquía de operadores):

La jerarquía determina el orden en que se evalúan los operadores:

| Prioridad | Operador           | Descripción        |
|-----------|--------------------|--------------------|
| 1         | ()                 | Paréntesis         |
| 2         | !                  | NOT                |
| 3         | * / %              | Mult/Div/Mod       |
| 4         | + -                | Suma/Resta         |
| 5         | < > <= >=          | Relacionales       |
| 6         | == !=              | Igualdad           |
| 7         | &&                 | AND                |
| 8         | \|\|               | OR                 |
| 9         | =                  | Asignación         |

### Ejemplo de evaluación paso a paso:

**Expresión:** `3 + 4 * 2 - 1`

```
Paso 1: 4 * 2 = 8      (multiplicación primero)
Paso 2: 3 + 8 = 11     (suma)
Paso 3: 11 - 1 = 10    (resta)
Resultado: 10
```

**Con paréntesis:** `(3 + 4) * (2 - 1)`

```
Paso 1: 3 + 4 = 7      (paréntesis primero)
Paso 2: 2 - 1 = 1      (paréntesis primero)
Paso 3: 7 * 1 = 7      (multiplicación)
Resultado: 7
```

---

## 5. Los Identificadores

Un identificador es el nombre que se le da a una variable, constante, función o cualquier elemento del programa.

### Reglas de escritura para identificadores:

- Debe comenzar con una letra (a-z, A-Z) o guion bajo (_).
- Puede contener letras, dígitos (0-9) y guion bajo.
- NO puede contener espacios ni caracteres especiales (@, #, $...).
- NO puede ser una palabra reservada del lenguaje (if, while, int...).
- C distingue entre mayúsculas y minúsculas (es case-sensitive):  
  "edad", "Edad" y "EDAD" son tres variables diferentes.

**Válidos:** edad, nota1, salario_bruto, _contador, totalVentas  
**Inválidos:** 1nota, salario bruto, int, mi-variable, año

---

## 6. Las Variables

Una variable es un espacio en memoria que almacena un valor que puede cambiar durante la ejecución del programa.

Se declara indicando su tipo y nombre:
```
Entero edad           →  int edad;
Real precio           →  float precio;
Carácter inicial      →  char inicial;
```

### 6.1 Clasificación según su CONTENIDO:

**a) Variables numéricas:** almacenan valores numéricos.
```c
int cantidad = 10;
float temperatura = 36.5;
```

**b) Variables lógicas:** almacenan verdadero (1) o falso (0).
```c
int aprobado = 1;   // verdadero
int reprobado = 0;  // falso
```

**c) Variables alfanuméricas:** almacenan texto o caracteres.
```c
char letra = 'A';
char nombre[30] = "Maria";
```

### 6.2 Clasificación según su USO:

**a) Variable de TRABAJO:**

Almacena resultados de cálculos intermedios o finales.

```c
area = base * altura;        // 'area' es variable de trabajo
promedio = suma / cantidad;  // 'promedio' es variable de trabajo
```

**b) Variable CONTADOR:**

Se incrementa (o decrementa) en un valor constante, generalmente 1. Se usa para contar repeticiones.

```c
contador = 0;
contador = contador + 1;   // incrementa de 1 en 1
// después de 5 repeticiones: contador vale 5
```

**c) Variable ACUMULADOR:**

Acumula valores sucesivos (generalmente sumas). La diferencia con el contador es que el valor que se suma varía.

```c
suma = 0;
suma = suma + nota;   // se le suma un valor diferente cada vez
// si nota fue 15, 18, 12: suma = 0+15+18+12 = 45
```

**Diferencia clave:**
- **Contador:** siempre suma el mismo valor (1, 2, etc.)
- **Acumulador:** suma valores diferentes cada vez.

---

## 7. Las Constantes

Una constante es un valor que NO cambia durante la ejecución del programa. Se define una vez y se usa varias veces.

### En pseudocódigo:
```
Constante Real PI = 3.14159
Constante Entero MAX = 100
```

### En lenguaje C:
```c
#define PI 3.14159
#define MAX 100

// O también:
const float PI = 3.14159;
const int MAX = 100;
```

### Ventajas de usar constantes:

- Evitan "números mágicos" en el código.
- Si el valor cambia, se modifica en un solo lugar.
- Mejoran la legibilidad del programa.

```c
MAL:   area = 3.14159 * radio * radio;   // ¿qué es 3.14159?
BIEN:  area = PI * radio * radio;        // claro: es PI
```

---

*Fin de la Teoría - Unidad 3*
