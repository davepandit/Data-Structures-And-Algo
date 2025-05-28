void heapifyUp(vector<int>& heap, int i) {
    if (i == 0) return;

    int parent = (i - 1) / 2;
    if (heap[parent] < heap[i]) {
        swap(heap[parent], heap[i]);
        heapifyUp(heap, parent);
    }
}