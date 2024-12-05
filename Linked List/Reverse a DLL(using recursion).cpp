#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;

        Node(int val){
            data = val;
            next = nullptr;
            back = nullptr;
        }
};

Node* reverseDLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while (temp)
    {
        Node* swap = temp->next;
        temp->next = temp->back;
        temp->back = swap;

        prev = temp;
        temp = temp->back;
    }
    
    return prev;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<< temp->data<< " ";
        temp = temp->next;
    }
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->back = mover;
        mover = temp;
    }

    head = reverseDLL(head);

    printLL(head);

    return 0;
}