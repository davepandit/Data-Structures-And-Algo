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

// Function to segregate odd-indexed nodes
vector<ListNode*> segregateOddLL(ListNode* slow) {
    vector<ListNode*> v;
    ListNode* slow_copy = new ListNode(slow->val); // Create new list for odd-indexed nodes
    ListNode* prev = slow_copy;                   // Tail pointer for the odd list

    slow = slow->next ? slow->next->next : nullptr; // Move to the next odd-indexed node

    while (slow) {
        ListNode* temp = new ListNode(slow->val); // Create a new node
        prev->next = temp;                        // Link to the tail
        prev = temp;                              // Update the tail
        slow = slow->next ? slow->next->next : nullptr; // Move to the next odd-indexed node
    }

    prev->next = nullptr; // Properly terminate the list
    v.push_back(slow_copy); // Push the head of the odd list
    v.push_back(prev);      // Push the tail of the odd list
    return v;
}

// Function to segregate even-indexed nodes
ListNode* segregateEvenLL(ListNode* fast) {
    if (!fast) return nullptr;

    ListNode* fast_copy = new ListNode(fast->val); // Create new list for even-indexed nodes
    ListNode* prev = fast_copy;                   // Tail pointer for the even list

    fast = fast->next ? fast->next->next : nullptr; // Move to the next even-indexed node

    while (fast) {
        ListNode* temp = new ListNode(fast->val); // Create a new node
        prev->next = temp;                        // Link to the tail
        prev = temp;                              // Update the tail
        fast = fast->next ? fast->next->next : nullptr; // Move to the next even-indexed node
    }

    prev->next = nullptr; // Properly terminate the list
    return fast_copy;
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
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    // Get the odd-indexed and even-indexed lists
    ListNode* slow = head;
    ListNode* fast = head->next;
    vector<ListNode*> pointers = segregateOddLL(slow); // Odd-indexed list
    ListNode* start = segregateEvenLL(fast);           // Even-indexed list

    // Link the two lists
    pointers[1]->next = start;

    // Print the combined linked list
    printLL(pointers[0]);

    return 0;
}
