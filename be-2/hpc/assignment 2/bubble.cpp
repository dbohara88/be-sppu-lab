#include <iostream>
#include <chrono>
#include <omp.h>

using namespace std;
using namespace std::chrono;

void bubbleSortSerial(int a[], int n)
{
    time_point<system_clock> starttime, endtime;
    starttime = system_clock::now();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    endtime = system_clock::now();
    duration <double> time= endtime - starttime;
    cout<<"Time for serial: "<<1000*time.count()<<" milliseconds"<<endl;
}

void bubbleSortParallel(int b[], int n)
{
    time_point<system_clock> starttime, endtime;
    starttime = system_clock::now();
    int pass;
    omp_set_num_threads(2);
    for (int i = 0; i < n-1; i++)
    {
        #pragma omp parallel for
        for (int j = 0; j < n-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    endtime = system_clock::now();
    duration<double> time = endtime - starttime;
    cout<<"Time for Parallel: "<<1000*time.count()<<" milliseconds"<<endl;
}
void init_array(int *arr1, int n) {
    for(int i = 0 ; i < n ; i++) {
    cin >> arr1[i];
    }
}
void print_array(int *arr, int n) {
    for(int i = 0 ; i < n ; i++) {
    cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    int *a;
    cin >> n;
    a = new int[n];
    init_array(a, n);
    cout<<"Initial vector: "<<endl;
    print_array(a, n);
    cout<<endl;
    cout<<endl;
    bubbleSortSerial(a,n);
    cout<<"Result after serial bubble sort: "<<endl;
    print_array(a, n);
    cout<<endl;
    cout<<endl;
    bubbleSortParallel(a,n);
    cout<<"Result after parallel bubble sort: "<<endl;
    print_array(a, n);
    cout<<endl;
    return 0;
}
