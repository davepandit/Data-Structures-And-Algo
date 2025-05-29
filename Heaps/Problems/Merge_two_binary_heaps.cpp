// User function Template for C++

class Solution {
  public:
    void heapifyDown(vector<int>& heap, int n, int i){
        int left = (2 * i + 1);
        int right = (2 * i + 2);
        
        int largest = i;
        
        if(left < n && heap[left] > heap[largest]){
            largest = left;
        }
        
        if(right < n && heap[right] > heap[largest]){
            largest = right;
        }
        
        if(largest != i){
            swap(heap[largest], heap[i]);
            // call the heapify function again
            heapifyDown(heap, n, largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // we can use the heapify down method to do the heavy lifting 
        // copy the ele of the of the two vectors into one 
        int size = n + m;
        vector<int> heap;
        
        for(auto it : a){
            heap.push_back(it);
        }
        
        for(auto it : b){
            heap.push_back(it);
        }
        
        
        for(int i = (size - 1) / 2; i >= 0; --i){
            heapifyDown(heap, size, i);
        }
        
        // now we have a max heap
        return heap;
        
    }
};