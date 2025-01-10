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
    Node* node = root;
    stack<Node*> st;

    while(true){
        if(node != NULL){
            // store and move to the left 
            st.push(node);
            node = node->left;
        }else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            // move the node to the right 
            node = node->right;
        }
    }
    return ans;
}

int main(){
    return 0;
}