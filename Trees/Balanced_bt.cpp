#include <bits/stdc++.h>
using namespace std;

bool balanced_bt(Node* root){
    if(root == NULL){
        return true;
    }
    lh = balanced_bt(root->left);
    rh = balanced_bt(root->right);

    if(lh - rh > 1){
        // then it is not balanced 
        return false;
    }
    // if i have reached till here that means that the tree is balanced 
    return true;
}

int main(){
    return 0;
}