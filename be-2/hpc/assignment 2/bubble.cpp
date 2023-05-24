#include <iostream>
#include <omp.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
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
      for (int i = 0; i < n - 1; i++) {
        int pass = i%2;
          #pragma omp parallel for
          for (int j = pass; j < n - 1; j+=2) {
              if (ar[j] > ar[j + 1]) {
                  int temp = ar[j];
                  ar[j] = ar[j + 1];
                  ar[j + 1] = temp;
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
    {
      ar[i] = rand()%100;
    }
    cout << "Before sorting: " << endl;
    for(int i=0; i<n; i++)
    cout << ar[i] << " ";
    cout << endl;
    cout << endl;

    auto start1 = high_resolution_clock::now();
    serialBubble(ar, n);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1-start1);
    cout << "After serial sorting: " << endl;
    for(int i=0; i<n; i++)
    cout << ar[i] << " ";
    cout << "time taken: " << duration1.count() << " milliseconds";
    cout << endl;
    cout << endl;
    auto start2 = high_resolution_clock::now();
    parallelBubble(ar, n);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2-start2);
    cout << "After parallel sorting: " << endl;
    for(int i=0; i<n; i++)
    cout << ar[i] << " ";
    cout << "time taken : " << duration2.count()<< " milliseconds";
    cout << endl;

    return 0;
}
