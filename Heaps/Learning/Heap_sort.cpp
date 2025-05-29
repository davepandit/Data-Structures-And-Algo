#include <bits/stdc++.h>
using namespace std;

// Heapify function: maintains the max-heap property
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;         // Assume current index is the largest
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    // If left child is larger
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build a max-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {2, 5, 1, 45, 23, 22};

    heapSort(arr);

    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
