
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <omp.h>
#include <stdio.h>
#include <random>

using namespace std;
using namespace std::chrono;
int random_in_range( int minimum, int maximum )
{
    thread_local std::ranlux48 rng(
    std::chrono::system_clock::now().time_since_epoch().count() );
    return std::uniform_int_distribution <int> ( minimum, maximum )( rng );
}
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

void sequentialBubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    }
    endtime = system_clock::now();
    duration <double> time= endtime - starttime;
    cout<<"Time for serial: "<<1000*time.count()<<" milliseconds"<<endl;
}
void bubbleSortOddEven(int b[], int n)
{
    time_point<system_clock> starttime, endtime;
    starttime = system_clock::now();
    int pass;
    for(int i = 0 ; i < n-1 ; i++)
    {
        pass = i % 2;
        for (int j = pass ; j < n-1 ; j+=2)
        {
            if(b[j]>b[j+1])
            {
                int temp = b[j];
                b[j] = b[j+1];
                b[j+1]=temp;
            }

        if (!swapped) {
            break;
        }
    }
    endtime = system_clock::now();
    duration<double> time = endtime - starttime;
    cout<<"Time for Bubble sort (Odd Even Transposition): "<<1000*time.count()<<"milliseconds"<<endl;
}
void bubbleSortParallel(int b[], int n)
{
    time_point<system_clock> starttime, endtime;
    starttime = system_clock::now();
    int pass;
    omp_set_num_threads(2);
    for(int i = 0 ; i < n-1 ; i++)
    {
        pass = i % 2;
        #pragma omp parallel for
        for (int j = pass ; j < n-1 ; j+=2)
        {
            if(b[j]>b[j+1])
            {
                int temp = b[j];
                b[j] = b[j+1];
                b[j+1]=temp;

void parallelBubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    do {
        swapped = false;

        #pragma omp parallel for shared(arr, swapped)
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    }
    endtime = system_clock::now();
    duration<double> time = endtime - starttime;
    cout<<"Time for Parallel: "<<1000*time.count()<<" milliseconds"<<endl;

        #pragma omp barrier
    } while (swapped);
}
void init_array(int *arr1, int *arr2, int *arr3, int n) {
    for(int i = 0 ; i < n ; i++) {
    arr1[i] = arr2[i] = arr3[i] = random_in_range(10,999);

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}
void print_array(int *arr, int n) {
    for(int i = 0 ; i < n ; i++) {
    cout<<arr[i]<<" ";

    // Perform sequential bubble sort
    vector<int> seqArr = arr;
    double startSeq = omp_get_wtime();
    sequentialBubbleSort(seqArr);
    double endSeq = omp_get_wtime();
    double seqTime = endSeq - startSeq;

    // Perform parallel bubble sort
    vector<int> parArr = arr;
    double startPar = omp_get_wtime();
    parallelBubbleSort(parArr);
    double endPar = omp_get_wtime();
    double parTime = endPar - startPar;

    // Display sorted arrays and performance results
    cout << "Sequential Bubble Sort Result: ";
    for (int num : seqArr) {
        cout << num << " ";
    }
}
int main()
{
    int n = 50;
    int *a, *b, *c;
    a = new int[n];
    b = new int[n];
    c = new int[n];
    init_array(a, b, c, n);
    cout<<"Initial vector: "<<endl;
    print_array(a, n);
    cout<<endl;
    cout<<endl;
    bubbleSortSerial(a,n);
    cout<<"Result after serial bubble sort: "<<endl;
    print_array(a, n);
    cout<<endl;
    cout<<endl;
    bubbleSortOddEven(c,n);
    cout<<"Result after odd-even sort: "<<endl;
    print_array(c, n);
    cout<<endl;
    cout<<endl;
    bubbleSortParallel(b,n);
    cout<<"Result after parallel bubble sort: "<<endl;
    print_array(b, n);
    cout<<endl;
    cout << endl;
    cout << "Sequential Bubble Sort Time: " << seqTime * 1000 << " milliseconds" << endl;

    cout << "Parallel Bubble Sort Result: ";
    for (int num : parArr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Parallel Bubble Sort Time: " << parTime * 1000 << " milliseconds" << endl;

    return 0;
}
}
