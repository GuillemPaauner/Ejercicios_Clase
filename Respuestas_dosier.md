# Dosier resuelto: Introducción a la programación

Los ejercicios que piden código se entregan en archivos `.cpp` independientes. Este documento contiene las respuestas de interpretación y explica las soluciones de programación, sus resultados y cómo ejecutarlas.

## Archivos y compilación

Cada archivo tiene su propio `main`: se compilan **por separado**, no todos juntos en un único ejecutable.

| Ejercicio | Archivo |
| --- | --- |
| 3.25 a | `ejercicio_3_25_a_factorial.cpp` |
| 3.25 b | `ejercicio_3_25_b_constante_e.cpp` |
| 3.25 c | `ejercicio_3_25_c_exponencial.cpp` |
| 3.26, cifrado | `ejercicio_3_26_cifrar.cpp` |
| 3.26, descifrado | `ejercicio_3_26_descifrar.cpp` |
| 4.15 | `ejercicio_4_15_pi.cpp` |
| 4.8 | `ejercicio_4_8_producto_impares.cpp` |
| 5.2 | `ejercicio_5_2_aparcamiento.cpp` |
| 5.6 | `ejercicio_5_6_aleatorios.cpp` |
| 5.18 | `ejercicio_5_18_invertir_cifras.cpp` |
| 5.21 | `ejercicio_5_21_moneda.cpp` |
| 5.26 | `ejercicio_5_26_hanoi.cpp` |

