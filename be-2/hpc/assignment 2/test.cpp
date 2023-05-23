#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < leftArr.size())
        arr[k++] = leftArr[i++];

    while (j < rightArr.size())
        arr[k++] = rightArr[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

void parallelMergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSort(arr, left, mid);
            #pragma omp section
            mergeSort(arr, mid + 1, right);
        }
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr (n);
    for(int i=0; i<n; i++)
    cin >> arr[i];
    cout << "Original array: ";
    printArray(arr);

    clock_t start1 = clock();
    mergeSort(arr, 0, arr.size() - 1);
    clock_t end1 = clock();
    double duration1  = double(end1-start1) / CLOCKS_PER_SEC * 1000;
    cout << "\nSorted array: ";
    printArray(arr);
    cout <<"\n time taken: "<< duration1 << " miliseconds" << endl;

    clock_t start2 = clock();
    parallelMergeSort(arr, 0, arr.size() - 1);
    clock_t end2 = clock();
    double duration2  = double(end2-start2) / CLOCKS_PER_SEC * 1000;
    cout << "\nSorted array: ";
    printArray(arr);
    cout <<"\n time taken: "<< duration2 << " miliseconds" << endl;

    return 0;
}
