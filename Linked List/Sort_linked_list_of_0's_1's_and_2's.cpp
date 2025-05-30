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
        // we will be making 3 separate lists to maintian the 0's and 1's and 2's
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        
        
        while(head){
            if(head->data == 0){
                zero->next = head;
                // move the zero
                zero = zero->next;
            }
            else if(head->data == 1){
                one->next = head;
                // move the one
                one = one->next;
            }
            else{
                two->next = head;
                // move the two
                two = two->next;
            }
            
            // move the head
            head = head->next;
        }
        
        zero->next = oneHead->next ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr;
        
        return zeroHead->next;
        
        
    }
};