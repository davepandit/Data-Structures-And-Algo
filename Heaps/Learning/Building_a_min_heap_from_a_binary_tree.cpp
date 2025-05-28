#include <iostream>
#include <vector>
using namespace std;

void heapifyDown(vector<int>& heap, int i, int n) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(heap, smallest, n);
    }
}

void buildMinHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n/2 - 1; i >= 0; i--) {
        heapifyDown(heap, i, n);
    }
}

int main() {
    vector<int> arr = {30, 10, 20, 15, 25};

    buildMinHeap(arr);

    cout << "Min Heap array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
