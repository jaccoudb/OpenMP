#include <iostream>
#include <omp.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> a {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // inicializa
    vector<int> b {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // inicializa

    for(auto x : b)
        cout << x << endl;

    int max, min;
    min = *min_element(a.begin(),a.end());
    max = *max_element(a.begin(),a.end());

    /// sections: Divide o trabalho em secções discretas, distintas, que são executadas pelos threads. 
    /// Pode ser usado para paralelismo funcional.
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            for (int i = 0; i < 10; i++)
                if (min > a[i])
                    min = a[i];
        }

        #pragma omp section
        {
            for (int i = 0; i < 10; i++)
                if (max < b[i])
                    max = b[i];
        }
    }

    cout << "min: " << min << "max: " << max << endl;
    
    return 0;
}