#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
        int data;
        Node* left;
        Node* right;

    
        Node(int val){
            data = val;
        }
};

void preOrder(Node* root, vector<string>& arr){
    if(root == NULL){
        arr.push_back("null");
        return;
    }

    // recursive preorder traversal
    arr.push_back(to_string(root->data)); 
    preOrder(root->left, arr);
    preOrder(root->right, arr);
}

bool check(Node* p, Node* q){
    vector<string> p1;
    vector<string> p2;

    preOrder(p, p1);
    preOrder(q, p2);

    // here we have the updated p1 and p2
    // now we can compare 
    if(p1.size() != p2.size()){
        return false;
    }

    // check the 2 arrays
    for(int i = 0; i < p1.size(); i++){
        if(p1[i] != p2[i]){
            return false;
        }
    }
    // here return true
    return true;
}

int main(){
    Node* p = new Node(1);
    Node* q = new Node(2);
    return 0;
}