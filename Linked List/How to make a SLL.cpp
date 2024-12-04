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

int main(){
    vector<int> arr = {1, 2, 3, 4};
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    Node* temp = head;
    while(temp->next != NULL){
        cout<<temp->data<< " ";
        temp = temp->next;
    }
    return 0;
}