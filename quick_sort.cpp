#include <iostream>
using namespace std;

int partitionArr(int *arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;

    for(int j = l; j < r; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int *arr, int l, int r) {
    if(l < r) {
        int pi = partitionArr(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    delete[] arr;
    return 0;
}

