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

Node* segregateLL(Node* head){
    queue<Node*> q;
    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL && temp->next != NULL){
        prev = temp->next;
        temp->next = prev->next;
        prev->next = NULL;
        q.emplace(prev);
        temp = temp->next;
    }

    if(temp != NULL){
        while(!q.empty()){
            temp->next = q.front();
            q.pop();
            temp = temp->next;
        }
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        while (!q.empty())      
        {
            temp->next = q.front();
            q.pop();
            temp = temp->next;
        }
        
    }


    return head;
}

void printLL(Node* head){
    while(head){
        cout<< head->data << " ";
        head = head->next;
    }
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    Node* new_head = segregateLL(head);

    // print the ll
    printLL(new_head);

    return 0;
}