#include <iostream>
#include <omp.h>
#include <ctime>
using namespace std;

void serialBubble(int ar[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(ar[j] > ar[j+1])
            {
                int temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
    }
}

void parallelBubble(int ar[], int n) {
    #pragma omp parallel
    {
        for (int i = 0; i < n - 1; i++) {
            #pragma omp for
            for (int j = 0; j < n - 1; j++) {
                if (ar[j] > ar[j + 1]) {
                    int temp = ar[j];
                    ar[j] = ar[j + 1];
                    ar[j + 1] = temp;
                }
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int *ar;
    ar = new int[n];
    for(int i=0; i<n; i++)
    cin >> ar[i];
    cout << "Before sorting: " << endl;
    for(int i=0; i<n; i++)
    cout << ar[i] << " ";
    cout << endl;
    cout << endl;
    clock_t start1 = clock();
    serialBubble(ar, n);
    clock_t end1 = clock();
    double duration1 = static_cast<double>(end1 - start1) / (CLOCKS_PER_SEC / 1000);
    cout.precision(3);
    cout << "After serial sorting: " << endl;
    for(int i=0; i<n; i++)
    cout << ar[i] << " ";
    cout << "time taken: " << fixed << duration1 << " milliseconds";
    cout << endl; 
    cout << endl;
    clock_t start2 = clock();
    parallelBubble(ar, n);
    clock_t end2 = clock();
    double duration2 = static_cast<double>(end2 - start2) / (CLOCKS_PER_SEC / 1000);
    cout << "After parallel sorting: " << endl;
    for(int i=0; i<n; i++)
    cout << ar[i] << " ";
    cout.precision(3);
    cout << "time taken : " << fixed << duration2 << " milliseconds";
    cout << endl; 

    return 0;
}
