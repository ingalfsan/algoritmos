# Unidad 5: Programación Estructurada

**Asignatura:** Algoritmos y Programación  
**Profesor:** José Alfredo Sánchez

---

## 1. Teoremas de la Programación Estructurada

La programación estructurada se basa en el Teorema de Bohm-Jacopini (1966), que establece que CUALQUIER algoritmo puede construirse utilizando solo tres estructuras de control:

1. **Secuencia:** ejecutar instrucciones una tras otra.
2. **Selección (decisión):** elegir entre dos o más caminos.
3. **Iteración (repetición):** repetir un bloque de instrucciones.

### Principios fundamentales:

- Todo programa tiene UN solo punto de entrada y UN solo punto de salida.
- Se evita el uso de saltos incondicionales (GOTO).
- El código se lee de arriba hacia abajo.
- Se favorece la claridad y la estructura lógica.

---

## 2. Estructuras de Control

Son mecanismos que permiten controlar el flujo de ejecución de un programa. Se dividen en dos grandes grupos:

- **A) Estructuras de Decisión (selección)**
- **B) Estructuras de Iteración (repetición)**

---

# A) ESTRUCTURAS DE DECISIÓN

## 3. Condicional Simple

Ejecuta un bloque de instrucciones SOLO si la condición es verdadera. Si es falsa, no hace nada.

### Pseudocódigo:
```
Si (condicion) Entonces
    instrucciones
Fin Si
```

### En C:
```c
if (condicion) {
    instrucciones;
}
```

### Ejemplo:
```c
if (edad >= 18) {
    printf("Es mayor de edad\n");
}
```

---

## 4. Condicional Doble

Ejecuta un bloque si la condición es verdadera, y OTRO bloque diferente si es falsa.

### Pseudocódigo:
```
Si (condicion) Entonces
    instrucciones_V
Sino
    instrucciones_F
Fin Si
```

### En C:
```c
if (condicion) {
    instrucciones_V;
} else {
    instrucciones_F;
}
```

### Ejemplo:
```c
if (nota >= 10) {
    printf("Aprobado\n");
} else {
    printf("Reprobado\n");
}
```

---

## 5. Condicionales Múltiples (Anidadas)

Se colocan condicionales dentro de otras condicionales para evaluar múltiples condiciones.

### Pseudocódigo:
```
Si (cond1) Entonces
    instrucciones_1
Sino Si (cond2) Entonces
    instrucciones_2
Sino Si (cond3) Entonces
    instrucciones_3
Sino
    instrucciones_default
Fin Si
```

### En C:
```c
if (cond1) {
    instrucciones_1;
} else if (cond2) {
    instrucciones_2;
} else if (cond3) {
    instrucciones_3;
} else {
    instrucciones_default;
}
```


### Ejemplo: Clasificar una nota

```c
if (nota >= 18) {
    printf("Excelente\n");
} else if (nota >= 15) {
    printf("Bueno\n");
} else if (nota >= 10) {
    printf("Aprobado\n");
} else {
    printf("Reprobado\n");
}
```

**IMPORTANTE:** El orden de las condiciones importa. Se evalúan de arriba hacia abajo y se ejecuta SOLO el primer bloque cuya condición sea verdadera.

---

## 6. Estructura Selectiva (Según Sea / Switch)

Permite elegir entre múltiples opciones basándose en el valor de una variable (generalmente entera o carácter).

### Pseudocódigo:
```
Según Sea (variable) Hacer
    Caso valor1:
        instrucciones_1
    Caso valor2:
        instrucciones_2
    De Otro Modo:
        instrucciones_default
Fin Según
```

### En C:
```c
switch (variable) {
    case valor1:
        instrucciones_1;
        break;
    case valor2:
        instrucciones_2;
        break;
    default:
        instrucciones_default;
        break;
}
```

**IMPORTANTE en C:**
- Cada "case" debe terminar con "break;" para evitar que se ejecuten los casos siguientes (fall-through).
- Solo funciona con valores enteros (int) o caracteres (char), NO con float ni con cadenas.

### Ejemplo: Menú de opciones

```c
switch (opcion) {
    case 1:
        printf("Sumar\n");
        break;
    case 2:
        printf("Restar\n");
        break;
    default:
        printf("No válido\n");
        break;
}
```

---

# B) ESTRUCTURAS DE CONTROL ITERATIVAS (CICLOS)

Un ciclo (bucle) repite un bloque de instrucciones mientras se cumpla una condición o un número determinado de veces.

### Componentes de un ciclo:

- **Inicialización:** valor inicial de la variable de control.
- **Condición:** se evalúa para decidir si se sigue repitiendo.
- **Actualización:** modifica la variable de control para avanzar.
- **Cuerpo:** instrucciones que se repiten.

---

## 7. Ciclo Mientras (While)

Evalúa la condición ANTES de ejecutar el cuerpo. Si la condición es falsa desde el inicio, el cuerpo NO se ejecuta nunca.

### Pseudocódigo:
```
Mientras (condicion) Hacer
    instrucciones
Fin Mientras
```

