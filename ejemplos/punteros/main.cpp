#include <iostream>

int main()
{
    // Puntero de entero

    int num = 10;
    int *pNum = &num;
    std::cout << "Contenido de num: " << *pNum << "\n"; // Imprime 10 (dereferenciación)
    std::cout << "Contenido de pNum: " << pNum << "\n"; // Imprime la dirección de num
    std::cout << "Dirección de pNum: " << &pNum << "\n"; // Imprime la dirección de pNum

    // Puntero de puntero

    int **pPun = &pNum;
    std::cout << "Contenido de pNum: " << *pPun << "\n"; // Imprime la dirección de num (dereferenciación)
    std::cout << "Contenido de num: " << **pPun << "\n"; // Imprime 10 (dereferenciación)

    // Definición de una matriz

    const int FILA = 2;
    const int COL = 3;
    int m[FILA][COL];
    m[0][0] = 10;
    std::cout << "Contenido de m[0][0]: " << **m << "\n"; // Imprime 10 (dereferenciación)

    // Recorrido tradicional

    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            m[i][j] = 0;
        }
    }

    // Recorrido usando punteros de punteros

    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            *(*(m + i) + j) = 0;
        }
    }

    // Recorrido usando arreglos

    for (int (*i)[COL] = m; i < m + FILA; i++)
    {
        for (int *j = *i; j < (*i) + COL; j++)
        {
            *j = 0;
        }
    }

    return 0;
}