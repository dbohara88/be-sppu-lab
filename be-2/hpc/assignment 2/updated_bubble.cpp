#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>

using namespace std;

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

        if (!swapped) {
            break;
        }
    }
}

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

        #pragma omp barrier
    } while (swapped);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

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
