/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head){
        if(head == NULL){
            return head;
        }
        
        Node* prev = NULL;
        Node* node = head;
        
        while(node){
            Node* front = node->next;
            node->next = prev;
            prev = node;
            node = front;
        }
        
        return prev;
    }
    Node* addOne(Node* head) {
        // we will first reverse the linked list 
        Node* reversedHead = reverse(head);
        
        // this sum can be a two digit number and at max can be a 10
        int lastDigit = 0, carry = 0, sum = 0;
        
        sum = reversedHead->data + 1;
        lastDigit = sum % 10;
        carry = sum / 10;
        
        Node* newHead = new Node(lastDigit);
        Node* node = newHead;
        reversedHead = reversedHead->next;
        
        while(reversedHead){
            sum = reversedHead->data + carry;
            lastDigit = sum % 10;
            carry = sum / 10;
            
            // create a node with lastDigit and add carry to the next sum
            Node* newNode = new Node(lastDigit);
            node->next = newNode;
            node = node->next;
            reversedHead = reversedHead->next;
        }
        
        // after all this if there is some value of carry then 
        if(carry != 0){
            node->next = new Node(carry);
        }
        // now again we need to reverse the links 
        Node* ans = reverse(newHead);
        
        return ans;
        
        
        
        
        
        
        
        
    }
};