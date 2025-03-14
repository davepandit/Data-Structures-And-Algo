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

void solve(Node* root, Node* &successor, int key){
    Node* node = root;
    while(node){
        if(node->data < key){
            // move to the right
            node = node->right;
        }
        else if(node->data > key){
            successor = node;
            // move to the left 
            node = node->left;
        }
    }
}

Node* findNode(Node* root, int key){
    Node* node = root;
    while(node){
        if(node->data == key){
            return node;
        }
        else if(node->data < key){
            node = node->right;
        }
        else if(node->data > key){
            node = node->left;
        }
    }

    return NULL;
}

Node* inorderSuccessor(Node* root, int key){
    if(root == NULL){
        return root;
    }
    // here i can check whether the key wala node exists in the tree or not 
    Node* keyNode = findNode(root ,key);

    if(!keyNode){
        return NULL;
    }
    
    Node* successor = NULL;
    solve(root, successor, key);

    return successor;
}

int main(){
    return 0;
}