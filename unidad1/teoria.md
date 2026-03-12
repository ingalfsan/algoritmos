# Unidad 1: Algoritmos y Programas

**Asignatura:** Algoritmos y Programación  
**Profesor:** José Alfredo Sánchez

---

## 1. Concepto de Algoritmo

Un algoritmo es un conjunto ordenado y finito de pasos o instrucciones bien definidas que permiten resolver un problema o realizar una tarea específica.

### Características de un algoritmo:

- **PRECISO:** Cada paso debe ser claro y sin ambigüedad.
- **DEFINIDO:** Si se ejecuta dos veces con los mismos datos, debe dar el mismo resultado.
- **FINITO:** Debe terminar en algún momento (número finito de pasos).

### Ejemplo cotidiano:

Algoritmo para preparar café:
1. Calentar agua
2. Colocar café en el filtro
3. Verter el agua caliente sobre el filtro
4. Esperar que filtre
5. Servir en la taza

---

## 2. Concepto de Programa

Un programa es la traducción de un algoritmo a un lenguaje de programación que la computadora puede entender y ejecutar.

```
Algoritmo (idea) → Programa (código) → Ejecución (resultado)
```

### La diferencia clave:

- **Algoritmo:** es independiente del lenguaje, es la lógica pura.
- **Programa:** es la implementación concreta en un lenguaje (C, Python, etc.)

---

## 3. Lenguaje Algorítmico y de Programación

### Lenguaje algorítmico:

Es un lenguaje informal usado para expresar algoritmos de forma comprensible para humanos. No tiene reglas sintácticas estrictas. Ejemplo: pseudocódigo.

### Lenguaje de programación:

Es un lenguaje formal con reglas sintácticas estrictas que la computadora puede procesar. Ejemplos: C, Java, Python, C++.

### Clasificación de lenguajes:

- **Bajo nivel:** Lenguaje máquina (binario), Ensamblador.
- **Alto nivel:** C, Java, Python (más cercanos al lenguaje humano).

---

## 4. Partes de un Algoritmo

Todo algoritmo tiene tres partes fundamentales:

```
┌──────────┐     ┌──────────┐     ┌──────────┐
│ ENTRADA  │ ──> │ PROCESO  │ ──> │  SALIDA  │
└──────────┘     └──────────┘     └──────────┘
```

- **ENTRADA:** Datos que el algoritmo necesita para trabajar.  
  Ejemplo: base y altura de un rectángulo.

- **PROCESO:** Operaciones y cálculos que se realizan con los datos.  
  Ejemplo: area = base * altura

- **SALIDA:** Resultados que produce el algoritmo.  
  Ejemplo: mostrar el área calculada.

---

## 5. Características para Construir un Algoritmo

Un buen algoritmo debe cumplir:

a) **Precisión:** Los pasos deben estar definidos sin ambigüedad.  
b) **Determinismo:** Ante las mismas entradas, produce las mismas salidas.  
c) **Finitud:** Debe terminar después de un número finito de pasos.  
d) **Entrada:** Puede tener cero o más datos de entrada.  
e) **Salida:** Debe producir al menos un resultado.  
f) **Efectividad:** Cada paso debe ser lo suficientemente básico para poder ejecutarse (en teoría) con lápiz y papel.

### Elementos para construir un algoritmo:

- Variables y constantes (almacenar datos)
- Operadores (realizar cálculos)
- Instrucciones de entrada/salida (leer/escribir)
- Estructuras de control (decisiones y repeticiones)

---

## 6. Formas de Representar un Algoritmo

### 6.1 Lenguaje Natural

Se describe el algoritmo con palabras del idioma común.

**Ejemplo:**  
"Pedir al usuario dos números, sumarlos y mostrar el resultado."

- **Ventaja:** Fácil de entender.
- **Desventaja:** Puede ser ambiguo.

### 6.2 Pseudocódigo

Lenguaje intermedio entre el lenguaje natural y el de programación. Usa palabras clave como Inicio, Fin, Leer, Escribir, Si, Mientras, etc.

**Ejemplo:**
```
Inicio
    Entero a, b, suma
    Escribir "Ingrese dos números:"
    Leer a
    Leer b
    suma = a + b
    Escribir "La suma es: ", suma
Fin
```

- **Ventaja:** Más preciso que el lenguaje natural, fácil de traducir a código.
- **Desventaja:** No es estándar universal (varía entre autores).

### 6.3 Diagrama de Flujo

Representación gráfica del algoritmo usando símbolos estandarizados.

**Símbolos principales:**
- **Óvalo (inicio/fin):** Marca el comienzo y final.
- **Rectángulo (proceso):** Operaciones y cálculos.
- **Rombo (decisión):** Preguntas Sí/No.
- **Paralelogramo (E/S):** Entrada o salida de datos.
- **Flechas:** Indican la dirección del flujo.

- **Ventaja:** Visual, fácil de seguir el flujo.
- **Desventaja:** Puede volverse complejo para algoritmos grandes.

---

## 7. Traza de un Algoritmo (Corrida en Frío)

La traza o corrida en frío es la ejecución manual de un algoritmo paso a paso, registrando el valor de cada variable en cada momento.

### Sirve para:

- Verificar que el algoritmo funciona correctamente.
- Encontrar errores de lógica ANTES de programar.
- Entender el comportamiento del algoritmo.

### Cómo hacer una traza:

1. Crear una tabla con una columna por cada variable.
2. Agregar una columna para la salida en pantalla.
3. Ejecutar cada instrucción en orden, actualizando los valores.

### Ejemplo con pseudocódigo:

```
Inicio
    Entero a, b, c
    a = 5
    b = 3
    c = a + b
    Escribir c
Fin
```

**Traza:**

| Paso | a | b | c | Salida |
|------|---|---|---|--------|
| 1    | ? | ? | ? |        |
| 2    | 5 | ? | ? |        |
| 3    | 5 | 3 | ? |        |
| 4    | 5 | 3 | 8 |        |
| 5    | 5 | 3 | 8 | 8      |

**Consejo:** Siempre haz la corrida en frío con al menos dos conjuntos de datos diferentes para validar tu algoritmo.

---

*Fin de la Teoría - Unidad 1*
