/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        DLLNode* node = head;
        DLLNode* temp = NULL;
        
        while(node){
            node->prev = node->next;
            node->next = temp;
            
            // move temp to node 
            temp = node;
            
            // move node forward 
            node = node->prev;
        }
        
        return temp;
        
    }
};