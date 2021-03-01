#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int a{0}, b{0};

	cout << endl;
	cout << "#Valor Inicial - a: " << a << " ; b: " << b << endl;
	cout << endl;

	/// Cada thread obtém sua própria cópia de b com o valor inicial.
	/// private(var) cria um nova variável local para cada thread. Tem valor inicial não definido. Ao final retorna ao valor original.
	/// firstprivate(var) cria um nova variável local para cada thread. Tem valor inicial definido. Ao final retorna ao valor original.
	#pragma omp parallel num_threads(2) private(a) firstprivate(b)
	{
		a = 0; // Inicializa variável
		a += omp_get_thread_num();
		b += omp_get_thread_num();
		printf("#Valor Durante Thread %d  - a:%d ; b:%d\n", omp_get_thread_num(), a, b);
	}

	cout << endl;
	printf("Valor Apos 1 Regiao Paralela - a:%d ; b:%d\n\n\n", a, b);

	cout << endl;

	#pragma omp parallel num_threads(4) shared(a) private(b)
	{
		b = 0; // Inicializa variável
		#pragma omp atomic
		a -= omp_get_thread_num();
		b -= omp_get_thread_num();
		printf("#Valor Durante Thread %d - a:%d ; b:%d\n", omp_get_thread_num(), a, b);
	}

	cout << endl;
	printf("#Valor Apos Regiao Paralela - a:%d ; b:%d\n\n\n", a, b);

    return 0;
}