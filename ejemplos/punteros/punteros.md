# Punteros y matrices

&nbsp;
Un puntero es una variable que almacena la dirección de memoria de otra variable.
Con el operador `*` se puede *desreferenciar* un puntero, mostrando el contenido de la variable apuntada:

```cpp
int num = 10;
int *pNum = &num;
std::cout << "Contenido de num: " << *pNum << "\n"; // Imprime 10 (dereferenciación)
std::cout << "Contenido de pNum: " << pNum << "\n"; // Imprime la dirección de num
std::cout << "Dirección de pNum: " << &pNum << "\n"; // Imprime la dirección de pNum
```

&nbsp;
Pero si en vez de tratarse de una variable que almacene enteros se tratase de una variable que a su vez almacene otro puntero, al dereferenciar se mostraría una dirección, que a su vez se puede volver a desreferenciar:

```cpp
int **pPun = &pNum;
std::cout << "Contenido de pNum: " << *pPun << "\n"; // Imprime la dirección de num (dereferenciación)
std::cout << "Contenido de num: " << **pPun << "\n"; // Imprime 10 (dereferenciación)
```

&nbsp;
Un vector es un puntero que puede pegar saltos en la memoria a partir de la dirección que almacena.
Dado que matemáticamente una matriz es un vector de vectores, una matriz es un puntero de punteros.
Esto es, una variable que contiene las direcciones en memoria de los vectores que componen la matriz.

```cpp
const int FILA = 2;
const int COL = 3;
int m[FILA][COL];
m[0][0] = 10;
std::cout << "Contenido de m[0][0]: " << **m << "\n"; // Imprime 10 (dereferenciación)
```

&nbsp;
La forma tradicional de recorrer una matriz es usando la notación con corchetes:

```cpp
for (int i = 0; i < FILA; i++)
{
    for (int j = 0; j < COL; j++)
    {
        m[i][j] = 0;
    }
}
```

&nbsp;
Pero por aritmética de punteros, es posible sumar un entero a una dirección de memoria para avanzar al siguiente espacio.
La unidad está definida por el tipo de dato.
Sumar 1 a la dirección de una variable entera implica avanzar 4 bytes.
Así, podemos recorrer una matriz dereferenciándola:

```cpp
for (int i = 0; i < FILA; i++)
{
    for (int j = 0; j < COL; j++)
    {
        *(*(m + i) + j) = 0;
    }
}
```

Donde:

- `m + i` avanza a la siguiente dirección a medida que aumenta `i`.
- `*(m + i)` es la *primera* dereferenciación de `m`, que accede a direcciones de memoria, equivalente a `*pPun`.
- `*(m + i) + j` avanza a la siguiente dirección a medida que aumenta `j`.
- `*(*(m + i) + j)` es la *segunda* dereferenciación de `m`, que asigna el contenido, equivalente a `**pPun`.

&nbsp;
Ahora bien, en realidad una matriz no es un puntero que tenga cualquier grupo de punteros, sino que tienen que ser **contiguos**.
Por esto se dice que una matriz es un arreglo, ya que está ubicada en memoria como un bloque contiguo de datos.
Así, podemos recorrer una matriz usando punteros

```cpp
for (int (*i)[COL] = m; i < m + FILA; i++)
{
    for (int *j = *i; j < (*i) + COL; j++)
    {
        *j = 0;
    }
}
```

Donde:

- `i` no es un entero, sino un puntero a una fila (osea a un vector).
- `j` no es un entero, sino un puntero a un entero.
- `m` es un puntero que tiene la dirección inicial de la matriz.