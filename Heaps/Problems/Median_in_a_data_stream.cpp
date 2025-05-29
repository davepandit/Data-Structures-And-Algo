class MedianFinder {
private:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
public:
    MedianFinder() {
        
    }
    void balanceHeaps(){
        // if right min heap ka size > left max heap then move one ele from right min heap to left max heap
        // if left max heap me no of ele > right min heap + 1 then put one ele from left max heap to right min heap
        if(rightMinHeap.size() > leftMaxHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
        else if(leftMaxHeap.size() > rightMinHeap.size() + 1){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
    }
    void addNum(int num) {
        if(leftMaxHeap.empty()){
            leftMaxHeap.push(num);
        }
        else if(num > leftMaxHeap.top()){
            // insert into the right half 
            rightMinHeap.push(num);
        }
        else if(num <= leftMaxHeap.top()){
            // insert into the left half 
            leftMaxHeap.push(num);
        }

        // now we need to balance the heaps 
        balanceHeaps();
    }
    
    double findMedian() {
        // if left max heap ka size == right min heap ka size then left max heap ka top and right min heap ka top ka mean lena hai 
        // else left max ka top is the ans 

        if(leftMaxHeap.size() > rightMinHeap.size()){
            return double(leftMaxHeap.top());
        }
        else if(leftMaxHeap.size() == rightMinHeap.size()){
            return (leftMaxHeap.top() + rightMinHeap.top()) / double(2);
        }

        // the control will never reach here
        return 1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */