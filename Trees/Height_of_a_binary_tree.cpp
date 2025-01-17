#include <bits/stdc++.h>
using namespace std;

int height_of_a_binary_tree(Node* root){
    it(root == NULL){
        return 0;
    }
    int lh = height_of_a_binary_tree(root->left);
    int rh = height_of_a_binary_tree(root->right);

    return (1 + max(lh, rh));
}

int main(){
    return 0;
}