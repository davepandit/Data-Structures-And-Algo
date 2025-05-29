class Solution {
  public:
    void heapifyDown(long long heap[], long long n, long long i){
    
    
        long long left = (2 * i) + 1;
        long long right = (2 * i) + 2;
    
        long long largest = i;
    
        if(left < n && heap[left] > heap[largest]){
            largest = left;
        }
    
        if(right < n && heap[right] > heap[largest]){
            largest = right;
        }
    
        if(largest != i){
            swap(heap[i], heap[largest]);
            // call the function again 
            heapifyDown(heap, n, largest);
        }
    }
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // here we can apply the heap sort very easily 
        for (int i = N / 2 - 1; i >= 0; i--) {
            heapifyDown(A, N, i);
        }
        
        for (int i = N - 1; i >= 0; i--) {
            // Move current root to the end
            swap(A[0], A[i]);
    
            // Call heapify on the reduced heap
            heapifyDown(A, i, 0);
        }
        
        
        // now we have a sorted array A[]
        // k1th smallest will be available at the k1 - 1 th position in the array 
        // k2th smallest will be available at the k2 - 1 th position in the array 
        
        long long sum = 0;
        
        for (long long idx = K1; idx < K2 - 1 && idx < N; ++idx){
            sum += A[idx];
        }
            
        
        return sum;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};