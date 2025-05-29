// this is a valid sort which prints the ele in the ascending order 
// time complexity -> O(nlogn)
// space complexity -> O(n)
// we dont want this O(n) time complexity and thats why we will changing the arraay in
// place to create a max heap

#include <bits/stdc++.h>
using namespace std;

void heapifyDown(vector<int>& heap, int i){
    int n = heap.size();

    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    int largest = i;

    if(left < n && heap[left] > heap[largest]){
        largest = left;
    }

    if(right < n && heap[right] > heap[largest]){
        largest = right;
    }

    if(largest != i){
        swap(heap[i], heap[largest]);
        // call the function again 
        heapifyDown(heap, largest);
    }
}

void heapSort(vector<int>& heap){
    int n = heap.size();

    // convert this array into a heap
    // we can use the heapifyDown function also or 
    // we can use the pq method too 

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; ++i){
        pq.push(heap[i]);
    }

    // we are ready with the max heap 
    for(int i = 0; i < n; ++i){
        heap[i] = pq.top();
        pq.pop();
    }
}

int main(){
    vector<int> binaryTree = {2, 5, 1, 45, 23, 22};
    heapSort(binaryTree);

    for(auto it : binaryTree){
        cout << it << " ";
    }
    return 0;
}