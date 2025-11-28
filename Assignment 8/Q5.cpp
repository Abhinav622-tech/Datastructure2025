#include <iostream>
using namespace std;

// ------------------------
//   MAX HEAPIFY
// ------------------------
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// ------------------------
//   MIN HEAPIFY
// ------------------------
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// ----------------------------------------------------------
//   HEAPSORT FOR INCREASING ORDER USING MAX HEAP
// ----------------------------------------------------------
void heapSortIncreasing(int arr[], int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // move largest to end
        maxHeapify(arr, i, 0);
    }
}

// ----------------------------------------------------------
//   HEAPSORT FOR DECREASING ORDER USING MIN HEAP
// ----------------------------------------------------------
void heapSortDecreasing(int arr[], int n) {
    // Build min heap
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // move smallest to end
        minHeapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {10, 3, 6, 1, 15, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int incArr[n];   // copy for increasing
    int decArr[n];   // copy for decreasing

    // copy arrays
    for (int i = 0; i < n; i++) {
        incArr[i] = arr[i];
        decArr[i] = arr[i];
    }

    heapSortIncreasing(incArr, n);
    heapSortDecreasing(decArr, n);

    cout << "Sorted Increasing Order: ";
    for (int x : incArr) cout << x << " ";
    cout << endl;

    cout << "Sorted Decreasing Order: ";
    for (int x : decArr) cout << x << " ";
    cout << endl;

    return 0;
}
