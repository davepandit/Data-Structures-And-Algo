#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = nullptr;
    }
};

ListNode* sortLL(ListNode* head){
        ListNode* temp = head;
        ListNode* j;
        while(temp){
            j = temp->next;
            ListNode* min = temp;
            while(j){
                if(j->val < min->val){
                    min = j;
                }
                // move the pointer 
                j = j->next;
            }
            // swap and then move the pointer 
            swap(temp->val, min->val);
            temp = temp->next;
        }


        return head;
}

// Utility function to print a linked list
void printLL(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create the original linked list
    vector<int> arr = {4, 3, 2, 1, 6};
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    ListNode* new_head = sortLL(head);
    printLL(new_head);

    return 0;
}
