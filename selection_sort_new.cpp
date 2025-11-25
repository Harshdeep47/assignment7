#include <iostream>
using namespace std;

void improvedSelectionSort(int *arr, int n) {
    int left = 0, right = n - 1;

    while(left < right) {
        int minIdx = left, maxIdx = left;

        for(int i = left; i <= right; i++) {
            if(arr[i] < arr[minIdx]) minIdx = i;
            if(arr[i] > arr[maxIdx]) maxIdx = i;
        }

        swap(arr[left], arr[minIdx]);

        if(maxIdx == left)
            maxIdx = minIdx;

        swap(arr[right], arr[maxIdx]);

        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    delete[] arr;
    return 0;
}

