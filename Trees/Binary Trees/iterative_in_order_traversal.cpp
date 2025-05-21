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

vector<int> in_order_traversal(Node* root){
    vector<int> ans;
    stack<Node*> st;
    Node* node = root;

    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty() == true){
                break;
            }
            // take the top most ele from the stack 
            node = st.top();
            st.pop();
            // insert into the ans 
            ans.push_back(node->data);
            node = node->right;
        }
    }
}

int main(){
    Node* root = new Node(1);
    vector<int> ans = in_order_traversal(root);
    return 0;
}