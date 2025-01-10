#include <bits/stdc++.h>
using namespace std;

struct Node{
    // typical struct
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = right = NULL;
        }
};

vector<int> pre_order_traversal(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    stack<Node*> st;

    while(!st.empty()){
        // get the top ele 
        Node* node = st.top();
        // pop the top ele 
        st.pop();
        ans.push_back(node->data);

        // check whether there is some right child or there is some left child of the node 
        if(node->right != NULL){
            st.push(node->right);
        }
        if(node->left != NULL){
            st.push(node->left);
        }
    }

    return ans;
}
 
int main(){
    Node* root = new Node(1);
    vector<int> ans = pre_order_traversal(root);
    return 0;
}