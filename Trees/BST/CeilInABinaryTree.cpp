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

int findCeil(Node* root, int key){
    Node* node = root;
    int ceil = root->data; // can assign anything to anything

    while(node){
        if(node->data < key){
            node = node->right;
        }
        else if(node->data == key){
            return node->data;
        }
        else if(node->data > key){
            ceil = node->data;
            node = node->left;
        }
    }

    return ceil;
}

int main(){
    Node* root = new Node(10);
    int ans = findCeil(root, 4);
    cout << ans;
    return 0;
}