Ejemplo de compilación con GCC, desde la carpeta de los archivos:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic ejercicio_3_25_a_factorial.cpp -o factorial
./factorial
```

Todos los archivos utilizan únicamente la biblioteca estándar de C++17; no requieren Boost ni otras dependencias externas.

Se debe introducir el punto como separador decimal, por ejemplo `1.5`.

## 3.11. Salida del programa

El programa muestra exactamente estas diez líneas:


*****
++++++++
*****
++++++++
*****
++++++++
*****
++++++++
*****
++++++++


`count` comienza en 1 y el bucle se ejecuta hasta 10, ambos incluidos. En los valores impares, `count % 2 == 1` es verdadero y se imprimen cinco asteriscos. En los pares se imprimen ocho signos `+`. Después de cada impresión se escribe un salto de línea y se incrementa el contador.

## 3.12. Salida del programa


>>>>>>>>>>
<<<<<<<<<<
>>>>>>>>>>
<<<<<<<<<<
>>>>>>>>>>
<<<<<<<<<<
>>>>>>>>>>
<<<<<<<<<<
>>>>>>>>>>
<<<<<<<<<<


El bucle exterior recorre `row` desde 10 hasta 1. El interior escribe diez caracteres por fila. Como la condición depende de `row`, todos los caracteres de una misma fila son iguales: `>` en las filas pares y `<` en las impares. La primera fila corresponde a `row = 10` y, por tanto, contiene `>`.

## 3.25. Factorial y aproximaciones mediante series

Los tres apartados utilizan `while`, como pide el enunciado. En las series, **N términos incluye el término inicial 1**: se suman los términos con índices de 0 a N − 1.

### a) Factorial

Archivo: `ejercicio_3_25_a_factorial.cpp`.

Se inicializa el resultado a 1 y se multiplica sucesivamente por los enteros desde `n` hasta 2. Para 0 y 1 no se entra en el bucle, por lo que se obtiene correctamente 1.

`n! = n · (n − 1) · ... · 2 · 1`, con `0! = 1`.

Para evitar el desbordamiento, el factorial se almacena como un vector de cifras decimales. Se multiplica cada cifra por el factor actual y se propaga el acarreo, como en una multiplicación a mano. Las cifras se guardan de menor a mayor peso y se imprimen en orden inverso. Es una alternativa sin dependencias externas al `cpp_int` que sugiere el enunciado. Todos los bucles son `while`. El tamaño calculable en la práctica depende de la memoria y del tiempo disponibles.

| Entrada | Resultado |
| --- | --- |
| 0 | 1 |
| 1 | 1 |
| 5 | 120 |
| 25 | 15511210043330985984000000 |

### b) Aproximación de e

Archivo: `ejercicio_3_25_b_constante_e.cpp`.

Se calcula:

`e_N = Σ(k = 0 ... N − 1) 1/k!`.

El término inicial vale 1. Cada término siguiente se obtiene dividiendo el anterior entre `k`, porque `1/k! = (1/(k − 1)!)/k`. Así se evita recalcular los factoriales y desbordarlos innecesariamente.

Con 1 término se obtiene 1; con 5 términos:

`1 + 1 + 1/2 + 1/6 + 1/24 = 2.708333333333...`.

Con 20 términos se obtiene aproximadamente `2.718281828459045`.

### c) Aproximación de eˣ

Archivo: `ejercicio_3_25_c_exponencial.cpp`.

Se pide tanto `x` como el número de términos, y se calcula:

`S_N(x) = Σ(k = 0 ... N − 1) x^k/k!`.

Se parte de `termino = 1` y se actualiza mediante `termino *= x/k`. Con `x = 1` se recupera el apartado b. Con `x = 0`, el resultado es 1 para cualquier número válido de términos. Con `x = 2` y 20 términos, el resultado se aproxima a `7.38905609893065`.

La cantidad de términos controla la truncación de la serie; no garantiza un número concreto de decimales correctos. El cálculo usa `long double`, cuya precisión es finita. Para valores negativos de gran magnitud, la cancelación entre términos puede reducir la exactitud; para valores muy grandes también puede alcanzarse el límite del tipo numérico. El programa detecta resultados no finitos.

## 3.26. Cifrado y descifrado

Archivos: `ejercicio_3_26_cifrar.cpp` y `ejercicio_3_26_descifrar.cpp`.

### Cifrado

1. Se separan las cuatro cifras originales `a`, `b`, `c`, `d`.
2. Cada cifra se transforma con `(cifra + 7) % 10`.
3. Se intercambian la primera con la tercera y la segunda con la cuarta: el orden final es `c`, `d`, `a`, `b` de las cifras ya transformadas.

Ejemplo:

```text
Original:       1234
Transformación: 8901
Cifrado:        0189
```

El programa exige un original entre 1000 y 9999. La salida siempre conserva cuatro posiciones, aunque empiece por cero.

### Descifrado

Se deshacen los intercambios y se aplica `(cifra + 3) % 10`. Sumar 3 deshace sumar 7 módulo 10, porque `7 + 3 = 10`.

```text
Cifrado:            0189
Deshacer cambios:   8901
Recuperar cifras:   1234
```

El descifrador lee exactamente cuatro dígitos para conservar ceros iniciales, como los de `0189` o `0000`. Otro caso de comprobación es `7777 → 4444 → 7777`.

Este es el procedimiento didáctico solicitado; su transformación es fija y fácilmente reversible.

## 4.15. Aproximación de π

Archivo: `ejercicio_4_15_pi.cpp`.

Se utiliza la serie de Leibniz:

`π_N = 4 · Σ(k = 0 ... N − 1) (−1)^k/(2k + 1)`.

El programa imprime una fila por cada uno de los primeros **200 000 términos**, con el número de términos acumulados y la aproximación correspondiente. Para guardar la tabla completa:

```bash
g++ -std=c++17 ejercicio_4_15_pi.cpp -o pi
./pi > tabla_pi.txt
```

Las primeras filas, con ocho decimales como en el enunciado, son:

| Términos | Aproximación |
| --- | --- |
| 1 | 4.00000000 |
| 2 | 2.66666667 |
| 3 | 3.46666667 |
| 4 | 2.89523810 |
| 5 | 3.33968254 |

**Respuesta: se necesitan 136 121 términos para obtener por primera vez una aproximación que empiece por `3.14159`.** En ese punto se obtiene aproximadamente `3.1415999999948`.

Se interpreta «empiece por» como pertenecer al intervalo `3.14159 ≤ aproximación < 3.14160`, antes de redondear. Por ello, esa primera aproximación se muestra como `3.14160000` en una tabla de ocho decimales, aunque sus cifras sin redondear empiezan por `3.14159`. El resumen final imprime más decimales para que se aprecie la diferencia.

A los 200 000 términos se obtiene aproximadamente `3.141587653589793`, que se muestra como `3.14158765`. Que una aproximación haya empezado por `3.14159` no implica que todas las siguientes lo hagan: la serie alterna aproximaciones por encima y por debajo de π.

## 4.6. Qué hace el código

El programa imprime un rectángulo de **10 filas y 5 columnas** formado por el carácter `@`:

```text
@@@@@
@@@@@
@@@@@
@@@@@
@@@@@
@@@@@
@@@@@
@@@@@
@@@@@
@@@@@
```

El bucle exterior se ejecuta diez veces. En cada una, el bucle interior imprime cinco `@` consecutivas y después se escribe un salto de línea. En total aparecen 50 caracteres `@`.

## 4.8. Producto de los enteros impares

Archivo: `ejercicio_4_8_producto_impares.cpp`.

Se inicializa el producto a 1 y se recorren los impares de 1 a 15 incrementando el contador de dos en dos.

`1 · 3 · 5 · 7 · 9 · 11 · 13 · 15 = 2 027 025`.

Salida:

```text
Producto = 2027025
```

## 5.1. Evaluación de expresiones

Se entiende que `x` es de tipo real, compatible con los resultados de las funciones matemáticas.

| Apartado | Instrucción | Valor de x | Explicación |
| --- | --- | --- | --- |
| a | `x = fabs(7.5);` | 7.5 | Valor absoluto. |
| b | `x = floor(7.5);` | 7.0 | Mayor entero menor o igual que 7.5. |
| c | `x = fabs(0.0);` | 0.0 | El valor absoluto de cero es cero. |
| d | `x = ceil(0.0);` | 0.0 | Cero ya es entero. |
| e | `x = fabs(-6.4);` | 6.4 | Elimina el signo negativo. |
| f | `x = ceil(-6.4);` | -6.0 | Menor entero mayor o igual que −6.4. |
| g | `x = ceil(-fabs(-8 + floor(-5.5)));` | -14.0 | Se evalúa desde dentro hacia fuera. |

Desarrollo de g:

```text
floor(-5.5) = -6
-8 + (-6) = -14
fabs(-14) = 14
-fabs(-14) = -14
ceil(-14) = -14
```

`floor` redondea hacia menos infinito; `ceil`, hacia más infinito. No equivalen, en general, a eliminar los decimales.

## 5.2. Tarifas de aparcamiento

Archivo: `ejercicio_5_2_aparcamiento.cpp`.

La función solicitada, `calculateCharges`, aplica:

- Hasta 3 horas: 20,00 dólares.
- Más de 3 horas: `20 + 5 · ceil(horas − 3)` dólares.
- En todos los casos válidos: máximo 50,00 dólares.

Se admiten tiempos mayores que 0 y menores o iguales a 24 horas. La función `ceil` hace que cualquier fracción de hora adicional cuente como una hora completa: por ejemplo, 3.1 horas cuestan 25,00 dólares y 4.1 horas cuestan 30,00 dólares.

Para las entradas `1.5`, `4.0` y `24.0`, la tabla es:

```text
Car          Hours      Charge
1              1.5       20.00
2              4.0       25.00
3             24.0       50.00
TOTAL         29.5       95.00
```

**Errata del dosier:** la imagen indica un total de 95.50, pero `20.00 + 25.00 + 50.00 = 95.00`. El programa muestra el total correcto.

## 5.6. Números aleatorios

Archivo: `ejercicio_5_6_aleatorios.cpp`.

El archivo contiene las seis instrucciones solicitadas, cada una asignando el resultado a `n`, y muestra el valor después de cada asignación. Se utiliza un generador `std::mt19937` inicializado una sola vez y `std::uniform_int_distribution<int>`.

| Apartado | Límite inferior | Límite superior | Cantidad de enteros posibles |
| --- | --- | --- | --- |
| a | 1 | 2 | 2 |
| b | 1 | 100 | 100 |
| c | 0 | 9 | 10 |
| d | 1000 | 1112 | 113 |
| e | -1 | 1 | 3 |
| f | -3 | 11 | 15 |

Ambos límites están incluidos. Los resultados concretos pueden cambiar en cada ejecución.

## 5.18. Inversión de cifras

Archivo: `ejercicio_5_18_invertir_cifras.cpp`.

La función `invertirCifras` extrae la última cifra con `% 10`, la incorpora al resultado mediante `invertido * 10 + cifra` y elimina la cifra procesada con `/ 10`. Repite el proceso hasta que el número queda en cero.

| Entrada | Resultado |
| --- | --- |
| 7631 | 1367 |
| 1200 | 21 |
| 0 | 0 |
| -7631 | -1367 |

Los ceros que quedarían al principio no se conservan porque el resultado es un número entero. Se usa `long long` y se comprueba el desbordamiento antes de construir cada nuevo resultado. Si el número invertido no cabe, el programa informa del error.

## 5.21. Lanzamiento de una moneda

Archivo: `ejercicio_5_21_moneda.cpp`.

La función independiente `flip()` no recibe argumentos y devuelve:

- `0`: cruz, mostrada como `Tails`.
- `1`: cara, mostrada como `Heads`.

El programa la llama 100 veces, muestra el resultado de cada lanzamiento y acumula dos contadores. Al terminar presenta las caras, las cruces y el total, que siempre debe ser 100.

Cada resultado tiene probabilidad 1/2. Se esperan aproximadamente 50 caras y 50 cruces, pero no se fuerza esa distribución: una ejecución puede producir, por ejemplo, 47 y 53.

## 5.26. Torres de Hanói

Archivo: `ejercicio_5_26_hanoi.cpp`.

La función recursiva `hanoi(discos, origen, destino, auxiliar)` recibe los cuatro parámetros pedidos.

1. Si hay un solo disco, lo mueve directamente del origen al destino: es el caso base.
2. Si hay más de uno, mueve `discos − 1` del origen al auxiliar usando el destino como apoyo.
3. Mueve el disco mayor del origen al destino.
4. Mueve `discos − 1` del auxiliar al destino usando el origen como apoyo.

Para tres discos, desde la varilla 1 hasta la 3:

```text
1 -> 3
1 -> 2
3 -> 2
1 -> 3
2 -> 1
2 -> 3
1 -> 3
```

El número de movimientos satisface `M(n) = 2 · M(n − 1) + 1`, con `M(1) = 1`. Por tanto, se necesitan `2^n − 1` movimientos: 7 para tres discos y 15 para cuatro.

Para 64 discos serían `18 446 744 073 709 551 615` movimientos. El programa imprime todos los movimientos, de modo que conviene probarlo con cantidades pequeñas de discos. La profundidad de recursión es proporcional a `n`, mientras que el tiempo y la cantidad de líneas crecen como `2^n`.

## Comprobaciones realizadas

Los doce programas se han compilado con GCC en C++17, con `-Wall -Wextra -Wpedantic`, sin avisos. Se han comprobado factoriales hasta 1000!, las series, la recuperación de originales cifrados, el producto de impares, las tarifas y sus fracciones de hora, la inversión de cifras y su desbordamiento, los intervalos aleatorios, los 100 lanzamientos de moneda, las 200 000 filas de π y los movimientos legales de Hanói para entre 1 y 8 discos. También se han probado entradas fuera del dominio de los ejercicios.

## Entrega

El dosier solicita entregar un enlace de GitHub que contenga los códigos. Los doce archivos C++ y este documento están preparados para subirlos a un repositorio; cada archivo se ejecuta de forma independiente.
