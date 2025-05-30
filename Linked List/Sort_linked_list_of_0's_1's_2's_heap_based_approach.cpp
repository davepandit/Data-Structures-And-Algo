/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // we will use a min heap wala priority queue 
        priority_queue<int, vector<int>, greater<int>> pq;
        
        Node* node = head;
        while(node){
            pq.push(node->data);
            // move the node ahead 
            node = node->next;
        }
        
        // now we can keep on taking the ele from the heap
        node = head;
        while(!pq.empty() && node){
            // take out the ele 
            node->data = pq.top();
            pq.pop();
            
            node = node->next;
        }
        
        return head;
        
    }
};