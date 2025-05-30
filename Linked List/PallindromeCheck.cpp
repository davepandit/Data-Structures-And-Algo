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
    ListNode* reverse(ListNode* head){
        if(head == NULL){
            return head;
        }
        ListNode* node = head;
        ListNode* prev = NULL;

        while(node){
            ListNode* front = node->next;
            node->next = prev;
            prev = node;
            node = front;
        }


        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // using the slow and the fast pointer 
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow->next is the new head in both the case when the lenght of the linked list is 
        // even or odd 

        ListNode* newHead = reverse(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;
        while(second){
            if(first->val != second->val){
                return false;
            }

            // move the pointers 
            first = first->next;
            second = second->next;
        }

        return true;
    }
};