# Unidad 6: Programación Modular

**Asignatura:** Algoritmos y Programación  
**Profesor:** José Alfredo Sánchez

---

## 1. Introducción a la Programación Modular

La programación modular consiste en dividir un programa grande en partes más pequeñas e independientes llamadas MÓDULOS (funciones y procedimientos).

### Ventajas:

- **Divide y vencerás:** problemas complejos se resuelven por partes.
- **Reutilización:** un módulo se escribe una vez y se usa muchas veces.
- **Mantenimiento:** si hay un error, se localiza y corrige en un módulo.
- **Legibilidad:** el programa principal queda más corto y claro.
- **Trabajo en equipo:** cada persona puede trabajar en un módulo diferente.

---

## 2. Funciones y Procedimientos

### 2.1 Procedimiento (Función void en C)

Es un módulo que realiza una tarea pero NO retorna un valor. En C se declara con la palabra "void" (vacío).

**Pseudocódigo:**
```
Procedimiento mostrarSaludo()
    Escribir "Bienvenido"
Fin Procedimiento
```

**En C:**
```c
void mostrarSaludo() {
    printf("Bienvenido\n");
}
```

**Se llama (invoca) así:**
```c
mostrarSaludo();
```

### 2.2 Función (Función con retorno en C)

Es un módulo que realiza una tarea y RETORNA un valor al punto donde fue llamada.

**Pseudocódigo:**
```
Función Real sumar(Real a, Real b)
    Retornar a + b
Fin Función
```

**En C:**
```c
float sumar(float a, float b) {
    return a + b;
}
```

**Se llama así:**
```c
resultado = sumar(5, 3);
// resultado vale 8
```

### 2.3 Diferencia clave:

| Procedimiento        | Función                    |
|----------------------|----------------------------|
| NO retorna valor     | SÍ retorna un valor        |
| void en C            | int, float, char... en C   |
| Se llama solo        | Se asigna a una variable   |
| mostrarMenu();       | r = calcular(a, b);        |

---

## 3. Definición y Declaración de Funciones en C

### 3.1 Estructura de una función en C:

```c
tipo_retorno nombre_funcion(parametros) {
    // cuerpo de la función
    return valor;  // si no es void
}
```

Donde:
- **tipo_retorno:** tipo del valor que devuelve (int, float, void, etc.)
- **nombre_funcion:** identificador descriptivo
- **parametros:** datos que recibe (puede ser vacío)
- **return:** valor que devuelve al punto de llamada

### 3.2 Ejemplo completo:

```c
// Declaración (prototipo) - le dice al compilador que la función existe
float calcularArea(float base, float altura);

// Programa principal
int main() {
    float b = 5, h = 3;
    float area = calcularArea(b, h);   // Llamada a la función
    printf("Area: %.2f\n", area);
    return 0;
}

// Definición (implementación) - el cuerpo de la función
float calcularArea(float base, float altura) {
    return base * altura;
}
```

**NOTA:** Si la función se define ANTES de main(), no necesita prototipo. Si se define DESPUÉS, se necesita declarar el prototipo antes de main().

---

## 4. Ámbito de Variables: Locales y Globales

El "ámbito" (scope) de una variable determina DÓNDE es visible y accesible dentro del programa.

### 4.1 Variables LOCALES

- Se declaran DENTRO de una función.
- Solo existen mientras esa función se está ejecutando.
- No son accesibles desde otras funciones.
- Se crean al entrar a la función y se destruyen al salir.

```c
void ejemplo() {
    int x = 10;       // x es LOCAL a esta función
    printf("%d", x);  // OK: x es visible aquí
}

int main() {
    ejemplo();
    // printf("%d", x);  // ERROR: x no existe aquí
    return 0;
}
```

### 4.2 Variables GLOBALES

- Se declaran FUERA de todas las funciones (generalmente al inicio).
- Son accesibles desde CUALQUIER función del programa.
- Existen durante toda la ejecución del programa.

