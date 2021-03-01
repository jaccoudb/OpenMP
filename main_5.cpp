#include <iostream>
#include <omp.h>
#include <random>

#define amostra 50

using namespace std;

int main()
{

    /// Semente randômica
    std::mt19937 gen{std::random_device()()};
    /// Gera um número de uma distribuição uniforme entre 0 e amostra;
    std::uniform_int_distribution<> Uid(0, amostra);

    int linha{6};
    int coluna{8};
    int d[linha][coluna];

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            d[i][j] = Uid(gen);
            cout << d[i][j] << '\t';
        }
        cout << endl;
    }

    cout << endl
         << endl;

/// sections: Divide o trabalho em secções discretas, distintas, que são executadas pelos threads.
/// Pode ser usado para paralelismo funcional.
#pragma omp parallel sections firstprivate(linha, coluna)
    {
#pragma omp section
        {
            int elements{0};
            int sum{0};
            for (int i = 0; i < linha; i++)
            {
                for (int j = 0; j < coluna; j++)
                {
                    sum += d[i][j];
                    elements++;
                }
            }
            printf("Media %.2f; Thread: %d \n", sum * 1.0 / elements, omp_get_thread_num());
        }

#pragma omp section
        {
            int min = amostra + 1;
            int max = -1;
            for (int i = 0; i < linha; i++)
            {
                for (int j = 0; j < coluna; j++)
                {
                    if (min > d[i][j])
                    {
                        min = d[i][j];
                    }
                    if (max < d[i][j])
                    {
                        max = d[i][j];
                    }
                }
            }
            printf("Max: %d; Min: %d; Thread: %d\n", max, min, omp_get_thread_num());
        }

#pragma omp section
        {
            int sum = 0;
            for (int i = 0; i < linha; i++)
            {
                for (int j = 0; j < coluna; j++)
                {
                    if (d[i][j] % 3 == 0)
                    {
                        sum += d[i][j];
                    }
                }
            }
            printf("Soma dos Multiplos de 3: %d; Thread: %d\n", sum, omp_get_thread_num());
        }
    }
    return 0;
}