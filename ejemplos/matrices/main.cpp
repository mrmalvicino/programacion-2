#include <iostream>

int main()
{
    const int M = 2;
    const int N = 3;
    int m[M][N];

    // Carga la matriz:

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m[i][j] = i + j + i * M + 1;
        }
    }

    // Muestra la matriz:

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << m[i][j];
            std::cout << "\t";
        }

        std::cout << "\n";
    }

    return 0;
}