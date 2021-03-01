#include <iostream>
#include <omp.h>

using namespace std;

int main()
{

/// Região paralela com um número padrão de threads
#pragma omp parallel
    {
        /// Função da biblioteca que retorna o thread ID.
        int thread_id = omp_get_thread_num();
        cout << "Thread" << thread_id << endl;

    } // fim da região paralela
    return 0;
}