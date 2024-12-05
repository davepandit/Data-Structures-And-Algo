#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = nullptr;
        }
};

Node* check_pallindrome(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    Node* front;
    while(temp){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

int main(){
    vector<int> arr = {1, 2, 3, 2, 1};
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    // tortoise hare method
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // move the fast
    fast = head;
    while(fast != NULL && fast->next != slow){
        fast = fast->next;
    }
    Node* new_head = check_pallindrome(slow);
    fast->next = new_head;
    // traverse the linked list 
    Node* temp = new_head;
    while(head != new_head){
        if(temp->data == head->data){
            head = head->next;
            temp = temp->next;
        }
        else{
            cout<< "false" << endl;
            return 0;
        }
    }

    cout<< "true"<< endl;
    return 0;
}