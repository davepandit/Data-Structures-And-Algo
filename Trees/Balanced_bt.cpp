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

int solve(Node* root, vector<int>& dummy_ans){
    if(root == NULL){
        return 0;
    }
    int lh = solve(root->left, dummy_ans);
    int rh = solve(root->right, dummy_ans);

    int diff = abs(lh - rh);
    if(diff > 1){
        dummy_ans.push_back(1);
    }

    return 1 + max(lh, rh);
}

bool check_for_balanced(Node* root){
    if(root == NULL){
        return true;
    }
    vector<int> dummy_ans;
    // inside this making a separate a solve function that will be solving the thing 
    solve(root, dummy_ans);

    // check for the ones in the dummy_ans
    // if there is one then we can say that the tree is not balanced 
    auto it = find(dummy_ans.begin(), dummy_ans.end(), 1);

    if(it == dummy_ans.end()){
        return true;
    }else{
        return false;
    }

}

int main(){
    Node* root = new Node(3);
    bool ans = check_for_balanced(root);
    cout << ans;
    return 0;
}