#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int num{4}, thread_id{-1};

    cout << "Quantidade Threads:" << '\t' << omp_get_max_threads() << endl;

/// Testa se o número estipulado para threads é maior ou igual a 1.
/// Função que requer uma quantidade num de threads definida anteriormente.
/// thread_id não tem valor inicial definido.
/// num é uma variável compartilhada.
#pragma omp parallel if (num >= 1) num_threads(num) private(thread_id) shared(num)
    {
        /// Obtém o identificador de thread
        thread_id = omp_get_thread_num();
        
        printf("Thread %d: Entra!\n", thread_id);

        /// Teste para máximo de threads
        if (num != omp_get_num_threads())
            cout << "Error: NTHREADS" << endl;

        cout << "Thread " << thread_id << " Sai!" << endl;
    }

    cout << "Saida Thread " << thread_id << " Sai!" << endl;

    return 0;
}