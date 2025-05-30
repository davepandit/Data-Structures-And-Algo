/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        int lastDigit = 0, carry = 0, sum = 0;

        // we need to create the first node first
        sum = head1->val + head2->val;
        lastDigit = sum % 10;
        carry = sum / 10;
        ListNode* newHead = new ListNode(lastDigit);
        // move the heads to the next 
        head1 = head1->next;
        head2 = head2->next;

        // since i dont want to tamper the new head so i will create a temp
        ListNode* temp = newHead;

        while(head1 && head2){
            // jab tak ye dono valid hai tab tak to data ko we can simply add 
            sum = head1->val + head2->val + carry;
            // if sum is a 2 digit no then we need to store the last digit 
            // in one node and the other digit should be send as carry 
            lastDigit = sum % 10;
            carry = sum / 10;
            // create a new node with lastDigit and add carry to the sum 
            ListNode* newNode = new ListNode(lastDigit);
            temp->next = newNode;
            temp = temp->next;

            // move the heads to the next pointer 
            head1 = head1->next;
            head2 = head2->next;
        }

        while(head1){
            sum = head1->val + carry;
            lastDigit = sum % 10;
            carry = sum / 10;

            // make a node 
            ListNode* newNode = new ListNode(lastDigit);
            temp->next = newNode;
            temp = temp->next;

            // move the head 
            head1 = head1->next;
        }

        while(head2){
            sum = head2->val + carry;
            lastDigit = sum % 10;
            carry = sum / 10;

            // make a node 
            ListNode* newNode = new ListNode(lastDigit);
            temp->next = newNode;
            temp = temp->next;

            // move the head 
            head2 = head2->next;
        }

        if(carry != 0){
            // we need to create one more node 
            ListNode* tail = new ListNode(carry);
            temp->next = tail;
        }

        return newHead;
    }
};