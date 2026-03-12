# Unidad 4: Metodología para el Análisis y Planteamiento de Problemas

**Asignatura:** Algoritmos y Programación  
**Profesor:** José Alfredo Sánchez

---

La metodología de análisis es un proceso sistemático de 5 pasos que permite pasar de un enunciado de problema a un algoritmo que lo resuelve.

## 1. Identificación del Problema

Es el primer paso y el más importante. Consiste en entender claramente QUÉ se pide resolver.

### Preguntas clave:

- ¿Qué debe hacer el programa?
- ¿Cuál es el objetivo final?
- ¿Qué restricciones existen?

**Técnica:** Leer el enunciado varias veces y expresar el problema con palabras propias en una sola oración.

### Ejemplo:

**Enunciado:** "Una empresa necesita calcular el salario neto de sus empleados, considerando las horas trabajadas, la tarifa por hora y una deducción del 10% por impuestos."

**Identificación:** "Calcular el salario neto de un empleado a partir de sus horas trabajadas y tarifa, descontando un 10% de impuestos."

---

## 2. Identificación de los Datos de Entrada

Son los datos que el programa necesita recibir del usuario (o de otra fuente) para poder resolver el problema.

### Preguntas clave:

- ¿Qué datos necesito para resolver el problema?
- ¿De qué tipo es cada dato?
- ¿Cómo se obtienen (los ingresa el usuario, se calculan, son fijos)?

### Para el ejemplo del salario:

| Dato de entrada    | Tipo   | Descripción                      |
|--------------------|--------|----------------------------------|
| nombre             | Cadena | Nombre del empleado              |
| horasTrabajadas    | Entero | Cantidad de horas trabajadas     |
| tarifaHora         | Real   | Pago por cada hora de trabajo    |

---

## 3. Identificación de los Datos de Salida

Son los resultados que el programa debe producir y mostrar al usuario.

### Preguntas clave:

- ¿Qué resultados se esperan?
- ¿En qué formato deben presentarse?
- ¿Cuántos decimales, qué unidades?

### Para el ejemplo del salario:

| Dato de salida     | Tipo | Descripción                      |
|--------------------|------|----------------------------------|
| salarioBruto       | Real | Horas * tarifa (antes de deduc.) |
| deduccion          | Real | 10% del salario bruto            |
| salarioNeto        | Real | Salario bruto - deduccion        |

---

## 4. Descripción de las Operaciones (Cálculos)

Son las fórmulas y operaciones matemáticas necesarias para transformar los datos de entrada en los datos de salida.

### Para el ejemplo del salario:

```
salarioBruto = horasTrabajadas * tarifaHora
deduccion = salarioBruto * 0.10
salarioNeto = salarioBruto - deduccion
```

Es recomendable expresar cada fórmula de forma clara y verificar con un ejemplo numérico:

```
Si horasTrabajadas = 160, tarifaHora = 50:
salarioBruto = 160 * 50 = 8000
deduccion = 8000 * 0.10 = 800
salarioNeto = 8000 - 800 = 7200
```

---

## 5. Descripción de los Pasos del Proceso

Es la secuencia ordenada de pasos para resolver el problema. Aquí se construye el algoritmo propiamente dicho.

### Para el ejemplo del salario:

1. Solicitar el nombre del empleado.
2. Solicitar las horas trabajadas.
3. Solicitar la tarifa por hora.
4. Calcular el salario bruto (horas * tarifa).
5. Calcular la deducción (10% del bruto).
6. Calcular el salario neto (bruto - deducción).
7. Mostrar el recibo de pago con todos los datos.

---

## Ejemplo Completo de Aplicación de la Metodología

**PROBLEMA:** "Una tienda vende productos. Se necesita un programa que calcule el total a pagar por un cliente, aplicando un IVA del 16%."

### 1. IDENTIFICACIÓN DEL PROBLEMA:
Calcular el total a pagar por un cliente incluyendo IVA.

### 2. DATOS DE ENTRADA:
- nombreProducto (Cadena): nombre del producto
- precioUnitario (Real): precio de una unidad
- cantidad (Entero): cuántas unidades compra

### 3. DATOS DE SALIDA:
- subtotal (Real): precio sin IVA
- montoIVA (Real): impuesto calculado
- totalPagar (Real): monto final con IVA

### 4. OPERACIONES:
```
subtotal = precioUnitario * cantidad
montoIVA = subtotal * 0.16
totalPagar = subtotal + montoIVA
```

### 5. PROCESO (Pseudocódigo):
```
Inicio
    Cadena nombreProducto
    Real precioUnitario, subtotal, montoIVA, totalPagar
    Entero cantidad

    Escribir "Nombre del producto: "
    Leer nombreProducto
    Escribir "Precio unitario: "
    Leer precioUnitario
    Escribir "Cantidad: "
    Leer cantidad

    subtotal = precioUnitario * cantidad
    montoIVA = subtotal * 0.16
    totalPagar = subtotal + montoIVA

    Escribir "--- Ticket de Compra ---"
    Escribir "Producto: ", nombreProducto
    Escribir "Subtotal: ", subtotal
    Escribir "IVA (16%): ", montoIVA
    Escribir "TOTAL: ", totalPagar
Fin
```

---

## Resumen: Los 5 Pasos

| # | Paso                              | Pregunta clave             |
|---|-----------------------------------|----------------------------|
| 1 | Identificar el problema           | ¿Qué debo resolver?        |
| 2 | Identificar datos de entrada      | ¿Qué datos necesito?       |
| 3 | Identificar datos de salida       | ¿Qué resultados debo dar?  |
| 4 | Describir las operaciones         | ¿Cómo transformo E en S?   |
| 5 | Describir los pasos del proceso   | ¿En qué orden lo hago?     |

**Consejo:** Antes de programar, SIEMPRE aplica estos 5 pasos. Un buen análisis ahorra tiempo y errores a la hora de escribir el código.

---

*Fin de la Teoría - Unidad 4*
