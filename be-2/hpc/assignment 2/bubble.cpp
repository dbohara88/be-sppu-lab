#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

using namespace std;
using namespace std::chrono;

void parallelBubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < n - 1; i++) {
            swapped = false;

            #pragma omp for
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }

            if (!swapped) {
                // If no swap occurred in the inner loop, the array is already sorted
                break;
            }
        }
    }
}

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
            // If no swap occurred in the inner loop, the array is already sorted
            break;
        }
    }
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
    auto startSeq = high_resolution_clock::now();
    sequentialBubbleSort(seqArr);
    auto endSeq = high_resolution_clock::now();
    double seqTime = duration_cast<milliseconds>(endSeq - startSeq).count();

    // Perform parallel bubble sort
    vector<int> parArr = arr;
    auto startPar = high_resolution_clock::now();
    parallelBubbleSort(parArr);
    auto endPar = high_resolution_clock::now();
    double parTime = duration_cast<milliseconds>(endPar - startPar).count();

    // Display sorted arrays and performance results
    cout << "Sequential Bubble Sort Result: ";
    for (int num : seqArr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Sequential Bubble Sort Time: " << seqTime << " milliseconds" << endl;

    cout << "Parallel Bubble Sort Result: ";
    for (int num : parArr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Parallel Bubble Sort Time: " << parTime << " milliseconds" << endl;

    return 0;
}