```c
int contador = 0;  // GLOBAL: visible en todo el programa

void incrementar() {
    contador++;     // OK: puede acceder a la variable global
}

int main() {
    incrementar();
    incrementar();
    printf("%d", contador);  // Imprime: 2
    return 0;
}
```


### 4.3 Comparación:

| Variable Local       | Variable Global           |
|----------------------|---------------------------|
| Dentro de función    | Fuera de funciones        |
| Solo en su función   | En todo el programa       |
| Se crea/destruye     | Existe todo el tiempo     |
| Más segura           | Puede causar errores      |
| RECOMENDADA          | Usar con precaución       |

**RECOMENDACIÓN:** Preferir variables locales. Las globales deben usarse solo cuando realmente se necesita compartir datos entre funciones sin usar parámetros.

### 4.4 Conflicto de nombres:

Si una variable local tiene el mismo nombre que una global, la LOCAL tiene prioridad dentro de su función.

```c
int x = 100;  // global

void funcion() {
    int x = 5;       // local: "oculta" la global
    printf("%d", x); // Imprime: 5 (la local)
}

int main() {
    printf("%d", x); // Imprime: 100 (la global)
    funcion();
    return 0;
}
```

---

## 5. Llamada de una Función y Pase de Parámetros

### 5.1 Parámetros y argumentos

- **Parámetro:** variable en la DEFINICIÓN de la función (nombre formal).
- **Argumento:** valor que se PASA al llamar la función (valor real).

```c
float calcular(float precio, int cantidad) {  // parámetros
    return precio * cantidad;
}

int main() {
    float total = calcular(9.99, 3);  // argumentos: 9.99 y 3
    return 0;
}
```

### 5.2 Pase por VALOR

Se copia el valor del argumento al parámetro. La función trabaja con la COPIA, el original NO se modifica.

```c
void duplicar(int numero) {
    numero = numero * 2;         // modifica la COPIA
    printf("Dentro: %d\n", numero);  // Imprime: 10
}

int main() {
    int x = 5;
    duplicar(x);
    printf("Fuera: %d\n", x);   // Imprime: 5 (NO cambió)
    return 0;
}
```

**Explicación:**
- x vale 5 en main
- Se copia 5 al parámetro 'numero'
- 'numero' se duplica a 10 dentro de la función
- Pero x sigue valiendo 5, porque era una copia

### 5.3 Pase por REFERENCIA (punteros en C)

Se pasa la DIRECCIÓN de memoria de la variable. La función puede modificar el valor ORIGINAL.

En C se usan punteros (*) para pase por referencia:

```c
void duplicar(int *numero) {         // recibe un puntero
    *numero = *numero * 2;           // modifica el ORIGINAL
    printf("Dentro: %d\n", *numero); // Imprime: 10
}

int main() {
    int x = 5;
    duplicar(&x);                    // pasa la DIRECCIÓN de x
    printf("Fuera: %d\n", x);       // Imprime: 10 (SÍ cambió)
    return 0;
}
```

**Explicación:**
- &x es la dirección de memoria de x
- *numero accede al valor en esa dirección
- Al modificar *numero, se modifica x directamente

### 5.4 Comparación:

| Por Valor            | Por Referencia              |
|----------------------|-----------------------------|
| Copia el valor       | Pasa la dirección           |
| Original intacto     | Original se puede modificar |
| func(x)              | func(&x)                    |
| int param            | int *param                  |
| Más seguro           | Más eficiente para datos    |
|                      | grandes                     |

### Cuándo usar cada uno:

- **Por valor:** cuando la función NO necesita modificar el original.
- **Por referencia:** cuando la función SÍ debe modificar el original, o cuando se necesita retornar más de un valor.

### Ejemplo de función que retorna dos valores usando punteros:

```c
void dividir(int a, int b, int *cociente, int *residuo) {
    *cociente = a / b;
    *residuo = a % b;
}

int main() {
    int c, r;
    dividir(17, 5, &c, &r);
    printf("Cociente: %d, Residuo: %d\n", c, r);
    // Imprime: Cociente: 3, Residuo: 2
    return 0;
}
```

---

*Fin de la Teoría - Unidad 6*
