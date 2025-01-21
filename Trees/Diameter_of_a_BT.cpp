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

int solve(Node* root, int& dia){
    if(root == NULL){
        return 0;
    }

    int lh = solve(root->left, dia);
    int rh = solve(root->right, dia);

    if(dia >= lh + rh){
        dia = lh + rh;
    }

    return 1 + max(lh, rh);
}

int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    // this function will solve the problem 
    int dia = 0;
    int res = solve(root, dia);

    return res;
}

int main(){
    Node* root = new Node(1);
    int ans = diameter(root);
    cout << ans;
    return 0;
}