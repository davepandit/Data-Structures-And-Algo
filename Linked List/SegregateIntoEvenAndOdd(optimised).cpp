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

ListNode* segregateLL(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* even_copy = even;

    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = even_copy;
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
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    ListNode* new_head = segregateLL(head);
    printLL(new_head);

    return 0;
}
