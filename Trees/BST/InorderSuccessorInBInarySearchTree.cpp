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

void solve(Node* node, Node* ans, int key){
    if(node == NULL){
        return;
    }
    solve(node->left, ans, key);
    if(node->data > key){
        if(ans == NULL){
            ans = node;
        }
    }
    solve(node->right, ans, key);
}

Node* findInorderSuccessor(Node* root, int key){
    // simply i will be doing am inorder traversal 
    // when i find a node that has value greater than key 
    // i can return it because the first value that i encounter 
    // greater than the key is going to be my answer because 
    // in the case of inorder traversal the order in which we get the ele is 
    // sorted
    Node* node = root;
    Node* ans = NULL;
    solve(node, ans, key);
    return ans;
}

int main(){
    return 0;
}