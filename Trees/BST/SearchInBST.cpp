#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

Node* search(Node* root, int targetValue){
    Node* node = root;
    while(node){
        if(node->data < targetValue){
            // move to the right 
            node = node->right;
        }
        else if(node->data == targetValue){
            return node;
        }
        else if(node->data > targetValue){
            // move to the left 
            node = node->left;
        }
    }

    // if we reach here, then node not found 
    return NULL;
}

int main(){
    Node* root = new Node(10);
    Node* ans = search(root, 10);
    cout << ans;
    return 0;
}