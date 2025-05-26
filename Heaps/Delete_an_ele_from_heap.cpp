#include <iostream>
#include <vector>
using namespace std;

void heapifyDown(vector<int>& heap, int i, int n) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;
    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDown(heap, largest, n);
    }
}

void heapifyUp(vector<int>& heap, int i) {
    if (i == 0) return;

    int parent = (i - 1) / 2;
    if (heap[parent] < heap[i]) {
        swap(heap[parent], heap[i]);
        heapifyUp(heap, parent);
    }
}

void deleteAtIndex(vector<int>& heap, int i) {
    int n = heap.size();
    if (i >= n) return;

    // Step 1: Replace the element with the last one
    heap[i] = heap[n - 1];

    // Step 2: Remove the last element
    heap.pop_back();

    // Step 3: Restore heap property
    if (i < heap.size()) {
        heapifyDown(heap, i, heap.size());
        heapifyUp(heap, i);
    }
}

void printHeap(const vector<int>& heap) {
    for (int val : heap)
        cout << val << " ";
    cout << endl;
}

// Sample usage
int main() {
    vector<int> maxHeap = {90, 80, 70, 60, 50, 65, 55};

    cout << "Initial Max Heap:\n";
    printHeap(maxHeap);

    int deleteIndex = 1; // delete 80
    deleteAtIndex(maxHeap, deleteIndex);

    cout << "\nMax Heap after deleting index " << deleteIndex << ":\n";
    printHeap(maxHeap);

    return 0;
}
