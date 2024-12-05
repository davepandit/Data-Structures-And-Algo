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
    stack<int> st;
    Node* temp = head;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    while(temp){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
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