### En C:
```c
while (condicion) {
    instrucciones;
}
```

### Ejemplo: Imprimir números del 1 al 5

```c
i = 1;
while (i <= 5) {
    printf("%d\n", i);
    i = i + 1;
}
```

**Salida:** 1 2 3 4 5

**CUIDADO:** Si la condición nunca se vuelve falsa, el ciclo es INFINITO.

### Ejemplo de ciclo infinito (ERROR):

```c
i = 1;
while (i <= 5) {
    printf("%d\n", i);
    // FALTA: i = i + 1;  <-- nunca se actualiza, i siempre es 1
}
```

### Métodos para salir de un ciclo Mientras:

a) La condición se vuelve falsa naturalmente (actualizando la variable).  
b) Uso de centinela: un valor especial que indica fin de datos.  
   Ejemplo: Leer números hasta que el usuario ingrese 0.

---

## 8. Ciclo Repetir-Hasta (Do-While)

Ejecuta el cuerpo PRIMERO y luego evalúa la condición. El cuerpo se ejecuta AL MENOS UNA VEZ.

### Pseudocódigo:
```
Repetir
    instrucciones
Hasta Que (condicion_salida)
```

### En C:
```c
do {
    instrucciones;
} while (condicion_continuar);
```

**ATENCIÓN:** Hay una diferencia sutil entre pseudocódigo y C:
- **Pseudocódigo:** "Hasta Que" = se detiene cuando la condición es VERDADERA.
- **C:** "while" = continúa mientras la condición sea VERDADERA.

Son condiciones OPUESTAS.

### Ejemplo:

**Pseudocódigo:**
```
Repetir
    Escribir "Ingrese opción"
    Leer opcion
Hasta Que (opcion == 4)
```
(se detiene cuando es 4)

**En C:**
```c
do {
    printf("Ingrese opción");
    scanf("%d", &opcion);
} while (opcion != 4);
```
(continúa mientras NO sea 4)

**Uso típico:** Validación de datos y menús.

### Ejemplo: Validar que una nota esté entre 0 y 20

```c
do {
    printf("Nota (0-20): ");
    scanf("%f", &nota);
} while (nota < 0 || nota > 20);
```

---

## 9. Ciclo Para (For)

Se usa cuando se conoce DE ANTEMANO cuántas veces se va a repetir.

### Pseudocódigo:
```
Para i = inicio Hasta fin Hacer
    instrucciones
Fin Para
```

### En C:
```c
for (i = inicio; i <= fin; i++) {
    instrucciones;
}
```

### Estructura del for en C:

```c
for (inicializacion; condicion; actualizacion)
```

- **inicialización:** se ejecuta UNA sola vez al inicio.
- **condición:** se evalúa ANTES de cada repetición.
- **actualización:** se ejecuta AL FINAL de cada repetición.

### Ejemplo: Sumar los números del 1 al 10

```c
suma = 0;
for (i = 1; i <= 10; i++) {
    suma = suma + i;
}
printf("Suma: %d\n", suma);
```

**Resultado:** Suma: 55

---

## 10. Ciclos Anidados

Un ciclo anidado es un ciclo dentro de otro ciclo. El ciclo interno se ejecuta COMPLETAMENTE por cada iteración del externo.

### Pseudocódigo:

```
Para fila = 1 Hasta 3 Hacer
    Para columna = 1 Hasta 4 Hacer
        Escribir fila, ",", columna, "  "
    Fin Para
    Escribir ""   // salto de línea
Fin Para
```

### En C:

```c
for (fila = 1; fila <= 3; fila++) {
    for (columna = 1; columna <= 4; columna++) {
        printf("(%d,%d) ", fila, columna);
    }
    printf("\n");
}
```

### Salida:

```
(1,1) (1,2) (1,3) (1,4)
(2,1) (2,2) (2,3) (2,4)
(3,1) (3,2) (3,3) (3,4)
```

Total de ejecuciones del ciclo interno: 3 × 4 = 12 veces.

**Regla general:** Si el ciclo externo se repite M veces y el interno N veces, el cuerpo del ciclo interno se ejecuta M × N veces.

---

## Resumen: Comparación de Ciclos

### Mientras (while) vs Repetir (do-while)

| Característica       | Mientras (while)      | Repetir (do-while)    |
|----------------------|-----------------------|-----------------------|
| Evalúa condición     | ANTES de ejecutar     | DESPUÉS de ejecutar   |
| Mínimo ejecución     | 0 veces               | 1 vez                 |
| Uso típico           | Cuando no se sabe     | Menús, validación     |
|                      | cuántas veces         | (al menos 1 vez)      |

### Para (for)

| Característica       | Para (for)            |
|----------------------|-----------------------|
| Evalúa condición     | ANTES de ejecutar     |
| Mínimo ejecución     | 0 veces               |
| Uso típico           | Número conocido       |
|                      | de repeticiones       |

Cualquier ciclo puede reescribirse con otro tipo de ciclo. Se elige el más conveniente según el caso.

---

*Fin de la Teoría - Unidad 5*
