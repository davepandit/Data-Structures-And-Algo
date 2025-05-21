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

vector<int> post_order_traversal(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    stack<Node*> st1, st2;
    // push the root into the stack1
    st1.push(root);
    while(!st1.empty()){
         Node* node = st1.top();
         st1.pop();

         // place it in the stack 2
         st2.push(node);
         // check whether the node has a left child and a right child and then take a decision on that basis
         if(node->left != NULL){
            st1.push(node->left);
         }
         if(node->right != NULL){
            st1.push(node->right);
         }
    }

    // now the stack 2 is ready with the ans
    while(!st2.empty()){
        Node* node = st2.top();
        st2.pop();
        ans.push_back(node->data);
    }

    return ans;
}

int main(){
    Node* root = new Node(1);
    vector<int> ans = post_order_traversal(root);
    return 0;
}