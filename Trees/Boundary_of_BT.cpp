#include <bits/stdc++.h>
using namespace std;


struct Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

bool isLeafNode(Node* node){
    if(node == NULL){
        return false;
    }
    if(node->left == NULL && node->right == NULL){
        // then that is a leaf node 
        return true;
    }

    // otherwise that is not a lead node
    return false;
}

void addLeftEle(Node* root, vector<int>& res){
    Node* curr = root->left;
    while(curr){
        if(!isLeafNode(curr)){
            res.push_back(curr->data);
        }
        if(curr->left != NULL){
            // then move to the left 
            curr = curr->left;
        }else{
            // move to the right 
            curr = curr->right;
        }
    }
}

void addLeafNodes(Node* root, vector<int>& res){
    // first check if it is a leaf node or not if it is then we can insert that into the res 
    // otherwise we can go to the left and then again check for the right ]
    if(isLeafNode(root)){
        // then insert 
        res.push_back(root->data);
        return;
    }
    if(root->left){
        addLeafNodes(root->left, res);
    }
    if(root->right){
        addLeafNodes(root->right, res);
    }
}
void addRightEle(Node* root, vector<int>& res){
    // here we need to go in reverse order so basically first store the thigns in some temp array 
    // and then push to the res array 
    Node* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeafNode(curr)){
            temp.push_back(curr->data);
        }

        if(curr->right){
            curr = curr->right;
        }

        if(curr->left){
            curr = curr->left;
        }
    }
}

vector<int> boundary(Node* root){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    // push the root into the res
    res.push_back(root->data);

    // call for the left ele 
    addLeftEle(root, res);
    // add leaf nodes
    addLeafNodes(root, res);
    // add right nodes
    addRightEle(root, res);

    // then res can be returned 
    return res;
}

int main(){
    Node* root = new Node(1);
    vector<int> ans = boundary(root);
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i];
    }
    return 0;
}