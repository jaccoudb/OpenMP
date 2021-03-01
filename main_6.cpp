#include <iostream>
#include <omp.h>
#include <vector>

using namespace std;

int main()
{
    int size{10};
    vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b{10, 9, 8, 20, 6, 5, 30, 3, 40, 1};

    int sum_a{0}, sum_b{0};

    /// Dentro de uma região paralela ou de divisão de trabalho:
    /// Será feita uma cópia local de cada variável na lista
    /// Será inicializada dependendo da "op" (ex. 0 para "+").
    /// Atualizações acontecem na cópia local.
    /// Cópias locais são "reduzidas" para uma única variável original (global).
    #pragma omp parallel for reduction(+: sum_a) reduction(+: sum_b) firstprivate(size)
    {
        for (int i = 0; i < size; i++)
        {
            sum_a += a[i];
            sum_b += b[i];
        }
    }

    if (sum_a > sum_b)
    {
        printf("Media aritmetica da matriz A maior que B, sum_a = %d, sum_b = %d\n", sum_a / size, sum_b / size);
    }
    else
    {
        if (sum_a < sum_b)
        {
            printf("Media aritmetica da matriz B maior que B, sum_a = %d, sum_b = %d\n", sum_a / size, sum_b / size);
        }
        else
        {
            printf("Media aritmetica das matrizes sao iguais, sum_a = %d, sum_b = %d\n", sum_a / size, sum_b / size);
        }
    }

    return 0;
}