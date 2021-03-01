#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <omp.h>

using namespace std;

int main()
{

    int i, n{10};
    vector<double> a(n, 1), b(n, 111);

    /// Gerar vetor
    for (i = 0; i < n; i++)
        a[i] = i + 1;

/// Região paralela com um número padrão de threads
/// A variável i será feita privada para cada thread por padrão. Você poderia fazer isso explicitamente com a clausula private(i)
#pragma omp parallel for
    {
        for (i = 1; i < n; i++)
        {
            b[i] = (a[i] + a[i - 1]) / 2.0;
        }
    } // fim da região paralela

    for (int ii = 0; ii < n; ii++)
    {
        cout << ii << '\t' << a[ii] << '\t' << b[ii] << endl;
    }
    return 0;
}